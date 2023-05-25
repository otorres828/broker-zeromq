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

    std::string mensaje, host,puerto,direccion;
    int conectado=1;
    while (conectado) {
        try {
            std::cout << "Escriba el host: ";
            std::getline(std::cin, host);
            std::cout << "Escriba el puerto: ";
            std::getline(std::cin, puerto);
            direccion="tcp://"+host+":"+puerto;

            // Conectamos el suscriptor al broker
            subscriber.connect(direccion);
            std::cout << "Se conecto correctamente: "<<std::endl;
            conectado=0;
        } catch (const zmq::error_t& ex) {
            // Maneja la excepción de conexión aquí
            std::cout<<"error al enviar suscribirse:"<<direccion<<std::endl;
        }
    }
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