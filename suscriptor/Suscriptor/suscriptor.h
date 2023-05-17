#ifndef SUSCRIPTOR_H
#define SUSCRIPTOR_H
#include <zmq.hpp>
#include <thread>
#include <QMainWindow>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class Suscriptor; }
QT_END_NAMESPACE

class Suscriptor : public QMainWindow
{
    Q_OBJECT

public:
    Suscriptor(QWidget *parent = nullptr);
    bool es_imprimible(const char* data, size_t size);
    ~Suscriptor();

private slots:
    void on_conectar_clicked();
    //void on_mensaje_recibido(const QString& mensaje);

private:
    Ui::Suscriptor *ui;
    bool conectado;
    zmq::context_t context;
    zmq::socket_t subscriber;
    std::thread* recibir_thread;
};

#endif // SUSCRIPTOR_H
