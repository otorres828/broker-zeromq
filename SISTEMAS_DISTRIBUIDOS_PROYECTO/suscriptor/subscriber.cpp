#include <iostream>
#include <zmq.hpp>

bool es_imprimible(const char* data, size_t size) {
    for (size_t i = 0; i < size; i++) {
        if (data[i] < 32 || data[i] > 126) {
            return false;
        }
    }
    return true;
}

int main() {
    zmq::context_t context(1);
    zmq::socket_t subscriber(context, ZMQ_SUB);

    // Conectamos el suscriptor al broker
    subscriber.connect("tcp://localhost:5556");

    // Nos suscribimos a todos los mensajes
    subscriber.set(zmq::sockopt::subscribe, "");

    // Esperamos a recibir un mensaje del broker
    while (true) {
        zmq::message_t message;
        subscriber.recv(message, zmq::recv_flags::none);

        // Verificamos si el mensaje contiene sólo caracteres imprimibles
        if (es_imprimible(static_cast<char*>(message.data()), message.size())) {
            // Convertimos el mensaje a una cadena de texto
            if(message.size()>0){
                std::string mensaje(static_cast<char*>(message.data()), message.size());
                std::cout << "Mensaje recibido: " << mensaje << std::endl;
            }
        }
    }

    return 0;
}