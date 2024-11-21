/********************************************************************************
** Form generated from reading UI file 'dialognueva.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGNUEVA_H
#define UI_DIALOGNUEVA_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_DialogNueva
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton;

    void setupUi(QDialog *DialogNueva)
    {
        if (DialogNueva->objectName().isEmpty())
            DialogNueva->setObjectName("DialogNueva");
        DialogNueva->setWindowModality(Qt::WindowModality::NonModal);
        DialogNueva->resize(302, 188);
        DialogNueva->setMinimumSize(QSize(302, 188));
        DialogNueva->setMaximumSize(QSize(302, 188));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imagenes/icono.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        DialogNueva->setWindowIcon(icon);
        DialogNueva->setModal(false);
        buttonBox = new QDialogButtonBox(DialogNueva);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 150, 261, 32));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy);
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        groupBox = new QGroupBox(DialogNueva);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 20, 261, 81));
        groupBox->setFlat(false);
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 46, 21));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 50, 46, 21));
        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(80, 20, 101, 22));
        spinBox->setMinimum(1);
        spinBox->setMaximum(10000);
        spinBox->setValue(640);
        spinBox_2 = new QSpinBox(groupBox);
        spinBox_2->setObjectName("spinBox_2");
        spinBox_2->setGeometry(QRect(80, 50, 101, 22));
        spinBox_2->setMinimum(1);
        spinBox_2->setMaximum(10000);
        spinBox_2->setValue(480);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(190, 20, 46, 21));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(190, 50, 46, 21));
        label_5 = new QLabel(DialogNueva);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 118, 111, 21));
        pushButton = new QPushButton(DialogNueva);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(150, 110, 61, 31));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        pushButton->setFlat(false);

        retranslateUi(DialogNueva);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DialogNueva, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DialogNueva, qOverload<>(&QDialog::reject));

        pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(DialogNueva);
    } // setupUi

    void retranslateUi(QDialog *DialogNueva)
    {
        DialogNueva->setWindowTitle(QCoreApplication::translate("DialogNueva", "Nueva imagen...", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DialogNueva", "Tama\303\261o de la imagen", nullptr));
        label->setText(QCoreApplication::translate("DialogNueva", "Anchura:", nullptr));
        label_2->setText(QCoreApplication::translate("DialogNueva", "Altura:", nullptr));
        label_3->setText(QCoreApplication::translate("DialogNueva", "p\303\255xeles", nullptr));
        label_4->setText(QCoreApplication::translate("DialogNueva", "p\303\255xeles", nullptr));
        label_5->setText(QCoreApplication::translate("DialogNueva", "Color del fondo:", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogNueva: public Ui_DialogNueva {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGNUEVA_H
