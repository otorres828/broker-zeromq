#include "suscriptor.h"
#include "ui_suscriptor.h"
#include <QStringListModel>
#include <QMessageBox>
#include <zmq.hpp>
#include <iostream>
#include <QLabel>

Suscriptor::Suscriptor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Suscriptor)
    , conectado(false)
    , terminar(true)
    , recibir_thread(nullptr)
{
    ui->setupUi(this);
}

Suscriptor::~Suscriptor(){
    delete ui;
}


void Suscriptor::on_conectar_clicked(){

    // Leer el texto de los QTextEdit
    QString host = ui->host->text();
    QString puerto = ui->puerto->text();

    // Verificar si los campos están vacíos
    if (host.isEmpty() || puerto.isEmpty()) {
        // Mostrar un mensaje de alerta que diga "Llene los campos"
        QMessageBox::warning(this, "Campos vacíos", "Por favor, llene todos los campos.");
        return;
    }

    QString direccion = host + ":" + puerto;

    if (!conectado) {
        // Crear el modelo de lista para mostrar los mensajes recibidos
        QStringListModel* modelo = new QStringListModel(this);
        ui->lista->setModel(modelo);

        // Iniciar el hilo para recibir los mensajes del broker
        recibir_thread = new std::thread([this, modelo,direccion]() {
            zmq::context_t context(1);

            zmq::socket_t subscriber(context, ZMQ_SUB);

            // Conectamos el suscriptor al broker
            subscriber.connect(direccion.toStdString());

            // Nos suscribimos a todos los mensajes
            subscriber.set(zmq::sockopt::subscribe, "");
            while (conectado) {
                zmq::message_t message;
                subscriber.recv(message, zmq::recv_flags::none);

                // Verificamos si el mensaje contiene sólo caracteres imprimibles
                if (es_imprimible(static_cast<char*>(message.data()), message.size())) {
                    // Convertimos el mensaje a una cadena de texto
                    std::string mensaje_str(static_cast<char*>(message.data()), message.size());
                    QString mensaje = QString::fromStdString(mensaje_str);

                    //guardar mensaje en la lista
                    if(message.size()>0){
                        QStringListModel* modelo = static_cast<QStringListModel*>(ui->lista->model());
                        QStringList lista = modelo->stringList();
                        if(mensaje=="ON"){
                            lista.append("Bombillo Encendido");
                            QPixmap pixmap(":/bombillo/bombillo_on.png");
                            ui->bombillo->setPixmap(pixmap);
                        }
                        if(mensaje=="OFF"){
                            QPixmap pixmap(":/bombillo/bombillo_off.png");
                            ui->bombillo->setPixmap(pixmap);
                            lista.append("Bombillo Apagado");
                        }
                        modelo->setStringList(lista);
                    }
                }

            }
        });

        // Cambiar el texto del botón a "APAGAR"
        ui->conectar->setText("APAGAR");
        conectado = true;
    } else {
        // Detener el hilo de recibir mensajes del broker
        recibir_thread->detach();
        delete recibir_thread;

        // Desconectar el suscriptor del broker
        terminar=false;

        // Cerrar el socket y el contexto de ZeroMQ
        subscriber.close();
        context.close();
        ui->bombillo->setPixmap(QPixmap()); // Asignar una QPixmap vacía a ui->bombillo
        // Cambiar el texto del botón a "CONECTAR"
        ui->conectar->setText("CONECTAR");
        conectado = false;

    }

}

bool Suscriptor::es_imprimible(const char* data, size_t size){
    for (size_t i = 0; i < size; i++) {
        if (data[i] < 32 || data[i] > 126) {
            return false;
        }
    }
    return true;
}



