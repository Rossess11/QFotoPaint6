#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

extern QString FiltroImagen;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setStatusBarText(QString cadena);
    int comprobar_primera_libre();
    void show ();
protected:
    void changeEvent(QEvent *e);
    void closeEvent(QCloseEvent *event);

private:
    Ui::MainWindow *ui;

private slots:
    void on_actionImagen_media_triggered();
    void on_actionAcerca_de_triggered();
    void on_actionRotar_imagen_triggered();
    void on_actionMedia_ponderada_triggered();
    void on_actionMedia_triggered();
    void on_actionGausiano_triggered();
    void on_actionBrillo_contraste_triggered();
    void on_actionRotar_91_triggered();
    void on_actionRotar_180_triggered();
    void on_actionRotar_90_triggered();
    void on_actionInvertir_triggered();
    void on_toolButton_6_clicked();
    void on_toolButton_5_clicked();
    void on_toolButton_4_clicked();
    void on_actionSeleccionar_todo_triggered();
    void on_actionColor_del_pincel_triggered();
    void on_actionPreguntar_si_guardar_triggered();
    void on_actionCerrar_triggered();
    void on_actionGuardar_como_triggered();
    void on_actionGuardar_triggered();
    void on_toolButton_clicked();
    void on_horizontalSlider_2_valueChanged(int value);
    void on_horizontalSlider_valueChanged(int value);
    void on_pushButton_clicked();
    void on_toolButton_2_clicked();
    void on_actionSeleccionar_triggered();
    void on_actionLinea_triggered();
    void on_actionPunto_triggered();
    void on_actionAbrir_imagen_triggered();
    void on_actionNueva_imagen_triggered();
    void on_actionSalir_triggered();
    void on_toolButton_3_clicked();
    void on_toolButton_7_clicked();
    void on_actionRectangulo_triggered();
    void on_actionMediana_triggered();
    void on_toolButton_8_clicked();
    void on_actionElipse_triggered();
    void on_actionGrises_triggered();
    void on_actionRojo_triggered();
    void on_actionVerde_triggered();
    void on_actionAzul_triggered();
    void on_toolButton_9_clicked();
    void on_actionArcoiris_triggered();
    void on_actionCapturar_de_video_triggered();
    void on_actionBajorrelieve_triggered();
    void on_actionCopiar_a_nueva_triggered();
    void on_actionCapturar_de_camara_triggered();
    void on_actionVer_ajuste_lineal_del_histograma_triggered();
    void on_actionEscala_de_color_triggered();
    void on_actionPinchar_estirar_triggered();
    void on_actionMatiz_Saturacion_Luminosidad_triggered();
    void on_actionEspectro_triggered();
    void on_actionCopiar_al_portapapeles_triggered();
    void on_actionR_G_triggered();
    void on_actionR_B_triggered();
    void on_actionG_B_triggered();
    void on_actionMostrar_informaci_n_triggered();
    void on_actionPerspectiva_triggered();
    void on_actionSuavizado_temporal_triggered();
    void on_toolButton_10_clicked();
    void on_actionTrazos_triggered();
    void on_toolButton_11_clicked();
    void on_actionSuavizado_triggered();
};

extern MainWindow *w;
extern QApplication *a;

#endif // MAINWINDOW_H
