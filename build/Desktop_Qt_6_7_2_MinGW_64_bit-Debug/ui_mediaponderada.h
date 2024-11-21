/********************************************************************************
** Form generated from reading UI file 'mediaponderada.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDIAPONDERADA_H
#define UI_MEDIAPONDERADA_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_mediaponderada
{
public:
    QDialogButtonBox *buttonBox;
    QListWidget *listWidget;
    QCheckBox *checkBox;
    QLabel *label;
    QLabel *label_2;
    QSlider *horizontalSlider;

    void setupUi(QDialog *mediaponderada)
    {
        if (mediaponderada->objectName().isEmpty())
            mediaponderada->setObjectName("mediaponderada");
        mediaponderada->setWindowModality(Qt::WindowModality::WindowModal);
        mediaponderada->resize(301, 225);
        mediaponderada->setMinimumSize(QSize(301, 225));
        mediaponderada->setMaximumSize(QSize(301, 225));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imagenes/icono.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        mediaponderada->setWindowIcon(icon);
        mediaponderada->setModal(true);
        buttonBox = new QDialogButtonBox(mediaponderada);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(10, 190, 161, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        listWidget = new QListWidget(mediaponderada);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(10, 80, 281, 111));
        listWidget->setAlternatingRowColors(false);
        listWidget->setViewMode(QListView::ViewMode::ListMode);
        checkBox = new QCheckBox(mediaponderada);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(190, 200, 101, 17));
        checkBox->setChecked(true);
        label = new QLabel(mediaponderada);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 60, 111, 16));
        label_2 = new QLabel(mediaponderada);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 10, 281, 16));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(127, 127, 127);\n"
"color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        horizontalSlider = new QSlider(mediaponderada);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(10, 30, 281, 21));
        horizontalSlider->setMaximum(100);
        horizontalSlider->setValue(50);
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TickPosition::TicksBelow);
        horizontalSlider->setTickInterval(10);

        retranslateUi(mediaponderada);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, mediaponderada, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, mediaponderada, qOverload<>(&QDialog::reject));

        listWidget->setCurrentRow(-1);


        QMetaObject::connectSlotsByName(mediaponderada);
    } // setupUi

    void retranslateUi(QDialog *mediaponderada)
    {
        mediaponderada->setWindowTitle(QCoreApplication::translate("mediaponderada", "Media ponderada...", nullptr));
        checkBox->setText(QCoreApplication::translate("mediaponderada", "Previsualizar", nullptr));
        label->setText(QCoreApplication::translate("mediaponderada", "Segunda imagen", nullptr));
        label_2->setText(QCoreApplication::translate("mediaponderada", "Porcentaje", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mediaponderada: public Ui_mediaponderada {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIAPONDERADA_H
