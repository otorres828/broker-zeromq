#ifndef PUBLICADOR_H
#define PUBLICADOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Publicador; }
QT_END_NAMESPACE

class Publicador : public QMainWindow
{
    Q_OBJECT

public:
    Publicador(QWidget *parent = nullptr);
    ~Publicador();

private slots:
    void on_on_clicked();

    void on_off_clicked();

    void on_on_off_clicked();

private:
    Ui::Publicador *ui;
};
#endif // PUBLICADOR_H
