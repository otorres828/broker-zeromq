#include <zmq.hpp>
#include <string>
#include <iostream>

int main() {
    zmq::context_t context(1);
    zmq::socket_t requester(context, ZMQ_REQ);

    // Conectamos el publicador al broker
    requester.connect("tcp://localhost:5555");

    // Enviamos el mensaje al broker
    std::string mensaje = "Hola";
    zmq::message_t request(mensaje.size() + 1); // Agregamos espacio para el carácter nulo
    memcpy(request.data(), mensaje.c_str(), mensaje.size());
    static_cast<char*>(request.data())[mensaje.size()] = '\0'; // Agregamos el carácter nulo
    std::cout<<request;
    requester.send(request);

    return 0;
}