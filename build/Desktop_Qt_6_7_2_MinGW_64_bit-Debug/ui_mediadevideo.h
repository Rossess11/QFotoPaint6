/********************************************************************************
** Form generated from reading UI file 'mediadevideo.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDIADEVIDEO_H
#define UI_MEDIADEVIDEO_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_mediadevideo
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QSpinBox *spinBox;
    QPushButton *pushButton_2;
    QGroupBox *groupBox;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;

    void setupUi(QDialog *mediadevideo)
    {
        if (mediadevideo->objectName().isEmpty())
            mediadevideo->setObjectName("mediadevideo");
        mediadevideo->setWindowModality(Qt::WindowModality::WindowModal);
        mediadevideo->resize(277, 194);
        mediadevideo->setMinimumSize(QSize(277, 194));
        mediadevideo->setMaximumSize(QSize(277, 194));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imagenes/icono.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        mediadevideo->setWindowIcon(icon);
        pushButton = new QPushButton(mediadevideo);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 50, 121, 31));
        label = new QLabel(mediadevideo);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 22, 131, 16));
        spinBox = new QSpinBox(mediadevideo);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(150, 20, 71, 22));
        spinBox->setMaximum(10000);
        pushButton_2 = new QPushButton(mediadevideo);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setEnabled(false);
        pushButton_2->setGeometry(QRect(140, 50, 131, 31));
        groupBox = new QGroupBox(mediadevideo);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 90, 261, 61));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setEnabled(false);
        pushButton_3->setGeometry(QRect(10, 20, 101, 31));
        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setEnabled(false);
        pushButton_4->setGeometry(QRect(140, 20, 111, 31));
        pushButton_5 = new QPushButton(mediadevideo);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(90, 160, 91, 31));

        retranslateUi(mediadevideo);

        pushButton_5->setDefault(true);


        QMetaObject::connectSlotsByName(mediadevideo);
    } // setupUi

    void retranslateUi(QDialog *mediadevideo)
    {
        mediadevideo->setWindowTitle(QCoreApplication::translate("mediadevideo", "V\303\255deo a imagen media...", nullptr));
        pushButton->setText(QCoreApplication::translate("mediadevideo", "Conectar c\303\241mara", nullptr));
        label->setText(QCoreApplication::translate("mediadevideo", "Indice de la c\303\241mara:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("mediadevideo", "Desconectar c\303\241mara", nullptr));
        groupBox->setTitle(QCoreApplication::translate("mediadevideo", "Media", nullptr));
        pushButton_3->setText(QCoreApplication::translate("mediadevideo", "Empezar", nullptr));
        pushButton_4->setText(QCoreApplication::translate("mediadevideo", "Obtener", nullptr));
        pushButton_5->setText(QCoreApplication::translate("mediadevideo", "Salir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mediadevideo: public Ui_mediadevideo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIADEVIDEO_H
