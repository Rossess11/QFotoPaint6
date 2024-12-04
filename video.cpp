//---------------------------------------------------------------------------

#include "video.h"
#include <math.h>
#include "QMessageBox"

///////////////////////////////////////////////////////////////////
/////////  VARIABLES GLOBALES PRIVADAS               //////////////
///////////////////////////////////////////////////////////////////

static VideoCapture camara;
// Capturador de cámara usado actualmente

static Mat img_media;
// Imagen media acumulada de la cámara, con profundidad 32F

static int frames_img_media;
// Número de frames que se han acumulado en la media img_media

string FiltroVideo= "Todos los formatos (*.avi *.mpg *.wmv *.mov);;Archivos AVI (*.avi);;Archivos MPG (*.mpg *.mpeg);;Archivos WMV (*.wmv);;Archivos MOV (*.mov);;Otros (*.*)";

///////////////////////////////////////////////////////////////////
/////////  FUNCIONES DE PROCESAMIENTO DE VIDEO       //////////////
///////////////////////////////////////////////////////////////////

void rotar_video (int nfoto, string nombre, int modo, int nframes, int codec, double fps)
{
    assert(nfoto>=0 && nfoto<MAX_VENTANAS && foto[nfoto].usada && !nombre.empty() && nframes>0);
    Mat rotada;
    rotar_angulo(foto[nfoto].img, rotada, 0, 1, modo);
    VideoWriter writer(nombre, codec, fps, rotada.size());
    if (writer.isOpened()) {
        for (int i= 0; i<=nframes; i++) {
            rotar_angulo(foto[nfoto].img, rotada, i*360.0/nframes, 1, modo);
            namedWindow("Imagen a vídeo - Rotación", WINDOW_NORMAL);
            imshow("Imagen a vídeo - Rotación", rotada);
            waitKey(1);
            writer << rotada;
        }
        writer.release();
        destroyWindow("Imagen a vídeo - Rotación");
    }
}

//---------------------------------------------------------------------------

int inic_camara (int numero)
{
    if (camara.isOpened())
        camara.release();
    camara.open(numero);
    if (camara.isOpened()) {
        Mat img;
        namedWindow("Imagen de cámara", WINDOW_NORMAL);
        camara >> img;
        resizeWindow("Imagen de cámara", img.size().width, img.size().height);
        imshow("Imagen de cámara", img);
        return int(1000.0/30);
    }
    else
        return 0;
}

//---------------------------------------------------------------------------

void fin_camara (void)
{
    if (camara.isOpened()) {
        camara.release();
        namedWindow("Imagen de cámara", WINDOW_NORMAL);
        destroyWindow("Imagen de cámara");
    }
    namedWindow("Imagen media", WINDOW_NORMAL);
    destroyWindow("Imagen media");
}

//---------------------------------------------------------------------------

void acumular_media (bool primera)
{
    assert(camara.isOpened());
    Mat frame;
    camara >> frame;
    namedWindow("Imagen de cámara", WINDOW_NORMAL);
    imshow("Imagen de cámara", frame);
    if (primera) {
        frames_img_media= 1;
        frame.convertTo(img_media, CV_32FC3);
    }
    else {
        frames_img_media++;
        Mat frame32F;
        frame.convertTo(frame32F, CV_32FC3);
        img_media= frame32F + img_media;
        img_media.convertTo(frame, CV_8UC3, 1.0/frames_img_media);
    }
    namedWindow("Imagen media", WINDOW_NORMAL);
    imshow("Imagen media", frame);
}

//---------------------------------------------------------------------------

void media_a_nueva (int nfoto)
{
    Mat res(img_media.size(), CV_8UC3);
    img_media.convertTo(res, CV_8UC3, 1.0/frames_img_media);
    crear_nueva (nfoto, res);
}

//---------------------------------------------------------------------------

void mostrar_camara (void)
{
    Mat img;
    camara >> img;
    namedWindow("Imagen de cámara", WINDOW_NORMAL);
    imshow("Imagen de cámara", img);
}

//---------------------------------------------------------------------------

void capturar_de_camara (int nres) {
    VideoCapture cap(0);
    if(cap.isOpened()) {
        Mat frame;
        int tecla = -1;
        while(cap.read(frame) && (tecla=waitKey(1)) == -1) {
            imshow("Pulse una tecla para capturar (ESC Salir)", frame);
        }
        if(!frame.empty() && tecla!=27) {
            crear_nueva(nres, frame);
        }
        destroyWindow("Pulse una tecla para capturar (ESC Salir)");
    } else {
        cerr << "No se ha podido abrir la cámara";
    }
}

//---------------------------------------------------------------------------

void callback_suavi(int evento, int x,int y, int flags, void *pt) {
    if(evento==EVENT_CLOSE) {
        int *pi = (int *) pt;
        *pi = 0;
    }
}

void suavizado_temporal(string nombre) {
    //VideoCapture cap("C:/Users/javim/Pictures/vtest.avi");
    VideoCapture cap(0);
    // Descomentar

    Mat frame;
    if(!cap.isOpened() || !cap.read(frame)) {
        QMessageBox::information(nullptr, "Error al abrir la cámara", "No se ha podido abrir la cámara");
        return;
    }

    Mat media = frame.clone();

    media.convertTo(media, CV_32F);

    double alfa = 0;

    int alfa_int = 50;

    int seguir = 1;

    int grabando = 0;

    int tecla = -1;

    VideoWriter wri(nombre, VideoWriter::fourcc('D','I','V','X'), 30, frame.size(), true);

    if(!wri.isOpened()) {
        QMessageBox::information(nullptr, "Error al crear el video", "No se ha podido crear el archivo del video");
        return;
    }

    namedWindow("Pulse una tecla");

    setMouseCallback("Pulse una tecla", callback_suavi, &seguir);

    createTrackbar("Inercia", "Pulse una tecla", &alfa_int, 100);

    while(cap.read(frame) && seguir) {
        tecla = waitKey(1);
        if(tecla==27) {
            break;
        } else if(tecla!=-1) {
            if(!grabando) {
                grabando=1;
            } else {
                break;
            }
        }

        frame.convertTo(frame, CV_32F);
        alfa = alfa_int/100.0;
        addWeighted(media, alfa, frame, 1 - alfa, 0, media);
        Mat res;
        media.convertTo(res, CV_8U);

        if(grabando) {
            wri.write(res);
            circle(res, Point(res.cols/2+4, 50+4), 10, CV_RGB(0, 0, 0), -1);
            circle(res, Point(res.cols/2, 50), 10, CV_RGB(255, 0, 0), -1);
        }

        //flip(res, res, 1);

        imshow("Pulse una tecla", res);
    }
    destroyWindow("Pulse una tecla");
    wri.release();
}
