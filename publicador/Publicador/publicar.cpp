#include "publicar.h"
#include <zmq.hpp>
#include <QString>
#include <iostream>
#include <QDebug>
#include <QMessageBox>

Publicar::Publicar(QString direccion, QString mensaje)
{
    int major, minor, patch;
     zmq_version(&major,&minor,&patch);
     // Crea un contexto ZeroMQ
     zmq::context_t context(1);

     // Crea un socket de tipo PUB que envía mensajes
     zmq::socket_t socket(context, zmq::socket_type::req);

     // Configura el socket para permitir conexiones entrantes
     int hwm = 0;
     socket.setsockopt(ZMQ_SNDHWM, &hwm, sizeof(hwm));
     qDebug() << direccion.toStdString().c_str();
     try {
         // Conéctate al socket
         socket.connect(direccion.toStdString().c_str());

         // Envía el mensaje
         std::string mensaje_codificado = mensaje.toStdString();
         zmq::message_t zmq_message(mensaje_codificado.data(), mensaje_codificado.size());
         socket.send(zmq_message, zmq::send_flags::none);
         // Mostrar una ventana emergente que diga "Mensaje enviado"
         //QMessageBox::information(nullptr, "Mensaje enviado", "El mensaje se ha enviado correctamente.");
     } catch (const zmq::error_t& ex) {
         // Maneja la excepción de conexión aquí
         QMessageBox::critical(nullptr, "Error de conexión", "Ocurrió un error de conexión:\n" + QString(ex.what()));
         qDebug() << "Ocurrió un error de conexión:" << ex.what();
     }

}
