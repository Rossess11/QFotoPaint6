#ifndef AJUSTELINEAL_H
#define AJUSTELINEAL_H

#include <QDialog>

namespace Ui {
class AjusteLineal;
}

class AjusteLineal : public QDialog
{
    Q_OBJECT

public:
    explicit AjusteLineal(int numFoto, QWidget *parent = nullptr);
    ~AjusteLineal();

private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_spinBox_valueChanged(int arg1);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_spinBox_2_valueChanged(int arg1);

    void on_checkBox_stateChanged(int arg1);

    void on_AjusteLineal_accepted();

    void on_AjusteLineal_rejected();

private:
    Ui::AjusteLineal *ui;
    int nfoto;
};

#endif // AJUSTELINEAL_H
