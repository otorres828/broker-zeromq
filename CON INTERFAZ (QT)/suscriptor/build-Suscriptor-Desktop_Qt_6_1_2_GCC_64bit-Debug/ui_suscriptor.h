/********************************************************************************
** Form generated from reading UI file 'suscriptor.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUSCRIPTOR_H
#define UI_SUSCRIPTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Suscriptor
{
public:
    QWidget *centralwidget;
    QListView *lista;
    QLabel *label;
    QPushButton *conectar;
    QLineEdit *puerto;
    QLabel *label_2;
    QLineEdit *host;
    QLabel *label_3;
    QLabel *bombillo;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Suscriptor)
    {
        if (Suscriptor->objectName().isEmpty())
            Suscriptor->setObjectName(QString::fromUtf8("Suscriptor"));
        Suscriptor->resize(423, 347);
        centralwidget = new QWidget(Suscriptor);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lista = new QListView(centralwidget);
        lista->setObjectName(QString::fromUtf8("lista"));
        lista->setGeometry(QRect(10, 110, 256, 192));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 80, 91, 17));
        conectar = new QPushButton(centralwidget);
        conectar->setObjectName(QString::fromUtf8("conectar"));
        conectar->setGeometry(QRect(150, 80, 111, 25));
        puerto = new QLineEdit(centralwidget);
        puerto->setObjectName(QString::fromUtf8("puerto"));
        puerto->setGeometry(QRect(100, 40, 161, 25));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 10, 61, 25));
        host = new QLineEdit(centralwidget);
        host->setObjectName(QString::fromUtf8("host"));
        host->setGeometry(QRect(100, 10, 161, 25));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 40, 61, 25));
        bombillo = new QLabel(centralwidget);
        bombillo->setObjectName(QString::fromUtf8("bombillo"));
        bombillo->setGeometry(QRect(280, 10, 261, 281));
        Suscriptor->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Suscriptor);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 423, 22));
        Suscriptor->setMenuBar(menubar);
        statusbar = new QStatusBar(Suscriptor);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Suscriptor->setStatusBar(statusbar);

        retranslateUi(Suscriptor);

        QMetaObject::connectSlotsByName(Suscriptor);
    } // setupUi

    void retranslateUi(QMainWindow *Suscriptor)
    {
        Suscriptor->setWindowTitle(QCoreApplication::translate("Suscriptor", "Suscriptor", nullptr));
        label->setText(QCoreApplication::translate("Suscriptor", "MENSAJES", nullptr));
        conectar->setText(QCoreApplication::translate("Suscriptor", "CONECTAR", nullptr));
        label_2->setText(QCoreApplication::translate("Suscriptor", "HOST", nullptr));
        label_3->setText(QCoreApplication::translate("Suscriptor", "PUERTO", nullptr));
        bombillo->setText(QCoreApplication::translate("Suscriptor", "BOMBILLO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Suscriptor: public Ui_Suscriptor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUSCRIPTOR_H
