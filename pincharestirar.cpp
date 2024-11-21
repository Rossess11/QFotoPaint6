#include "pincharestirar.h"
#include "ui_pincharestirar.h"
#include "imagenes.h"

int pe_nfoto;
int pe_cx, pe_cy;
int pe_radio;
double pe_grado;

void pe_callback(int evento, int x, int y, int flags, void *pt) {
    if(flags == EVENT_FLAG_LBUTTON) {
        pe_cx = x;
        pe_cy = y;
        ver_pinchar_estirar(pe_nfoto, pe_cx, pe_cy, pe_radio, pe_grado);
    }
};

PincharEstirar::PincharEstirar(int numFoto, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PincharEstirar)
{
    ui->setupUi(this);
    pe_nfoto = numFoto;
    int w = foto[numFoto].img.cols;
    int h = foto[numFoto].img.rows;
    pe_cx = w/2;
    pe_cy = h/2;
    pe_radio = 200;
    ui->horizontalSlider->setMaximum(w+h);
    pe_grado = ui->horizontalSlider_2->value()*pe_radio*pe_radio/1000.0;
    ver_pinchar_estirar(pe_nfoto, pe_cx, pe_cy, pe_radio, pe_grado);
    setMouseCallback("Pinchar/Estirar", pe_callback);
    if (parent)
        move(parent->x()+DESP_X_HIJO, parent->y()+DESP_Y_HIJO);
    activar_callback_fotos(false);
}

PincharEstirar::~PincharEstirar()
{
     activar_callback_fotos(true);
    delete ui;
}

void PincharEstirar::on_horizontalSlider_valueChanged(int value)
{
    pe_radio = value;
    pe_grado = ui->horizontalSlider_2->value()*pe_radio*pe_radio/1000.0;
    ver_pinchar_estirar(pe_nfoto, pe_cx, pe_cy, pe_radio, pe_grado);
}


void PincharEstirar::on_horizontalSlider_2_valueChanged(int value)
{
    pe_grado = value*pe_radio*pe_radio/1000.0;
    ver_pinchar_estirar(pe_nfoto, pe_cx, pe_cy, pe_radio, pe_grado);
}


void PincharEstirar::on_PincharEstirar_accepted()
{
    ver_pinchar_estirar(pe_nfoto, pe_cx, pe_cy, pe_radio, pe_grado, true);
    destroyWindow("Pinchar/Estirar");
}


void PincharEstirar::on_PincharEstirar_rejected()
{
    destroyWindow("Pinchar/Estirar");
}

