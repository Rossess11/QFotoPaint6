/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNueva_imagen;
    QAction *actionAbrir_imagen;
    QAction *actionGuardar;
    QAction *actionGuardar_como;
    QAction *actionCerrar;
    QAction *actionSalir;
    QAction *actionPunto;
    QAction *actionLinea;
    QAction *actionSeleccionar;
    QAction *actionSeleccionar_todo;
    QAction *actionColor_del_pincel;
    QAction *actionPreguntar_si_guardar;
    QAction *actionBrillo_contraste;
    QAction *actionInvertir;
    QAction *actionRotar_90;
    QAction *actionRotar_91;
    QAction *actionMedia_ponderada;
    QAction *actionRotar_180;
    QAction *actionGausiano;
    QAction *actionMedia;
    QAction *actionV_deo_a_video;
    QAction *actionRotar_imagen;
    QAction *actionAcerca_de;
    QAction *actionImagen_media;
    QAction *actionRectangulo;
    QAction *actionMediana;
    QAction *actionElipse;
    QAction *actionGrises;
    QAction *actionRojo;
    QAction *actionVerde;
    QAction *actionAzul;
    QAction *actionArcoiris;
    QAction *actionCapturar_de_video;
    QAction *actionBajorrelieve;
    QAction *actionCopiar_a_nueva;
    QAction *actionVer_ajuste_lineal_del_histograma;
    QAction *actionCapturar_de_camara;
    QAction *actionEscala_de_color;
    QAction *actionPinchar_estirar;
    QAction *actionMatiz_Saturacion_Luminosidad;
    QAction *actionEspectro;
    QAction *actionCopiar_al_portapapeles;
    QAction *actionR_G;
    QAction *actionR_B;
    QAction *actionG_B;
    QAction *actionMostrar_informaci_n;
    QWidget *centralWidget;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QLabel *label;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QSlider *horizontalSlider_2;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QToolButton *toolButton_6;
    QPushButton *pushButton;
    QToolButton *toolButton_7;
    QToolButton *toolButton_8;
    QToolButton *toolButton_9;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QMenu *menuEdici_n;
    QMenu *menuOpciones;
    QMenu *menuVer_histograma;
    QMenu *menuVer_histograma_2d;
    QMenu *menuHerramientas;
    QMenu *menuTransformar;
    QMenu *menuRotar;
    QMenu *menuEfectos;
    QMenu *menuSuavizado;
    QMenu *menuV_deo;
    QMenu *menuImagen_a_v_deo;
    QMenu *menuV_deo_a_imagen;
    QMenu *menuAyuda;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(600, 150);
        MainWindow->setMinimumSize(QSize(600, 150));
        MainWindow->setMaximumSize(QSize(600, 150));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/imagenes/icono.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        actionNueva_imagen = new QAction(MainWindow);
        actionNueva_imagen->setObjectName("actionNueva_imagen");
        actionAbrir_imagen = new QAction(MainWindow);
        actionAbrir_imagen->setObjectName("actionAbrir_imagen");
        actionGuardar = new QAction(MainWindow);
        actionGuardar->setObjectName("actionGuardar");
        actionGuardar_como = new QAction(MainWindow);
        actionGuardar_como->setObjectName("actionGuardar_como");
        actionCerrar = new QAction(MainWindow);
        actionCerrar->setObjectName("actionCerrar");
        actionSalir = new QAction(MainWindow);
        actionSalir->setObjectName("actionSalir");
        actionPunto = new QAction(MainWindow);
        actionPunto->setObjectName("actionPunto");
        actionLinea = new QAction(MainWindow);
        actionLinea->setObjectName("actionLinea");
        actionSeleccionar = new QAction(MainWindow);
        actionSeleccionar->setObjectName("actionSeleccionar");
        actionSeleccionar_todo = new QAction(MainWindow);
        actionSeleccionar_todo->setObjectName("actionSeleccionar_todo");
        actionColor_del_pincel = new QAction(MainWindow);
        actionColor_del_pincel->setObjectName("actionColor_del_pincel");
        actionPreguntar_si_guardar = new QAction(MainWindow);
        actionPreguntar_si_guardar->setObjectName("actionPreguntar_si_guardar");
        actionPreguntar_si_guardar->setCheckable(true);
        actionPreguntar_si_guardar->setChecked(false);
        actionBrillo_contraste = new QAction(MainWindow);
        actionBrillo_contraste->setObjectName("actionBrillo_contraste");
        actionInvertir = new QAction(MainWindow);
        actionInvertir->setObjectName("actionInvertir");
        actionRotar_90 = new QAction(MainWindow);
        actionRotar_90->setObjectName("actionRotar_90");
        actionRotar_91 = new QAction(MainWindow);
        actionRotar_91->setObjectName("actionRotar_91");
        actionMedia_ponderada = new QAction(MainWindow);
        actionMedia_ponderada->setObjectName("actionMedia_ponderada");
        actionRotar_180 = new QAction(MainWindow);
        actionRotar_180->setObjectName("actionRotar_180");
        actionGausiano = new QAction(MainWindow);
        actionGausiano->setObjectName("actionGausiano");
        actionMedia = new QAction(MainWindow);
        actionMedia->setObjectName("actionMedia");
        actionV_deo_a_video = new QAction(MainWindow);
        actionV_deo_a_video->setObjectName("actionV_deo_a_video");
        actionRotar_imagen = new QAction(MainWindow);
        actionRotar_imagen->setObjectName("actionRotar_imagen");
        actionAcerca_de = new QAction(MainWindow);
        actionAcerca_de->setObjectName("actionAcerca_de");
        actionImagen_media = new QAction(MainWindow);
        actionImagen_media->setObjectName("actionImagen_media");
        actionRectangulo = new QAction(MainWindow);
        actionRectangulo->setObjectName("actionRectangulo");
        actionMediana = new QAction(MainWindow);
        actionMediana->setObjectName("actionMediana");
        actionElipse = new QAction(MainWindow);
        actionElipse->setObjectName("actionElipse");
        actionGrises = new QAction(MainWindow);
        actionGrises->setObjectName("actionGrises");
        actionRojo = new QAction(MainWindow);
        actionRojo->setObjectName("actionRojo");
        actionVerde = new QAction(MainWindow);
        actionVerde->setObjectName("actionVerde");
        actionAzul = new QAction(MainWindow);
        actionAzul->setObjectName("actionAzul");
        actionArcoiris = new QAction(MainWindow);
        actionArcoiris->setObjectName("actionArcoiris");
        actionCapturar_de_video = new QAction(MainWindow);
        actionCapturar_de_video->setObjectName("actionCapturar_de_video");
        actionBajorrelieve = new QAction(MainWindow);
        actionBajorrelieve->setObjectName("actionBajorrelieve");
        actionCopiar_a_nueva = new QAction(MainWindow);
        actionCopiar_a_nueva->setObjectName("actionCopiar_a_nueva");
        actionVer_ajuste_lineal_del_histograma = new QAction(MainWindow);
        actionVer_ajuste_lineal_del_histograma->setObjectName("actionVer_ajuste_lineal_del_histograma");
        actionCapturar_de_camara = new QAction(MainWindow);
        actionCapturar_de_camara->setObjectName("actionCapturar_de_camara");
        actionEscala_de_color = new QAction(MainWindow);
        actionEscala_de_color->setObjectName("actionEscala_de_color");
        actionPinchar_estirar = new QAction(MainWindow);
        actionPinchar_estirar->setObjectName("actionPinchar_estirar");
        actionMatiz_Saturacion_Luminosidad = new QAction(MainWindow);
        actionMatiz_Saturacion_Luminosidad->setObjectName("actionMatiz_Saturacion_Luminosidad");
        actionEspectro = new QAction(MainWindow);
        actionEspectro->setObjectName("actionEspectro");
        actionCopiar_al_portapapeles = new QAction(MainWindow);
        actionCopiar_al_portapapeles->setObjectName("actionCopiar_al_portapapeles");
        actionR_G = new QAction(MainWindow);
        actionR_G->setObjectName("actionR_G");
        actionR_B = new QAction(MainWindow);
        actionR_B->setObjectName("actionR_B");
        actionG_B = new QAction(MainWindow);
        actionG_B->setObjectName("actionG_B");
        actionMostrar_informaci_n = new QAction(MainWindow);
        actionMostrar_informaci_n->setObjectName("actionMostrar_informaci_n");
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        toolButton = new QToolButton(centralWidget);
        toolButton->setObjectName("toolButton");
        toolButton->setGeometry(QRect(40, 0, 41, 41));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/imagenes/abrir.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButton->setIcon(icon1);
        toolButton->setIconSize(QSize(32, 32));
        toolButton->setAutoRaise(true);
        toolButton_2 = new QToolButton(centralWidget);
        toolButton_2->setObjectName("toolButton_2");
        toolButton_2->setGeometry(QRect(0, 0, 41, 41));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/imagenes/nuevo.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButton_2->setIcon(icon2);
        toolButton_2->setIconSize(QSize(32, 32));
        toolButton_2->setAutoRaise(true);
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 50, 281, 16));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(126, 126, 126);"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label->setWordWrap(false);
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(10, 70, 281, 31));
        horizontalSlider->setMaximum(120);
        horizontalSlider->setValue(10);
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TickPosition::TicksBelow);
        horizontalSlider->setTickInterval(10);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(310, 50, 271, 16));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(126, 126, 126);"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2->setWordWrap(false);
        horizontalSlider_2 = new QSlider(centralWidget);
        horizontalSlider_2->setObjectName("horizontalSlider_2");
        horizontalSlider_2->setGeometry(QRect(310, 70, 271, 31));
        horizontalSlider_2->setMaximum(120);
        horizontalSlider_2->setValue(10);
        horizontalSlider_2->setOrientation(Qt::Orientation::Horizontal);
        horizontalSlider_2->setTickPosition(QSlider::TickPosition::TicksBelow);
        horizontalSlider_2->setTickInterval(10);
        toolButton_3 = new QToolButton(centralWidget);
        toolButton_3->setObjectName("toolButton_3");
        toolButton_3->setGeometry(QRect(80, 0, 41, 41));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/imagenes/guardar.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButton_3->setIcon(icon3);
        toolButton_3->setIconSize(QSize(32, 32));
        toolButton_3->setAutoRaise(true);
        toolButton_4 = new QToolButton(centralWidget);
        toolButton_4->setObjectName("toolButton_4");
        toolButton_4->setGeometry(QRect(130, 0, 41, 41));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/imagenes/punto.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButton_4->setIcon(icon4);
        toolButton_4->setIconSize(QSize(32, 32));
        toolButton_4->setCheckable(true);
        toolButton_4->setChecked(true);
        toolButton_4->setAutoExclusive(true);
        toolButton_5 = new QToolButton(centralWidget);
        toolButton_5->setObjectName("toolButton_5");
        toolButton_5->setGeometry(QRect(170, 0, 41, 41));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/imagenes/linea.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButton_5->setIcon(icon5);
        toolButton_5->setIconSize(QSize(32, 32));
        toolButton_5->setCheckable(true);
        toolButton_5->setAutoExclusive(true);
        toolButton_6 = new QToolButton(centralWidget);
        toolButton_6->setObjectName("toolButton_6");
        toolButton_6->setGeometry(QRect(250, 0, 41, 41));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/imagenes/seleccionar.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButton_6->setIcon(icon6);
        toolButton_6->setIconSize(QSize(32, 32));
        toolButton_6->setCheckable(true);
        toolButton_6->setAutoExclusive(true);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(560, 0, 41, 41));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        toolButton_7 = new QToolButton(centralWidget);
        toolButton_7->setObjectName("toolButton_7");
        toolButton_7->setGeometry(QRect(290, 0, 41, 41));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/imagenes/rectangulo.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButton_7->setIcon(icon7);
        toolButton_7->setCheckable(true);
        toolButton_7->setAutoExclusive(true);
        toolButton_8 = new QToolButton(centralWidget);
        toolButton_8->setObjectName("toolButton_8");
        toolButton_8->setGeometry(QRect(330, 0, 41, 41));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/imagenes/elipse.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        toolButton_8->setIcon(icon8);
        toolButton_8->setCheckable(true);
        toolButton_8->setAutoExclusive(true);
        toolButton_9 = new QToolButton(centralWidget);
        toolButton_9->setObjectName("toolButton_9");
        toolButton_9->setGeometry(QRect(210, 0, 41, 41));
        QIcon icon9(QIcon::fromTheme(QString::fromUtf8("text-x-generic")));
        toolButton_9->setIcon(icon9);
        toolButton_9->setCheckable(true);
        toolButton_9->setAutoExclusive(true);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 600, 22));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName("menuArchivo");
        menuEdici_n = new QMenu(menuBar);
        menuEdici_n->setObjectName("menuEdici_n");
        menuOpciones = new QMenu(menuEdici_n);
        menuOpciones->setObjectName("menuOpciones");
        menuVer_histograma = new QMenu(menuEdici_n);
        menuVer_histograma->setObjectName("menuVer_histograma");
        menuVer_histograma_2d = new QMenu(menuEdici_n);
        menuVer_histograma_2d->setObjectName("menuVer_histograma_2d");
        menuHerramientas = new QMenu(menuBar);
        menuHerramientas->setObjectName("menuHerramientas");
        menuTransformar = new QMenu(menuBar);
        menuTransformar->setObjectName("menuTransformar");
        menuRotar = new QMenu(menuTransformar);
        menuRotar->setObjectName("menuRotar");
        menuEfectos = new QMenu(menuBar);
        menuEfectos->setObjectName("menuEfectos");
        menuSuavizado = new QMenu(menuEfectos);
        menuSuavizado->setObjectName("menuSuavizado");
        menuV_deo = new QMenu(menuBar);
        menuV_deo->setObjectName("menuV_deo");
        menuImagen_a_v_deo = new QMenu(menuV_deo);
        menuImagen_a_v_deo->setObjectName("menuImagen_a_v_deo");
        menuV_deo_a_imagen = new QMenu(menuV_deo);
        menuV_deo_a_imagen->setObjectName("menuV_deo_a_imagen");
        menuAyuda = new QMenu(menuBar);
        menuAyuda->setObjectName("menuAyuda");
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuBar->addAction(menuEdici_n->menuAction());
        menuBar->addAction(menuHerramientas->menuAction());
        menuBar->addAction(menuTransformar->menuAction());
        menuBar->addAction(menuEfectos->menuAction());
        menuBar->addAction(menuV_deo->menuAction());
        menuBar->addAction(menuAyuda->menuAction());
        menuArchivo->addAction(actionNueva_imagen);
        menuArchivo->addAction(actionAbrir_imagen);
        menuArchivo->addAction(actionCapturar_de_camara);
        menuArchivo->addAction(actionCapturar_de_video);
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionGuardar);
        menuArchivo->addAction(actionGuardar_como);
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionCerrar);
        menuArchivo->addAction(actionSalir);
        menuEdici_n->addAction(actionSeleccionar_todo);
        menuEdici_n->addSeparator();
        menuEdici_n->addAction(actionCopiar_a_nueva);
        menuEdici_n->addAction(menuVer_histograma->menuAction());
        menuEdici_n->addAction(menuOpciones->menuAction());
        menuEdici_n->addAction(actionCopiar_al_portapapeles);
        menuEdici_n->addAction(menuVer_histograma_2d->menuAction());
        menuEdici_n->addAction(actionMostrar_informaci_n);
        menuOpciones->addAction(actionColor_del_pincel);
        menuOpciones->addAction(actionPreguntar_si_guardar);
        menuVer_histograma->addAction(actionGrises);
        menuVer_histograma->addAction(actionRojo);
        menuVer_histograma->addAction(actionVerde);
        menuVer_histograma->addAction(actionAzul);
        menuVer_histograma_2d->addAction(actionR_G);
        menuVer_histograma_2d->addAction(actionR_B);
        menuVer_histograma_2d->addAction(actionG_B);
        menuHerramientas->addAction(actionPunto);
        menuHerramientas->addAction(actionArcoiris);
        menuHerramientas->addAction(actionLinea);
        menuHerramientas->addAction(actionRectangulo);
        menuHerramientas->addAction(actionElipse);
        menuHerramientas->addAction(actionSeleccionar);
        menuTransformar->addAction(actionBrillo_contraste);
        menuTransformar->addAction(actionVer_ajuste_lineal_del_histograma);
        menuTransformar->addAction(actionInvertir);
        menuTransformar->addAction(menuRotar->menuAction());
        menuTransformar->addAction(actionMedia_ponderada);
        menuTransformar->addAction(actionEscala_de_color);
        menuTransformar->addAction(actionMatiz_Saturacion_Luminosidad);
        menuTransformar->addAction(actionEspectro);
        menuRotar->addAction(actionRotar_90);
        menuRotar->addAction(actionRotar_180);
        menuRotar->addAction(actionRotar_91);
        menuEfectos->addAction(menuSuavizado->menuAction());
        menuEfectos->addAction(actionBajorrelieve);
        menuEfectos->addAction(actionPinchar_estirar);
        menuSuavizado->addAction(actionGausiano);
        menuSuavizado->addAction(actionMedia);
        menuSuavizado->addAction(actionMediana);
        menuV_deo->addAction(menuImagen_a_v_deo->menuAction());
        menuV_deo->addAction(menuV_deo_a_imagen->menuAction());
        menuV_deo->addAction(actionV_deo_a_video);
        menuImagen_a_v_deo->addAction(actionRotar_imagen);
        menuV_deo_a_imagen->addAction(actionImagen_media);
        menuAyuda->addAction(actionAcerca_de);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "QFotoPaint6", nullptr));
        actionNueva_imagen->setText(QCoreApplication::translate("MainWindow", "Nueva imagen...", nullptr));
        actionAbrir_imagen->setText(QCoreApplication::translate("MainWindow", "Abrir imagen...", nullptr));
        actionGuardar->setText(QCoreApplication::translate("MainWindow", "Guardar", nullptr));
        actionGuardar_como->setText(QCoreApplication::translate("MainWindow", "Guardar como...", nullptr));
        actionCerrar->setText(QCoreApplication::translate("MainWindow", "Cerrar", nullptr));
        actionSalir->setText(QCoreApplication::translate("MainWindow", "Salir", nullptr));
        actionPunto->setText(QCoreApplication::translate("MainWindow", "Punto", nullptr));
        actionLinea->setText(QCoreApplication::translate("MainWindow", "L\303\255nea", nullptr));
        actionSeleccionar->setText(QCoreApplication::translate("MainWindow", "Seleccionar", nullptr));
        actionSeleccionar_todo->setText(QCoreApplication::translate("MainWindow", "Seleccionar todo", nullptr));
        actionColor_del_pincel->setText(QCoreApplication::translate("MainWindow", "Color del pincel...", nullptr));
        actionPreguntar_si_guardar->setText(QCoreApplication::translate("MainWindow", "Preguntar si guardar", nullptr));
        actionBrillo_contraste->setText(QCoreApplication::translate("MainWindow", "Brillo/Contraste/Gama", nullptr));
        actionInvertir->setText(QCoreApplication::translate("MainWindow", "Invertir", nullptr));
        actionRotar_90->setText(QCoreApplication::translate("MainWindow", "Rotar 90\302\272", nullptr));
        actionRotar_91->setText(QCoreApplication::translate("MainWindow", "Rotar 270\302\272", nullptr));
        actionMedia_ponderada->setText(QCoreApplication::translate("MainWindow", "Media ponderada...", nullptr));
        actionRotar_180->setText(QCoreApplication::translate("MainWindow", "Rotar 180\302\272", nullptr));
        actionGausiano->setText(QCoreApplication::translate("MainWindow", "Gausiano...", nullptr));
        actionMedia->setText(QCoreApplication::translate("MainWindow", "Media...", nullptr));
        actionV_deo_a_video->setText(QCoreApplication::translate("MainWindow", "V\303\255deo a video", nullptr));
        actionRotar_imagen->setText(QCoreApplication::translate("MainWindow", "Rotar imagen...", nullptr));
        actionAcerca_de->setText(QCoreApplication::translate("MainWindow", "Acerca de...", nullptr));
        actionImagen_media->setText(QCoreApplication::translate("MainWindow", "Imagen media...", nullptr));
        actionRectangulo->setText(QCoreApplication::translate("MainWindow", "Rectangulo", nullptr));
        actionMediana->setText(QCoreApplication::translate("MainWindow", "Mediana...", nullptr));
        actionElipse->setText(QCoreApplication::translate("MainWindow", "Elipse", nullptr));
        actionGrises->setText(QCoreApplication::translate("MainWindow", "Grises", nullptr));
        actionRojo->setText(QCoreApplication::translate("MainWindow", "Rojo", nullptr));
        actionVerde->setText(QCoreApplication::translate("MainWindow", "Verde", nullptr));
        actionAzul->setText(QCoreApplication::translate("MainWindow", "Azul", nullptr));
        actionArcoiris->setText(QCoreApplication::translate("MainWindow", "Arcoiris", nullptr));
        actionCapturar_de_video->setText(QCoreApplication::translate("MainWindow", "Capturar de video...", nullptr));
        actionBajorrelieve->setText(QCoreApplication::translate("MainWindow", "Bajorrelieve...", nullptr));
        actionCopiar_a_nueva->setText(QCoreApplication::translate("MainWindow", "Copiar a nueva", nullptr));
        actionVer_ajuste_lineal_del_histograma->setText(QCoreApplication::translate("MainWindow", "Ajuste lineal del histograma", nullptr));
        actionCapturar_de_camara->setText(QCoreApplication::translate("MainWindow", "Capturar de camara...", nullptr));
        actionEscala_de_color->setText(QCoreApplication::translate("MainWindow", "Escala de color", nullptr));
        actionPinchar_estirar->setText(QCoreApplication::translate("MainWindow", "Pinchar/estirar...", nullptr));
        actionMatiz_Saturacion_Luminosidad->setText(QCoreApplication::translate("MainWindow", "Matiz/Saturacion/Luminosidad", nullptr));
        actionEspectro->setText(QCoreApplication::translate("MainWindow", "Espectro", nullptr));
        actionCopiar_al_portapapeles->setText(QCoreApplication::translate("MainWindow", "Copiar al portapapeles", nullptr));
        actionR_G->setText(QCoreApplication::translate("MainWindow", "R-G", nullptr));
        actionR_B->setText(QCoreApplication::translate("MainWindow", "R-B", nullptr));
        actionG_B->setText(QCoreApplication::translate("MainWindow", "G-B", nullptr));
        actionMostrar_informaci_n->setText(QCoreApplication::translate("MainWindow", "Mostrar informaci\303\263n", nullptr));
        toolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        toolButton_2->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; color:#ffffff;\">Radio del pincel</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; color:#ffffff;\">Suavizado del pincel</span></p></body></html>", nullptr));
        toolButton_3->setText(QString());
        toolButton_4->setText(QString());
        toolButton_5->setText(QString());
        toolButton_6->setText(QString());
        pushButton->setText(QString());
        toolButton_7->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        toolButton_8->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        toolButton_9->setText(QCoreApplication::translate("MainWindow", "ARCOIRIS", nullptr));
        menuArchivo->setTitle(QCoreApplication::translate("MainWindow", "Archivo", nullptr));
        menuEdici_n->setTitle(QCoreApplication::translate("MainWindow", "Edici\303\263n", nullptr));
        menuOpciones->setTitle(QCoreApplication::translate("MainWindow", "Opciones", nullptr));
        menuVer_histograma->setTitle(QCoreApplication::translate("MainWindow", "Ver histograma", nullptr));
        menuVer_histograma_2d->setTitle(QCoreApplication::translate("MainWindow", "Ver histograma 2d", nullptr));
        menuHerramientas->setTitle(QCoreApplication::translate("MainWindow", "Herramientas", nullptr));
        menuTransformar->setTitle(QCoreApplication::translate("MainWindow", "Transformar", nullptr));
        menuRotar->setTitle(QCoreApplication::translate("MainWindow", "Rotar", nullptr));
        menuEfectos->setTitle(QCoreApplication::translate("MainWindow", "Efectos", nullptr));
        menuSuavizado->setTitle(QCoreApplication::translate("MainWindow", "Suavizado", nullptr));
        menuV_deo->setTitle(QCoreApplication::translate("MainWindow", "V\303\255deo", nullptr));
        menuImagen_a_v_deo->setTitle(QCoreApplication::translate("MainWindow", "Imagen a v\303\255deo", nullptr));
        menuV_deo_a_imagen->setTitle(QCoreApplication::translate("MainWindow", "V\303\255deo a imagen", nullptr));
        menuAyuda->setTitle(QCoreApplication::translate("MainWindow", "Ayuda", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
