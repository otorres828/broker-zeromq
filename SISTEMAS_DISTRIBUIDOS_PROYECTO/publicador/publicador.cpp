#include <iostream>
#include <string>
#include <zmq.hpp>
#include <zmq.h>

int main() {
 int major, minor, patch;
     zmq_version(&major,&minor,&patch);
     // Crea un contexto ZeroMQ
     zmq::context_t context(1);

     // Crea un socket de tipo PUB que envía mensajes
     zmq::socket_t socket(context, zmq::socket_type::req);

     // Configura el socket para permitir conexiones entrantes
     /*establece el límite máximo de mensajes en cero, lo que significa que el socket no puede 
     acumular ningún mensaje en su búfer antes de enviar una señal de congestión al remitente.*/
     int hwm = 0; 
    socket.setsockopt(ZMQ_SNDHWM, &hwm, sizeof(hwm));

    std::string mensaje, host,puerto,direccion;
     while (true) {
        try {
            std::cout << "Escriba el host: ";
            std::getline(std::cin, host);
            std::cout << "Escriba el puerto: ";
            std::getline(std::cin, puerto);
            std::cout << "Escriba el mensaje: ";
            std::getline(std::cin, mensaje);
            direccion="tcp://"+host+":"+puerto;
            // Conéctate al socket
            socket.connect(direccion);

            // Envía el mensaje
            zmq::message_t zmq_message(mensaje.data(), mensaje.size());
            socket.send(zmq_message, zmq::send_flags::none);
            std::cout<<"Mensaje Enviado"<<std::endl;
        } catch (const zmq::error_t& ex) {
            // Maneja la excepción de conexión aquí
            std::cout<<"error al enviar mensaje en la direccion:"<<direccion<<std::endl;
        }
    }
    return 0;
}