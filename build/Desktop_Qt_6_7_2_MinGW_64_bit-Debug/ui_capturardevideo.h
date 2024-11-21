/********************************************************************************
** Form generated from reading UI file 'capturardevideo.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAPTURARDEVIDEO_H
#define UI_CAPTURARDEVIDEO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_CapturarDeVideo
{
public:
    QDialogButtonBox *buttonBox;
    QSpinBox *spinBox;
    QSlider *horizontalSlider;
    QLabel *label;

    void setupUi(QDialog *CapturarDeVideo)
    {
        if (CapturarDeVideo->objectName().isEmpty())
            CapturarDeVideo->setObjectName("CapturarDeVideo");
        CapturarDeVideo->setWindowModality(Qt::WindowModal);
        CapturarDeVideo->resize(400, 121);
        buttonBox = new QDialogButtonBox(CapturarDeVideo);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(40, 80, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        spinBox = new QSpinBox(CapturarDeVideo);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(300, 20, 81, 22));
        spinBox->setMinimum(0);
        spinBox->setMaximum(256);
        horizontalSlider = new QSlider(CapturarDeVideo);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(20, 40, 271, 21));
        horizontalSlider->setMinimum(0);
        horizontalSlider->setMaximum(256);
        horizontalSlider->setPageStep(16);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);
        horizontalSlider->setTickInterval(32);
        label = new QLabel(CapturarDeVideo);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 271, 16));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(CapturarDeVideo);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, CapturarDeVideo, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, CapturarDeVideo, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(CapturarDeVideo);
    } // setupUi

    void retranslateUi(QDialog *CapturarDeVideo)
    {
        CapturarDeVideo->setWindowTitle(QCoreApplication::translate("CapturarDeVideo", "CapturarDeVideo", nullptr));
        label->setText(QCoreApplication::translate("CapturarDeVideo", "Numero de frames", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CapturarDeVideo: public Ui_CapturarDeVideo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAPTURARDEVIDEO_H
