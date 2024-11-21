/********************************************************************************
** Form generated from reading UI file 'suavizados.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUAVIZADOS_H
#define UI_SUAVIZADOS_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_suavizados
{
public:
    QDialogButtonBox *buttonBox;
    QCheckBox *checkBox;
    QSlider *horizontalSlider_2;
    QLabel *label;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox;
    QSlider *horizontalSlider;
    QLabel *label_2;

    void setupUi(QDialog *suavizados)
    {
        if (suavizados->objectName().isEmpty())
            suavizados->setObjectName("suavizados");
        suavizados->setWindowModality(Qt::WindowModality::WindowModal);
        suavizados->resize(380, 150);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(suavizados->sizePolicy().hasHeightForWidth());
        suavizados->setSizePolicy(sizePolicy);
        suavizados->setMinimumSize(QSize(380, 150));
        suavizados->setMaximumSize(QSize(380, 150));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imagenes/icono.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        suavizados->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(suavizados);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(10, 110, 161, 31));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        checkBox = new QCheckBox(suavizados);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(190, 118, 101, 17));
        checkBox->setChecked(true);
        horizontalSlider_2 = new QSlider(suavizados);
        horizontalSlider_2->setObjectName("horizontalSlider_2");
        horizontalSlider_2->setGeometry(QRect(10, 80, 271, 21));
        horizontalSlider_2->setMinimum(1);
        horizontalSlider_2->setMaximum(400);
        horizontalSlider_2->setOrientation(Qt::Orientation::Horizontal);
        horizontalSlider_2->setTickPosition(QSlider::TickPosition::TicksBelow);
        horizontalSlider_2->setTickInterval(20);
        label = new QLabel(suavizados);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 271, 16));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        spinBox_2 = new QSpinBox(suavizados);
        spinBox_2->setObjectName("spinBox_2");
        spinBox_2->setGeometry(QRect(290, 60, 81, 22));
        spinBox_2->setMinimum(1);
        spinBox_2->setMaximum(400);
        spinBox = new QSpinBox(suavizados);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(290, 10, 81, 22));
        spinBox->setMinimum(1);
        spinBox->setMaximum(400);
        horizontalSlider = new QSlider(suavizados);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(10, 30, 271, 21));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(400);
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TickPosition::TicksBelow);
        horizontalSlider->setTickInterval(20);
        label_2 = new QLabel(suavizados);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 60, 271, 16));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(128, 128, 128);\n"
"color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(suavizados);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, suavizados, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, suavizados, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(suavizados);
    } // setupUi

    void retranslateUi(QDialog *suavizados)
    {
        suavizados->setWindowTitle(QCoreApplication::translate("suavizados", "Suavizado...", nullptr));
        checkBox->setText(QCoreApplication::translate("suavizados", "Previsualizar", nullptr));
        label->setText(QCoreApplication::translate("suavizados", "Suavizado en X", nullptr));
        label_2->setText(QCoreApplication::translate("suavizados", "Suavizado en Y", nullptr));
    } // retranslateUi

};

namespace Ui {
    class suavizados: public Ui_suavizados {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUAVIZADOS_H
