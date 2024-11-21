/********************************************************************************
** Form generated from reading UI file 'pincharestirar.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PINCHARESTIRAR_H
#define UI_PINCHARESTIRAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_PincharEstirar
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QSlider *horizontalSlider_2;

    void setupUi(QDialog *PincharEstirar)
    {
        if (PincharEstirar->objectName().isEmpty())
            PincharEstirar->setObjectName("PincharEstirar");
        PincharEstirar->setWindowModality(Qt::WindowModality::WindowModal);
        PincharEstirar->resize(400, 181);
        buttonBox = new QDialogButtonBox(PincharEstirar);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(100, 130, 201, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label = new QLabel(PincharEstirar);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 10, 351, 16));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        horizontalSlider = new QSlider(PincharEstirar);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(30, 30, 351, 21));
        horizontalSlider->setMinimum(0);
        horizontalSlider->setMaximum(400);
        horizontalSlider->setPageStep(16);
        horizontalSlider->setValue(200);
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TickPosition::TicksBelow);
        horizontalSlider->setTickInterval(50);
        label_2 = new QLabel(PincharEstirar);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 70, 351, 16));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        horizontalSlider_2 = new QSlider(PincharEstirar);
        horizontalSlider_2->setObjectName("horizontalSlider_2");
        horizontalSlider_2->setGeometry(QRect(30, 90, 351, 21));
        horizontalSlider_2->setMinimum(-60);
        horizontalSlider_2->setMaximum(60);
        horizontalSlider_2->setPageStep(16);
        horizontalSlider_2->setOrientation(Qt::Orientation::Horizontal);
        horizontalSlider_2->setTickPosition(QSlider::TickPosition::TicksBelow);
        horizontalSlider_2->setTickInterval(15);

        retranslateUi(PincharEstirar);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, PincharEstirar, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, PincharEstirar, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(PincharEstirar);
    } // setupUi

    void retranslateUi(QDialog *PincharEstirar)
    {
        PincharEstirar->setWindowTitle(QCoreApplication::translate("PincharEstirar", "Pinchar/Estirar", nullptr));
        label->setText(QCoreApplication::translate("PincharEstirar", "Radio del efecto", nullptr));
        label_2->setText(QCoreApplication::translate("PincharEstirar", "Grado del efecto", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PincharEstirar: public Ui_PincharEstirar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PINCHARESTIRAR_H
