/********************************************************************************
** Form generated from reading UI file 'publicador.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PUBLICADOR_H
#define UI_PUBLICADOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Publicador
{
public:
    QWidget *centralwidget;
    QPushButton *conectar;
    QLineEdit *host;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *puerto;
    QLineEdit *mensaje;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Publicador)
    {
        if (Publicador->objectName().isEmpty())
            Publicador->setObjectName(QString::fromUtf8("Publicador"));
        Publicador->resize(277, 180);
        centralwidget = new QWidget(Publicador);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        conectar = new QPushButton(centralwidget);
        conectar->setObjectName(QString::fromUtf8("conectar"));
        conectar->setGeometry(QRect(50, 110, 139, 25));
        host = new QLineEdit(centralwidget);
        host->setObjectName(QString::fromUtf8("host"));
        host->setGeometry(QRect(90, 10, 141, 25));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 61, 25));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 61, 25));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 70, 81, 25));
        puerto = new QLineEdit(centralwidget);
        puerto->setObjectName(QString::fromUtf8("puerto"));
        puerto->setGeometry(QRect(90, 40, 141, 25));
        mensaje = new QLineEdit(centralwidget);
        mensaje->setObjectName(QString::fromUtf8("mensaje"));
        mensaje->setGeometry(QRect(90, 70, 141, 25));
        Publicador->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Publicador);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 277, 22));
        Publicador->setMenuBar(menubar);
        statusbar = new QStatusBar(Publicador);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Publicador->setStatusBar(statusbar);

        retranslateUi(Publicador);

        QMetaObject::connectSlotsByName(Publicador);
    } // setupUi

    void retranslateUi(QMainWindow *Publicador)
    {
        Publicador->setWindowTitle(QCoreApplication::translate("Publicador", "Publicador", nullptr));
        conectar->setText(QCoreApplication::translate("Publicador", "Conectar y Publicar", nullptr));
        label->setText(QCoreApplication::translate("Publicador", "HOST", nullptr));
        label_2->setText(QCoreApplication::translate("Publicador", "PUERTO", nullptr));
        label_3->setText(QCoreApplication::translate("Publicador", "MENSAJE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Publicador: public Ui_Publicador {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUBLICADOR_H
