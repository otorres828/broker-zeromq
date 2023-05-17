#include "publicador.h"
#include "ui_publicador.h"
#include <QStringListModel>
#include <QMessageBox>
#include <QString>
#include <iostream>
#include "publicar.h"

Publicador::Publicador(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Publicador)
{
    ui->setupUi(this);
}

Publicador::~Publicador()
{
    delete ui;
}


void Publicador::on_on_clicked()
{
    // Leer el texto de los QTextEdit
    QString host = ui->host->text();
    QString puerto = ui->puerto->text();
    QString mensaje = "ON";

    // Verificar si los campos están vacíos
    if (host.isEmpty() || puerto.isEmpty() || mensaje.isEmpty()) {
        // Mostrar un mensaje de alerta que diga "Llene los campos"
        QMessageBox::warning(this, "Campos vacíos", "Por favor, llene todos los campos.");
        return;
    }
    // Conectamos el publicador al broker en la dirección especificada
    QString direccion = host + ":" + puerto;
    //INSTANCIAMOS PUBLICAR
    Publicar pub(direccion, mensaje);

}


void Publicador::on_off_clicked()
{
    // Leer el texto de los QTextEdit
    QString host = ui->host->text();
    QString puerto = ui->puerto->text();
    QString mensaje = "OFF";

    // Verificar si los campos están vacíos
    if (host.isEmpty() || puerto.isEmpty() || mensaje.isEmpty()) {
        // Mostrar un mensaje de alerta que diga "Llene los campos"
        QMessageBox::warning(this, "Campos vacíos", "Por favor, llene todos los campos.");
        return;
    }
    // Conectamos el publicador al broker en la dirección especificada
    QString direccion = host + ":" + puerto;
    //INSTANCIAMOS PUBLICAR
    Publicar pub(direccion, mensaje);
}


void Publicador::on_on_off_clicked()
{
    // Leer el texto de los QTextEdit
    QString host = ui->host->text();
    QString puerto = ui->puerto->text();
    QString mensaje = ui->mensaje->text();

    // Verificar si los campos están vacíos
    if (host.isEmpty() || puerto.isEmpty() || mensaje.isEmpty()) {
        // Mostrar un mensaje de alerta que diga "Llene los campos"
        QMessageBox::warning(this, "Campos vacíos", "Por favor, llene todos los campos.");
        return;
    }
    // Conectamos el publicador al broker en la dirección especificada
    QString direccion = host + ":" + puerto;
    //INSTANCIAMOS PUBLICAR
    Publicar pub(direccion, mensaje);
}

