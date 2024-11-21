#ifndef CAPTURARDEVIDEO_H
#define CAPTURARDEVIDEO_H

#include <QDialog>
#include "imagenes.h"

namespace Ui {
class CapturarDeVideo;
}

class CapturarDeVideo : public QDialog
{
    Q_OBJECT

public:
    explicit CapturarDeVideo(String nombre, QWidget *parent = nullptr);
    ~CapturarDeVideo();
    bool isOpened();
private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_spinBox_valueChanged(int arg1);

    void on_CapturarDeVideo_accepted();

    void on_CapturarDeVideo_rejected();

private:
    Ui::CapturarDeVideo *ui;
    VideoCapture cap;
};

#endif // CAPTURARDEVIDEO_H
