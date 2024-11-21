#include "capturardevideo.h"
#include "ui_capturardevideo.h"

CapturarDeVideo::CapturarDeVideo(String nombre, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CapturarDeVideo)
{
    ui->setupUi(this);

    if(cap.open(nombre)) {

        int nframe = cap.get(CAP_PROP_FRAME_COUNT);
        ui->horizontalSlider->setMaximum(nframe-1);
        ui->spinBox->setMaximum(nframe-1);

        Mat frame;
        cap.read(frame);
        imshow("Frame actual",frame);
    }
    activar_callback_fotos(false);
    if (parent)
        move(parent->x()+DESP_X_HIJO,parent->y()+DESP_Y_HIJO);
}

CapturarDeVideo::~CapturarDeVideo()
{
    delete ui;
    activar_callback_fotos(true);
}

void CapturarDeVideo::on_horizontalSlider_valueChanged(int value)
{
    cap.set(CAP_PROP_POS_FRAMES, value);
    Mat frame;
    if (cap.read(frame)) {

        imshow("Frame actual", frame);
        ui->spinBox->setValue(value);

    }
}


void CapturarDeVideo::on_spinBox_valueChanged(int arg1)
{
    ui->horizontalSlider->setValue(arg1);
}


void CapturarDeVideo::on_CapturarDeVideo_accepted()
{
    cap.set(CAP_PROP_POS_FRAMES, ui->spinBox->value());
    Mat frame;
    if (cap.read(frame)) {

        crear_nueva(primera_libre(), frame);

    }
    destroyWindow("Frame actual");
}


void CapturarDeVideo::on_CapturarDeVideo_rejected()
{
    destroyWindow("Frame actual");
}

bool CapturarDeVideo::isOpened() {

    return cap.isOpened();

}

