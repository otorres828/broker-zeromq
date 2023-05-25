#include <iostream>
#include <zmq.hpp>
#include <zmq.h>

int main() {
    zmq::context_t context(1);
    zmq::socket_t frontend(context, ZMQ_ROUTER);
    zmq::socket_t backend(context, ZMQ_PUB);

    std::string host,puerto_publicador,direccion_publicador,puerto_suscriptor,direccion_suscriptor;
    std::cout << "Escriba el host: ";
    std::getline(std::cin, host);
    std::cout << "Escriba el puerto para el publicador: ";
    std::getline(std::cin, puerto_publicador);
    std::cout << "Escriba el puerto para el suscriptor: ";
    std::getline(std::cin, puerto_suscriptor);

    direccion_publicador="tcp://"+host+":"+puerto_publicador;
    direccion_suscriptor="tcp://"+host+":"+puerto_suscriptor;

    // Bind the frontend socket to a TCP port
    frontend.bind(direccion_publicador);
    std::cout << "Broker ZeroMQ iniciado en "<< direccion_publicador<< std::endl;

    // Bind the backend socket to a TCP port
    backend.bind(direccion_suscriptor); //bin es para conectarse a una direccion y un puerto

    // Proxy messages from frontend to backend
    zmq::proxy(static_cast<void*>(frontend), static_cast<void*>(backend), nullptr);

    return 0;
}

//secuencia de llamadas para una comunicacion no orientada a conexion
//no maneja conxion