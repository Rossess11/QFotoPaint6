#ifndef BAJORRELIEVE_H
#define BAJORRELIEVE_H

#include <QDialog>

namespace Ui {
class BajoRrelieve;
}

class BajoRrelieve : public QDialog
{
    Q_OBJECT

public:
    explicit BajoRrelieve(int numfoto, int numres, QWidget *parent = nullptr);
    ~BajoRrelieve();

private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_dial_valueChanged(int value);

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_BajoRrelieve_accepted();

    void on_BajoRrelieve_rejected();

private:
    Ui::BajoRrelieve *ui;
    int nfoto;
    int nres;
    int ntextura;
};

#endif // BAJORRELIEVE_H
