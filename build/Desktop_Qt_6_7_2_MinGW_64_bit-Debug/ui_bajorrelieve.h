/********************************************************************************
** Form generated from reading UI file 'bajorrelieve.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BAJORRELIEVE_H
#define UI_BAJORRELIEVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_BajoRrelieve
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QDial *dial;
    QLabel *label_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QLabel *label_4;
    QSpinBox *spinBox;

    void setupUi(QDialog *BajoRrelieve)
    {
        if (BajoRrelieve->objectName().isEmpty())
            BajoRrelieve->setObjectName("BajoRrelieve");
        BajoRrelieve->setWindowModality(Qt::WindowModal);
        BajoRrelieve->resize(612, 300);
        buttonBox = new QDialogButtonBox(BajoRrelieve);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(20, 250, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(BajoRrelieve);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 271, 16));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);
        horizontalSlider = new QSlider(BajoRrelieve);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(10, 30, 271, 21));
        horizontalSlider->setMinimum(0);
        horizontalSlider->setMaximum(300);
        horizontalSlider->setSingleStep(1);
        horizontalSlider->setPageStep(16);
        horizontalSlider->setValue(100);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);
        horizontalSlider->setTickInterval(25);
        label_2 = new QLabel(BajoRrelieve);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 60, 271, 16));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignCenter);
        dial = new QDial(BajoRrelieve);
        dial->setObjectName("dial");
        dial->setGeometry(QRect(60, 120, 161, 111));
        dial->setMaximum(360);
        dial->setWrapping(true);
        dial->setNotchTarget(3.000000000000000);
        dial->setNotchesVisible(true);
        label_3 = new QLabel(BajoRrelieve);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(290, 10, 271, 16));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label_3->setAlignment(Qt::AlignCenter);
        radioButton = new QRadioButton(BajoRrelieve);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(300, 40, 89, 20));
        radioButton_2 = new QRadioButton(BajoRrelieve);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(300, 60, 89, 20));
        radioButton_3 = new QRadioButton(BajoRrelieve);
        radioButton_3->setObjectName("radioButton_3");
        radioButton_3->setGeometry(QRect(300, 80, 89, 20));
        radioButton_4 = new QRadioButton(BajoRrelieve);
        radioButton_4->setObjectName("radioButton_4");
        radioButton_4->setGeometry(QRect(300, 100, 89, 20));
        radioButton_4->setChecked(true);
        label_4 = new QLabel(BajoRrelieve);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(290, 140, 271, 16));
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label_4->setAlignment(Qt::AlignCenter);
        spinBox = new QSpinBox(BajoRrelieve);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(410, 170, 42, 22));
        spinBox->setMinimum(3);
        spinBox->setMaximum(31);
        spinBox->setSingleStep(2);

        retranslateUi(BajoRrelieve);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, BajoRrelieve, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, BajoRrelieve, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(BajoRrelieve);
    } // setupUi

    void retranslateUi(QDialog *BajoRrelieve)
    {
        BajoRrelieve->setWindowTitle(QCoreApplication::translate("BajoRrelieve", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("BajoRrelieve", "Grado del efecto", nullptr));
        label_2->setText(QCoreApplication::translate("BajoRrelieve", "Angulo del efecto", nullptr));
        label_3->setText(QCoreApplication::translate("BajoRrelieve", "Textura", nullptr));
        radioButton->setText(QCoreApplication::translate("BajoRrelieve", "Arena", nullptr));
        radioButton_2->setText(QCoreApplication::translate("BajoRrelieve", "Cielo", nullptr));
        radioButton_3->setText(QCoreApplication::translate("BajoRrelieve", "Gris", nullptr));
        radioButton_4->setText(QCoreApplication::translate("BajoRrelieve", "Madera", nullptr));
        label_4->setText(QCoreApplication::translate("BajoRrelieve", "Tama\303\261o de sobel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BajoRrelieve: public Ui_BajoRrelieve {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BAJORRELIEVE_H
