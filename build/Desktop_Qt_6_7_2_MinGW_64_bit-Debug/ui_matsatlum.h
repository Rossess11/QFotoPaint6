/********************************************************************************
** Form generated from reading UI file 'matsatlum.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATSATLUM_H
#define UI_MATSATLUM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_matsatlum
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_3;
    QSlider *horizontalSlider_2;
    QLabel *label;
    QLabel *label_2;
    QSlider *horizontalSlider;
    QDial *dial;

    void setupUi(QDialog *matsatlum)
    {
        if (matsatlum->objectName().isEmpty())
            matsatlum->setObjectName("matsatlum");
        matsatlum->setWindowModality(Qt::WindowModality::WindowModal);
        matsatlum->resize(400, 350);
        buttonBox = new QDialogButtonBox(matsatlum);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(80, 300, 201, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label_3 = new QLabel(matsatlum);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 130, 271, 16));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        horizontalSlider_2 = new QSlider(matsatlum);
        horizontalSlider_2->setObjectName("horizontalSlider_2");
        horizontalSlider_2->setGeometry(QRect(50, 100, 271, 21));
        horizontalSlider_2->setMinimum(0);
        horizontalSlider_2->setMaximum(400);
        horizontalSlider_2->setSingleStep(1);
        horizontalSlider_2->setValue(100);
        horizontalSlider_2->setOrientation(Qt::Orientation::Horizontal);
        horizontalSlider_2->setTickPosition(QSlider::TickPosition::TicksBelow);
        horizontalSlider_2->setTickInterval(25);
        label = new QLabel(matsatlum);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 30, 271, 16));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new QLabel(matsatlum);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 80, 271, 16));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        horizontalSlider = new QSlider(matsatlum);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(50, 50, 271, 21));
        horizontalSlider->setMinimum(0);
        horizontalSlider->setMaximum(400);
        horizontalSlider->setPageStep(16);
        horizontalSlider->setValue(100);
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TickPosition::TicksBelow);
        horizontalSlider->setTickInterval(25);
        dial = new QDial(matsatlum);
        dial->setObjectName("dial");
        dial->setGeometry(QRect(120, 160, 131, 111));
        dial->setMaximum(255);
        dial->setWrapping(true);
        dial->setNotchTarget(4.000000000000000);
        dial->setNotchesVisible(true);

        retranslateUi(matsatlum);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, matsatlum, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, matsatlum, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(matsatlum);
    } // setupUi

    void retranslateUi(QDialog *matsatlum)
    {
        matsatlum->setWindowTitle(QCoreApplication::translate("matsatlum", "Matiz Luminosidad Saturacion", nullptr));
        label_3->setText(QCoreApplication::translate("matsatlum", "Matiz", nullptr));
        label->setText(QCoreApplication::translate("matsatlum", "Saturacion", nullptr));
        label_2->setText(QCoreApplication::translate("matsatlum", "Luminosidad", nullptr));
    } // retranslateUi

};

namespace Ui {
    class matsatlum: public Ui_matsatlum {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATSATLUM_H
