#include "matsatlum.h"
#include "ui_matsatlum.h"
#include "imagenes.h"

matsatlum::matsatlum(int numfoto, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::matsatlum)
{
    ui->setupUi(this);
    nfoto = numfoto;
    activar_callback_fotos(false);
    if (parent)
        move(parent->x()+DESP_X_HIJO, parent->y()+DESP_Y_HIJO);
}

matsatlum::~matsatlum()
{
    delete ui;
    activar_callback_fotos(false);
}

void matsatlum::on_horizontalSlider_valueChanged(int value)
{
    ver_matiz_sat_lum(nfoto, ui->dial->value(),
                             ui->horizontalSlider->value()/100.0,
                      ui->horizontalSlider_2->value()/100.0);
}


void matsatlum::on_horizontalSlider_2_valueChanged(int value)
{
    ver_matiz_sat_lum(nfoto, ui->dial->value(),
                      ui->horizontalSlider->value()/100.0,
                      ui->horizontalSlider_2->value()/100.0);
}


void matsatlum::on_dial_valueChanged(int value)
{
    ver_matiz_sat_lum(nfoto, ui->dial->value(),
                      ui->horizontalSlider->value()/100.0,
                      ui->horizontalSlider_2->value()/100.0);
}




void matsatlum::on_matsatlum_accepted()
{
    ver_matiz_sat_lum(nfoto, ui->dial->value(),
                      ui->horizontalSlider->value()/100.0,
                      ui->horizontalSlider_2->value()/100.0, true);
}




void matsatlum::on_matsatlum_rejected()
{
    mostrar(nfoto);
}

