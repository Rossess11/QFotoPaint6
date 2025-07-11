#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QColorDialog>
#include <QMessageBox>
#include "capturardevideo.h"

#include <opencv2/opencv.hpp>
using namespace cv;

#include "acercade.h"
#include "brillocontraste.h"
#include "dialognueva.h"
#include "imagenes.h"
#include "mediadevideo.h"
#include "mediaponderada.h"
#include "rotaravideo.h"
#include "suavizados.h"
#include "video.h"
#include "ajustelineal.h"
#include "capturardevideo.h"
#include "bajorrelieve.h"
#include "pincharestirar.h"
#include "matsatlum.h"
#include "perspectiva.h"


QString FiltroImagen = "Todos los formatos (*.jpg *.jpeg *.jpe .jp2 *.tif *.tiff *.png *.gif *.bmp *.dib *.webp *.ppm);;Archivos JPG (*.jpg *.jpeg *.jpe);;Archivos TIF (*.tif *.tiff);;Archivos PNG (*.png);;Archivos WEBP (*.webp);;Archivos GIF (*.gif);;Archivos BMP (*.bmp *.dib);;Otros (*.*)";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::show()
{
    QMainWindow::show();
    move(x(), 0);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (preguntar_guardar) {
        while (foto_activa()!= -1)
            on_actionCerrar_triggered();
    }
    destroyAllWindows();
}

void MainWindow::setStatusBarText(QString cadena)
{
    ui->statusBar->showMessage(cadena, 0);
}

int MainWindow::comprobar_primera_libre()
{
    int pl= primera_libre();
    if (pl == -1)
        QMessageBox::warning(this, "Error al crear imagen",
                             "Lo siento. No se pueden crear más ventanas.");
    return pl;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_actionSalir_triggered()
{
    close();
}

void MainWindow::on_actionNueva_imagen_triggered()
{
    int pl= comprobar_primera_libre();
    if (pl != -1) {
        DialogNueva nueva(pl, this);
        nueva.exec();
    }
}

void MainWindow::on_actionAbrir_imagen_triggered()
{
    int pl= comprobar_primera_libre();
    if (pl != -1) {
        QString nombre= QFileDialog::getOpenFileName(this, "Abrir imagen", ".", FiltroImagen);
        if (!nombre.isEmpty())
            crear_nueva(pl, nombre.toUtf8().data());
    }
}

void MainWindow::on_actionPunto_triggered()
{
    herr_actual= HER_PUNTO;
    ui->toolButton_4->setChecked(true);
}

void MainWindow::on_actionLinea_triggered()
{
    herr_actual= HER_LINEA;
    ui->toolButton_5->setChecked(true);
}

void MainWindow::on_actionSeleccionar_triggered()
{
    herr_actual= HER_SELECCION;
    ui->toolButton_6->setChecked(true);
}

void MainWindow::on_toolButton_2_clicked()
{
    on_actionNueva_imagen_triggered();
}

void MainWindow::on_pushButton_clicked()
{
    QColor color= QColorDialog::getColor();
    if (color.isValid()) {
        QString estilo= "background-color: rgb(";
        estilo+= QString::number(color.red())+",";
        estilo+= QString::number(color.green())+",";
        estilo+= QString::number(color.blue())+")";
        ui->pushButton->setStyleSheet(estilo);
        color_pincel= CV_RGB(color.red(), color.green(), color.blue());
    }
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    radio_pincel= value;
}

void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    difum_pincel= value;
}

void MainWindow::on_toolButton_clicked()
{
    on_actionAbrir_imagen_triggered();
}

void MainWindow::on_actionGuardar_triggered()
{
    int fa= foto_activa();
    if (fa != -1)
        guardar_foto(fa);
}

void MainWindow::on_actionGuardar_como_triggered()
{
    int fa= foto_activa();
    if (fa != -1) {
        QString nombre= QFileDialog::getSaveFileName(this, "Guardar imagen", QString::fromStdString(foto[fa].nombre), FiltroImagen);
        if (!nombre.isEmpty())
            guardar_foto(fa, nombre.toUtf8().data());
    }
}

void MainWindow::on_actionCerrar_triggered()
{
    int fa= foto_activa();
    if (fa != -1) {
        if (foto[fa].modificada && preguntar_guardar) {
            QString nombre= QString::fromStdString(foto[fa].nombre);
            nombre= "El archivo " + nombre + " ha sido modificado.\n¿Desea guardarlo?";
            int resp= QMessageBox::question(this, "Archivo modificado", nombre,
                                            QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
            if (resp==QMessageBox::Yes)
                guardar_foto(fa);
            else if (resp==QMessageBox::Cancel)
                return;
            else
                foto[fa].modificada= false;
        }
        cerrar_foto(fa);
    }
}

void MainWindow::on_actionPreguntar_si_guardar_triggered()
{
    preguntar_guardar= ui->actionPreguntar_si_guardar->isChecked();
}

void MainWindow::on_actionColor_del_pincel_triggered()
{
    on_pushButton_clicked();
}

void MainWindow::on_actionSeleccionar_todo_triggered()
{
    int fa= foto_activa();
    if (fa != -1) {
        foto[fa].roi= Rect(0, 0, foto[fa].img.cols, foto[fa].img.rows);
        mostrar(fa);
    }
}

void MainWindow::on_toolButton_3_clicked()
{
    on_actionGuardar_triggered();
}

void MainWindow::on_toolButton_4_clicked()
{
    herr_actual= HER_PUNTO;
}

void MainWindow::on_toolButton_5_clicked()
{
    herr_actual= HER_LINEA;
}

void MainWindow::on_toolButton_6_clicked()
{
    herr_actual= HER_SELECCION;
}

void MainWindow::on_actionInvertir_triggered()
{
    int fa= foto_activa();
    if (fa != -1) {
        int pl= comprobar_primera_libre();
        if (pl != -1)
            invertir(fa, pl);
    }
}

void MainWindow::on_actionRotar_90_triggered()
{
    int fa= foto_activa();
    if (fa != -1) {
        int pl= comprobar_primera_libre();
        if (pl != -1)
            rotar_exacto(fa, pl, 1);
    }
}

void MainWindow::on_actionRotar_180_triggered()
{
    int fa= foto_activa();
    if (fa != -1) {
        int pl= comprobar_primera_libre();
        if (pl != -1)
            rotar_exacto(fa, pl, 2);
    }
}

void MainWindow::on_actionRotar_91_triggered()
{
    int fa= foto_activa();
    if (fa != -1) {
        int pl= comprobar_primera_libre();
        if (pl != -1)
            rotar_exacto(fa, pl, 3);
    }
}

void MainWindow::on_actionBrillo_contraste_triggered()
{
    if (foto_activa() != -1) {
        brillocontraste bc(foto_activa(), this);
        bc.exec();
    }
}

void MainWindow::on_actionGausiano_triggered()
{
    if (foto_activa() !=- 1) {
        suavizados sg(foto_activa(), 1, this);
        sg.exec();
    }
}

void MainWindow::on_actionMedia_triggered()
{
    if (foto_activa() != -1) {
        suavizados sg(foto_activa(), 2, this);
        sg.exec();
    }
}

void MainWindow::on_actionMedia_ponderada_triggered()
{
    if (foto_activa() != -1) {
        int pl= comprobar_primera_libre();
        if (pl != -1) {
            mediaponderada mp(this);
            mp.exec();
        }
    }
}

void MainWindow::on_actionRotar_imagen_triggered()
{
    if (foto_activa() != -1) {
        rotaravideo rv(this);
        rv.exec();
    }
}

void MainWindow::on_actionAcerca_de_triggered()
{
    acercade ad;
    ad.exec();
}

void MainWindow::on_actionImagen_media_triggered()
{
    mediadevideo mv(this);
    mv.exec();
}

void MainWindow::on_toolButton_7_clicked()
{
    herr_actual = HER_RECTANGULO;
}


void MainWindow::on_actionRectangulo_triggered()
{
    herr_actual = HER_RECTANGULO;
    ui->toolButton_7->setChecked(true);
}


void MainWindow::on_actionMediana_triggered()
{
    if (foto_activa() != -1) {
        suavizados sg(foto_activa(), 3, this);
        sg.exec();
    }
}


void MainWindow::on_toolButton_8_clicked()
{
    herr_actual = HER_ELIPSE;
}


void MainWindow::on_actionElipse_triggered()
{
    herr_actual = HER_ELIPSE;
    ui->toolButton->setChecked(true);
}


void MainWindow::on_actionGrises_triggered()
{
    if(foto_activa() != -1) {
        ver_histograma(foto_activa(), 3, primera_libre());
    }
}


void MainWindow::on_actionRojo_triggered()
{
    if(foto_activa() != -1) {
        ver_histograma(foto_activa(), 2, primera_libre());
    }
}


void MainWindow::on_actionVerde_triggered()
{
    if(foto_activa() != -1) {
        ver_histograma(foto_activa(), 1, primera_libre());
    }
}


void MainWindow::on_actionAzul_triggered()
{
    if(foto_activa() != -1) {
        ver_histograma(foto_activa(), 0, primera_libre());
    }
}


void MainWindow::on_toolButton_9_clicked()
{
    herr_actual = HER_ARCOIRIS;
}


void MainWindow::on_actionArcoiris_triggered()
{
    herr_actual = HER_ARCOIRIS;
    ui->toolButton_9->setChecked(true);
}


void MainWindow::on_actionCapturar_de_video_triggered()
{
    if (primera_libre() != -1) {

        QString nombre = QFileDialog::getOpenFileName();
        if (!nombre.isEmpty()) {

            CapturarDeVideo cv(nombre.toLatin1().data(), this);
            if (cv.isOpened()) {
                cv.exec();
            }

        }

    }
}


void MainWindow::on_actionBajorrelieve_triggered()
{
    if (foto_activa() != -1 && primera_libre() != -1) {

        BajoRrelieve br(foto_activa(), primera_libre(), this);
        br.exec();

    }
}


void MainWindow::on_actionCopiar_a_nueva_triggered()
{
    if(foto_activa() != -1 && primera_libre() != -1) {
        copiar_a_nueva(foto_activa(), primera_libre());
    }
}


void MainWindow::on_actionCapturar_de_camara_triggered()
{
    if(primera_libre() != -1) {
        capturar_de_camara(primera_libre());
    }
}


void MainWindow::on_actionVer_ajuste_lineal_del_histograma_triggered()
{
    if(foto_activa() != -1) {
        //ver_ajuste_lineal(foto_activa(), 3, 3);
        AjusteLineal al(foto_activa(), this);
        al.exec();
    }
}


void MainWindow::on_actionEscala_de_color_triggered()
{
    if(foto_activa() != -1 && primera_libre() != -1) {
        escala_color(foto_activa(), primera_libre());
    }
}


void MainWindow::on_actionPinchar_estirar_triggered()
{
    if(foto_activa()!=-1) {
        /*ver_pinchar_estirar(foto_activa(), 200, 200, radio_pincel*10, difum_pincel*100);*/
        PincharEstirar pe(foto_activa(), this);
        pe.exec();
    }
}


void MainWindow::on_actionMatiz_Saturacion_Luminosidad_triggered()
{
    if(foto_activa() != -1) {
        //ver_matiz_sat_lum(foto_activa(), radio_pincel*2, difum_pincel/50.0, 1.0);
        matsatlum msl(foto_activa(), this);
        msl.exec();
    }
}


void MainWindow::on_actionEspectro_triggered()
{
    if(foto_activa() != -1 && primera_libre() != -1) {
        espectro(foto_activa(), primera_libre());
    }
}


void MainWindow::on_actionCopiar_al_portapapeles_triggered()
{
    if(foto_activa() != -1 && primera_libre() != -1) {
        copiar_al_portapapeles(foto_activa());
    }
}

void MainWindow::on_actionR_G_triggered()
{
    if (foto_activa() != -1) {
        int fa = foto_activa();
        if (fa != -1) {
            int pl = comprobar_primera_libre();
            if (pl != -1) {
                int num_celdas = 50;
                ver_histograma_2d(fa, 0, 1, pl, num_celdas); // R-G
            }
        }
    }
}


void MainWindow::on_actionR_B_triggered()
{
    if (foto_activa() != -1) {
        int fa = foto_activa();
        if (fa != -1) {
            int pl = comprobar_primera_libre();
            if (pl != -1) {
                int num_celdas = 50;
                ver_histograma_2d(fa, 0, 2, pl, num_celdas); // R-B
            }
        }
    }
}


void MainWindow::on_actionG_B_triggered()
{
    if (foto_activa() != -1) {
        int fa = foto_activa();
        if (fa != -1) {
            int pl = comprobar_primera_libre();
            if (pl != -1) {
                int num_celdas = 50;
                ver_histograma_2d(fa, 1, 2, pl, num_celdas); // G-B
            }
        }
    }
}


void MainWindow::on_actionMostrar_informaci_n_triggered()
{
    if(foto_activa() != -1 && primera_libre() != -1) {
        mostrar_info_imagen(foto_activa());
    }
}


void MainWindow::on_actionPerspectiva_triggered()
{
    if(foto_activa()!=-1) {
        /*Point2f no[4], nd[4];
        int w = foto[0].img.cols;
        int h = foto[0].img.rows;
        no[0] = Point2f(0, 0);
        no[1] = Point2d(w, 0);
        no[2] = Point2f(w, h);
        no[3] = Point2f(0, h);
        w = foto[1].img.cols;
        h = foto[1].img.rows;
        nd[0] = Point2f(w*0.4, h*0.1);
        nd[1] = Point2d(w*0.65, h*0.2);
        nd[2] = Point2f(w*0.95, h*0.9);
        nd[3] = Point2f(w*0.05, h*0.8);
        ver_perspectiva(0, 1, no, nd);*/
        Perspectiva pe;
        pe.exec();
    }
}


void MainWindow::on_actionSuavizado_temporal_triggered()
{
    QString nombre = QFileDialog::getSaveFileName();
    if(!nombre.isEmpty()) {
        suavizado_temporal(nombre.toLatin1().data());
    }
}


void MainWindow::on_toolButton_10_clicked()
{
    herr_actual = HER_TRAZOCONTINUO;
    reset_trazo_continuo();
}


void MainWindow::on_actionTrazos_triggered()
{
    herr_actual = HER_TRAZOCONTINUO;
    ui->toolButton_10->setChecked(true);
    reset_trazo_continuo();
}


void MainWindow::on_toolButton_11_clicked()
{
    herr_actual = HER_SUAVIZAR_CIRCULAR;
}


void MainWindow::on_actionSuavizado_triggered()
{
    herr_actual = HER_SUAVIZAR_CIRCULAR;
    ui->toolButton_11->setChecked(true);
}

