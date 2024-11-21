#include "bajorrelieve.h"
#include "ui_bajorrelieve.h"
#include "imagenes.h"

BajoRrelieve::BajoRrelieve(int numfoto, int numres, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::BajoRrelieve)
{
    ui->setupUi(this);
    nfoto = numfoto;
    nres = numres;
    ntextura = 3;
    ver_bajorrelieve(nfoto, nres, ui->horizontalSlider->value()/100, ui->dial->value(), ui->spinBox->value(), ntextura);
}

BajoRrelieve::~BajoRrelieve()
{
    delete ui;
}

void BajoRrelieve::on_horizontalSlider_valueChanged(int value)
{
     ver_bajorrelieve(nfoto, nres, ui->horizontalSlider->value()/100, ui->dial->value(), ui->spinBox->value(), ntextura);
}


void BajoRrelieve::on_dial_valueChanged(int value)
{
     ver_bajorrelieve(nfoto, nres, ui->horizontalSlider->value()/100, ui->dial->value(), ui->spinBox->value(), ntextura);
}


void BajoRrelieve::on_radioButton_clicked()
{
    ntextura=0;

     ver_bajorrelieve(nfoto, nres, ui->horizontalSlider->value()/100, ui->dial->value(), ui->spinBox->value(), ntextura);
}


void BajoRrelieve::on_radioButton_2_clicked()
{
    ntextura = 1;

     ver_bajorrelieve(nfoto, nres, ui->horizontalSlider->value()/100, ui->dial->value(), ui->spinBox->value(), ntextura);
}

void BajoRrelieve::on_radioButton_3_clicked()
{
    ntextura = 2;

    ver_bajorrelieve(nfoto, nres, ui->horizontalSlider->value()/100, ui->dial->value(), ui->spinBox->value(), ntextura);
}

void BajoRrelieve::on_BajoRrelieve_accepted()
{

    ver_bajorrelieve(nfoto, nres, ui->horizontalSlider->value()/100, ui->dial->value(), ui->spinBox->value(), ntextura, true);
    destroyWindow("Bajorrelieve");

}

void BajoRrelieve::on_BajoRrelieve_rejected()
{

    ver_bajorrelieve(nfoto, nres, ui->horizontalSlider->value()/100, ui->dial->value(), ui->spinBox->value(), ntextura, true);
    destroyWindow("Bajorrelieve");

}

