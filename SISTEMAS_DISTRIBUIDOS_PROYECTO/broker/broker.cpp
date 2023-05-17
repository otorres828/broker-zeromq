#include <iostream>
#include <zmq.hpp>

int main() {
    zmq::context_t context(1);
    zmq::socket_t frontend(context, ZMQ_ROUTER);
    zmq::socket_t backend(context, ZMQ_PUB);

    // Bind the frontend socket to a TCP port
    frontend.bind("tcp://*:5555");
    std::cout << "Broker ZeroMQ iniciado en 'tcp://*:5555'" << std::endl;

    // Bind the backend socket to a TCP port
    backend.bind("tcp://*:5556");

    // Proxy messages from frontend to backend
    zmq::proxy(static_cast<void*>(frontend), static_cast<void*>(backend), nullptr);

    return 0;
}