/********************************************************************************
** Form generated from reading UI file 'acercade.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACERCADE_H
#define UI_ACERCADE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_acercade
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QCommandLinkButton *commandLinkButton;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QDialog *acercade)
    {
        if (acercade->objectName().isEmpty())
            acercade->setObjectName("acercade");
        acercade->resize(450, 200);
        acercade->setMinimumSize(QSize(450, 200));
        acercade->setMaximumSize(QSize(450, 200));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imagenes/icono.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        acercade->setWindowIcon(icon);
        label = new QLabel(acercade);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 10, 221, 41));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        label->setFont(font);
        label_2 = new QLabel(acercade);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(130, 50, 171, 31));
        QFont font1;
        font1.setPointSize(12);
        label_2->setFont(font1);
        label_3 = new QLabel(acercade);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 110, 431, 31));
        label_4 = new QLabel(acercade);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(170, 160, 141, 31));
        commandLinkButton = new QCommandLinkButton(acercade);
        commandLinkButton->setObjectName("commandLinkButton");
        commandLinkButton->setGeometry(QRect(20, 156, 101, 41));
        commandLinkButton->setAutoDefault(true);
        commandLinkButton->setDefault(false);
        label_5 = new QLabel(acercade);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 10, 100, 100));
        label_5->setStyleSheet(QString::fromUtf8(""));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/logo.png")));
        label_5->setScaledContents(true);
        label_6 = new QLabel(acercade);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(50, 130, 401, 31));

        retranslateUi(acercade);

        QMetaObject::connectSlotsByName(acercade);
    } // setupUi

    void retranslateUi(QDialog *acercade)
    {
        acercade->setWindowTitle(QCoreApplication::translate("acercade", "Acerca de QFotoPaint...", nullptr));
        label->setText(QCoreApplication::translate("acercade", "QFotoPaint", nullptr));
        label_2->setText(QCoreApplication::translate("acercade", "Versi\303\263n 6.0", nullptr));
        label_3->setText(QCoreApplication::translate("acercade", "(2024) by GinesGM, DIS, Facultad de Inform\303\241tica, Universidad de Murcia", nullptr));
        label_4->setText(QCoreApplication::translate("acercade", "Versi\303\263n extensible", nullptr));
        commandLinkButton->setText(QCoreApplication::translate("acercade", "Salir", nullptr));
        label_5->setText(QString());
        label_6->setText(QCoreApplication::translate("acercade", "Logotipo by Antonio Mart\303\255nez Mar\303\255n y Adri\303\241n Pardo Egea", nullptr));
    } // retranslateUi

};

namespace Ui {
    class acercade: public Ui_acercade {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACERCADE_H
