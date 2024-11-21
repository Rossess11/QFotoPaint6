#ifndef MATSATLUM_H
#define MATSATLUM_H

#include <QDialog>

namespace Ui {
class matsatlum;
}

class matsatlum : public QDialog
{
    Q_OBJECT

public:
    explicit matsatlum(int numfoto, QWidget *parent = nullptr);
    ~matsatlum();

private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_dial_valueChanged(int value);

    void on_matsatlum_accepted();

    void on_matsatlum_rejected();

private:
    Ui::matsatlum *ui;
    int nfoto;
};

#endif // MATSATLUM_H
