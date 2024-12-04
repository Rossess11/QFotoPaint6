//---------------------------------------------------------------------------

#include "imagenes.h"
#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QFileDialog>
#include <assert.h>
#include <opencv2/core.hpp>
#include <QClipboard>
#include <QGuiApplication>

///////////////////////////////////////////////////////////////////
/////////  VARIABLES GLOBALES                        //////////////
///////////////////////////////////////////////////////////////////

ventana foto[MAX_VENTANAS];

tipo_herramienta herr_actual= HER_PUNTO;

int radio_pincel= 10;

Scalar color_pincel= CV_RGB(255, 255, 255);

int difum_pincel= 10;

bool preguntar_guardar= false;

bool callback_inactivo= false;

static int numpos= 0; // Número actual en el orden de posición de las ventanas

///////////////////////////////////////////////////////////////////
/////////  FUNCIONES DE MANEJO DE VENTANAS           //////////////
///////////////////////////////////////////////////////////////////

void callback (int event, int x, int y, int flags, void *_nfoto);

//---------------------------------------------------------------------------

void inic_fotos (void)
{
    for (int i= 0; i<MAX_VENTANAS; i++)
        foto[i].usada= false;
}

//---------------------------------------------------------------------------

void fin_fotos (void)
{
    for (int i= 0; i<MAX_VENTANAS; i++) {
        if (foto[i].usada) {
            destroyWindow(foto[i].nombre);
            foto[i].usada= false;
        }
    }
}

//---------------------------------------------------------------------------

int primera_libre (void)
{
    for (int i= 0; i<MAX_VENTANAS; i++)
        if (!foto[i].usada)
            return i;
    return -1;
}

//---------------------------------------------------------------------------

void escribir_barra_estado (void)
{
    int usadas, modificadas;
    num_fotos(usadas, modificadas);
    w->setStatusBarText(QString::number(usadas)+" fotos abiertas, "+
                        QString::number(modificadas)+" modificadas.");
}

//---------------------------------------------------------------------------

void crear_nueva (int nfoto, int ancho, int alto, Scalar color)
{
    assert(nfoto>=0 && nfoto<MAX_VENTANAS && !foto[nfoto].usada);
    foto[nfoto].nombre= "nueva-"+to_string(nfoto)+".png";
    foto[nfoto].nombref= foto[nfoto].nombre;
    foto[nfoto].img.create(alto, ancho, CV_8UC3);
    foto[nfoto].img=  color;
    namedWindow(foto[nfoto].nombre, WINDOW_NO_POPUP+WINDOW_MOVE_RIGHT);
    foto[nfoto].orden= numpos++;
    imshow(foto[nfoto].nombre, foto[nfoto].img);
    foto[nfoto].usada= true;
    foto[nfoto].modificada= true;
    foto[nfoto].roi= Rect(0, 0, ancho, alto);
    setMouseCallback(foto[nfoto].nombre, callback, reinterpret_cast<void*>(nfoto));
    escribir_barra_estado();
}

//---------------------------------------------------------------------------

void crear_nueva (int nfoto, Mat img)
{
    assert(nfoto>=0 && nfoto<MAX_VENTANAS && !foto[nfoto].usada && !img.empty());
    foto[nfoto].nombre= "nueva-"+to_string(nfoto)+".png";
    foto[nfoto].nombref= foto[nfoto].nombre;
    foto[nfoto].img= img;
    namedWindow(foto[nfoto].nombre, WINDOW_NO_POPUP+WINDOW_MOVE_RIGHT);
    foto[nfoto].orden= numpos++;
    imshow(foto[nfoto].nombre, foto[nfoto].img);
    foto[nfoto].usada= true;
    foto[nfoto].modificada= true;
    foto[nfoto].roi= Rect(0, 0, img.cols, img.rows);
    setMouseCallback(foto[nfoto].nombre, callback, reinterpret_cast<void*>(nfoto));
    escribir_barra_estado();
}

//---------------------------------------------------------------------------

void crear_nueva (int nfoto, string nombre)
{
    assert(nfoto>=0 && nfoto<MAX_VENTANAS && !foto[nfoto].usada);
    foto[nfoto].nombre= nombre;
    foto[nfoto].nombref= Lt1(nombre);
    foto[nfoto].img= imread(foto[nfoto].nombref);
    if (foto[nfoto].img.empty())
        return;
    namedWindow(foto[nfoto].nombre, WINDOW_NO_POPUP+WINDOW_MOVE_RIGHT);
    foto[nfoto].orden= numpos++;
    imshow(foto[nfoto].nombre, foto[nfoto].img);
    foto[nfoto].usada= true;
    foto[nfoto].modificada= false;
    foto[nfoto].roi= Rect(0, 0, foto[nfoto].img.cols, foto[nfoto].img.rows);
    setMouseCallback(foto[nfoto].nombre, callback, reinterpret_cast<void*>(nfoto));
    escribir_barra_estado();
}

//---------------------------------------------------------------------------

void guardar_foto (int nfoto, string nombre)
{
    assert(nfoto>=0 && nfoto<MAX_VENTANAS && foto[nfoto].usada);
    foto[nfoto].modificada= false;
    // 1. Guardar la imagen con el mismo nombre que tiene
    if (nombre=="")
        imwrite(foto[nfoto].nombref, foto[nfoto].img);
    // 2. Guardar la imagen con un nombre distinto al actual
    else {
        imwrite(Lt1(nombre), foto[nfoto].img);
        setWindowTitle(foto[nfoto].nombre, nombre);
    }
    escribir_barra_estado();
}

//---------------------------------------------------------------------------

void cerrar_foto (int nfoto, bool destruir_ventana)
{
    assert(nfoto>=0 && nfoto<MAX_VENTANAS && foto[nfoto].usada);
    if (destruir_ventana)
        destroyWindow(foto[nfoto].nombre);
    foto[nfoto].usada= false;
    escribir_barra_estado();
}

//---------------------------------------------------------------------------

void mostrar (int nfoto)
{
    assert(nfoto>=0 && nfoto<MAX_VENTANAS && foto[nfoto].usada);
    imshow(foto[nfoto].nombre, foto[nfoto].img);
    escribir_barra_estado();
}

//---------------------------------------------------------------------------

int nombre_a_numero (string nombre)
{
    for (int i= 0; i<MAX_VENTANAS; i++)
        if (foto[i].usada && foto[i].nombre==nombre)
            return i;
    return -1;
}

//---------------------------------------------------------------------------

int foto_activa (void)
{
    int maxorden= -1, maxpos= -1;
    for (int i= 0; i<MAX_VENTANAS; i++) {
        if (foto[i].usada && foto[i].orden>maxorden) {
            maxorden= foto[i].orden;
            maxpos= i;
        }
    }
    return maxpos;
}

//---------------------------------------------------------------------------

int num_fotos (int &usadas, int &modificadas)
{
    usadas= 0;
    modificadas= 0;
    for (int i= 0; i<MAX_VENTANAS; i++) {
        if (foto[i].usada) {
            usadas++;
            if (foto[i].modificada)
                modificadas++;
        }
    }
    return usadas;
}

//---------------------------------------------------------------------------

void activar_callback_fotos (bool activo)
{
    callback_inactivo= !activo;
}

///////////////////////////////////////////////////////////////////
/////////  FUNCIONES DEL CALLBACK PRINCIPAL          //////////////
///////////////////////////////////////////////////////////////////

static int downx, downy;
// Posición inicial del ratón al pinchar sobre la imagen actual

//---------------------------------------------------------------------------

void ninguna_accion (int factual, int x, int y)
{
    Mat res= foto[factual].img.clone();
    circle(res, Point(x, y), radio_pincel, CV_RGB(255,255,255), 2, LINE_AA);
    imshow(foto[factual].nombre, res);
}

//---------------------------------------------------------------------------

void cb_close (int factual)
{
    if (foto[factual].usada && !foto[factual].img.empty()) {
        if (foto[factual].modificada && preguntar_guardar) {
            QString cadena= "El archivo " + QString::fromStdString(foto[factual].nombre) +
                    " ha sido modificado.\n¿Desea guardarlo?";
            int resp= QMessageBox::question(w, "Archivo modificado", cadena,
                                            QMessageBox::Yes | QMessageBox::No );
            if (resp==QMessageBox::Yes)
                guardar_foto(factual);
        }
        cerrar_foto(factual, false);
    }
}

//---------------------------------------------------------------------------

void cb_punto (int factual, int x, int y)
{
    Mat im= foto[factual].img;  // Ojo: esto no es una copia, sino a la misma imagen
    if (difum_pincel==0)
        circle(im, Point(x, y), radio_pincel, color_pincel, -1, LINE_AA);
    else {
        int tam = radio_pincel + difum_pincel;
        int posx = tam, posy = tam;
        Rect roi(x-tam, y-tam, 2*tam+1, 2*tam+1);
        if(roi.x<0) {
            roi.width = roi.x;
            posx += roi.x;
            roi.x = 0;
        }
        if(roi.y<0) {
            roi.height += roi.y;
            posy += roi.y;
            roi.y = 0;
        }
        if(roi.x + roi.width > im.cols) {
            roi.width = im.cols - roi.x;
        }
        if(roi.y + roi.height > im.rows) {
            roi.height = im.rows - roi.y;
        }
        Mat trozo = im(roi);
        Mat res(roi.size(), im.type(), color_pincel);
        Mat cop(roi.size(), im.type(), CV_RGB(0,0,0));
        circle(cop, Point(posx, posy), radio_pincel, CV_RGB(255,255,255), -1, LINE_AA);
        blur(cop, cop, Size(difum_pincel*2+1, difum_pincel*2+1));
        multiply(res, cop, res, 1.0/255.0);
        bitwise_not(cop, cop);
        multiply(trozo, cop, trozo, 1.0/255.0);
        trozo = res + trozo;
    }
    imshow(foto[factual].nombre, im);
    foto[factual].modificada= true;
}


//---------------------------------------------------------------------------

Scalar color_arcoiris () {

    static Scalar c = CV_RGB(255,0,0);
    static int  estado = 0;
    int incr = 8;

    switch (estado) {
        case 0:
            c.val[1] +=incr;
            if (c.val[1] >= 255) estado ++;
            break;

        case 1:
            c.val[2] -=incr;
            if (c.val[2] <= 0) estado ++;
            break;

        case 2:
            c.val[0] += incr;
            if (c.val[0] >= 255) estado ++;
            break;

        case 3:
            c.val[1] -= incr;
            if (c.val[1] <=0) estado ++;
            break;

        case 4:
            c.val[2] += incr;
            if (c.val[2] >= 255) estado ++;
            break;

        case 5:
            c.val[0] -= incr;
            if (c.val[0] <= 0) estado =0;
            break;

    }
        return c;
}

void cb_arcoiris (int factual, int x, int y)
{
    Mat im= foto[factual].img;  // Ojo: esto no es una copia, sino a la misma imagen
    if (difum_pincel==0)
        circle(im, Point(x, y), radio_pincel, color_arcoiris(), -1, LINE_AA);
    else {
        int tam = radio_pincel + difum_pincel;
        int posx = tam, posy = tam;
        Rect roi(x-tam, y-tam, 2*tam+1, 2*tam+1);
        if(roi.x<0) {
            roi.width = roi.x;
            posx += roi.x;
            roi.x = 0;
        }
        if(roi.y<0) {
            roi.height += roi.y;
            posy += roi.y;
            roi.y = 0;
        }
        if(roi.x + roi.width > im.cols) {
            roi.width = im.cols - roi.x;
        }
        if(roi.y + roi.height > im.rows) {
            roi.height = im.rows - roi.y;
        }
        Mat trozo = im(roi);
        Mat res(roi.size(), im.type(), color_arcoiris());
        Mat cop(roi.size(), im.type(), CV_RGB(0,0,0));
        circle(cop, Point(posx, posy), radio_pincel, CV_RGB(255,255,255), -1, LINE_AA);
        blur(cop, cop, Size(difum_pincel*2+1, difum_pincel*2+1));
        multiply(res, cop, res, 1.0/255.0);
        bitwise_not(cop, cop);
        multiply(trozo, cop, trozo, 1.0/255.0);
        trozo = res + trozo;
    }
    imshow(foto[factual].nombre, im);
    foto[factual].modificada= true;
}

//---------------------------------------------------------------------------

void cb_linea (int factual, int x, int y)
{
    Mat im= foto[factual].img;  // Ojo: esto no es una copia, sino a la misma imagen
    if (difum_pincel==0)
        line(im, Point(downx, downy), Point(x,y), color_pincel, radio_pincel*2+1);
    else {
        Mat res(im.size(), im.type(), color_pincel);
        Mat cop(im.size(), im.type(), CV_RGB(0,0,0));
        line(cop, Point(downx, downy), Point(x,y), CV_RGB(255,255,255), radio_pincel*2+1);
        blur(cop, cop, Size(difum_pincel*2+1, difum_pincel*2+1));
        multiply(res, cop, res, 1.0/255.0);
        bitwise_not(cop, cop);
        multiply(im, cop, im, 1.0/255.0);
        im= res + im;
    }
    imshow(foto[factual].nombre, im);
    foto[factual].modificada= true;
}

//---------------------------------------------------------------------------

void cb_rectangulo (int factual, int x, int y)
{
    Mat im= foto[factual].img;  // Ojo: esto no es una copia, sino a la misma imagen
    if (difum_pincel==0)
        rectangle(im, Point(downx, downy), Point(x,y), color_pincel, radio_pincel*2-1);
    else {
        Mat res(im.size(), im.type(), color_pincel);
        Mat cop(im.size(), im.type(), CV_RGB(0,0,0));
        rectangle(cop, Point(downx, downy), Point(x,y), CV_RGB(255,255,255), radio_pincel*2-1);
        blur(cop, cop, Size(difum_pincel*2+1, difum_pincel*2+1));
        multiply(res, cop, res, 1.0/255.0);
        bitwise_not(cop, cop);
        multiply(im, cop, im, 1.0/255.0);
        im= res + im;
    }
    imshow(foto[factual].nombre, im);
    foto[factual].modificada= true;
}

//---------------------------------------------------------------------------

void cb_elipse (int factual, int x, int y)
{
    Mat im= foto[factual].img;  // Ojo: esto no es una copia, sino a la misma imagen
    if (difum_pincel==0)
        ellipse(im, Point(downx, downy), Size(abs(x-downx), abs(y-downy)), 0, 0, 360, color_pincel, radio_pincel*2-1);
    else {
        Mat res(im.size(), im.type(), color_pincel);
        Mat cop(im.size(), im.type(), CV_RGB(0,0,0));
        ellipse(cop, Point(downx, downy), Size(abs(x-downx), abs(y-downy)), 0, 0, 360, CV_RGB(255,255,255), radio_pincel*2-1);
        blur(cop, cop, Size(difum_pincel*2+1, difum_pincel*2+1));
        multiply(res, cop, res, 1.0/255.0);
        bitwise_not(cop, cop);
        multiply(im, cop, im, 1.0/255.0);
        im= res + im;
    }
    imshow(foto[factual].nombre, im);
    foto[factual].modificada= true;
}

//---------------------------------------------------------------------------

void cb_ver_linea (int factual, int x, int y)
{
    Mat res= foto[factual].img.clone();
    line(res, Point(downx, downy), Point(x,y), color_pincel, radio_pincel*2+1);
    imshow(foto[factual].nombre, res);
}

//---------------------------------------------------------------------------

void cb_ver_rectangulo (int factual, int x, int y)
{
    Mat res= foto[factual].img.clone();
    rectangle(res, Point(downx, downy), Point(x,y), color_pincel, radio_pincel*2-1);
    imshow(foto[factual].nombre, res);
}

//---------------------------------------------------------------------------

void cb_ver_elipse (int factual, int x, int y)
{
    Mat res= foto[factual].img.clone();
    ellipse(res, Point(downx, downy), Size(abs(x-downx), abs(y-downy)), 0, 0, 360, color_pincel, radio_pincel*2-1);
    imshow(foto[factual].nombre, res);
}

//---------------------------------------------------------------------------

void cb_seleccionar (int factual, int x, int y)
{
    Mat im= foto[factual].img;
    Rect nuevo= Rect(min(downx, x), min(downy, y),
                     max(downx, x)-min(downx, x)+1, max(downy, y)-min(downy, y)+1);
    if (nuevo.x<0)
        nuevo.x= 0;
    if (nuevo.y<0)
        nuevo.y= 0;
    if (nuevo.x+nuevo.width>im.size().width)
        nuevo.width= im.size().width-nuevo.x;
    if (nuevo.y+nuevo.height>im.size().height)
        nuevo.height= im.size().height-nuevo.y;
    foto[factual].roi= nuevo;
}

//---------------------------------------------------------------------------

void cb_ver_seleccion (int factual, int x, int y, bool foto_roi)
{
    Mat res= foto[factual].img.clone();
    Point p1, p2;
    if (foto_roi) {
        p1.x= foto[factual].roi.x;
        p1.y= foto[factual].roi.y;
        p2.x= foto[factual].roi.x+foto[factual].roi.width-1;
        p2.y= foto[factual].roi.y+foto[factual].roi.height-1;
    }
    else {
        p1= Point(downx, downy);
        p2= Point(x, y);
    }
    rectangle(res, p1, p2, CV_RGB(255,foto_roi?0:255,0),2);
    imshow(foto[factual].nombre, res);
}

//---------------------------------------------------------------------------

void callback (int event, int x, int y, int flags, void *_nfoto)
{
    int factual= (long long) _nfoto;

    // 1. Eventos y casos especiales
    // 1.1. Evento cerrar ventana
    if (event==EVENT_CLOSE) {
        cb_close(factual);
        return;
    }
    // 1.2. Desactivado el callback al estar ejecutando una herramienta
    if (callback_inactivo) {
        return;
    }
    // 1.3. Evento obtiene el foco
    if (event==EVENT_FOCUS) {
        foto[factual].orden= numpos++;
        return;
    }
    // 1.4. El ratón se sale de la ventana
    if (x<0 || x>=foto[factual].img.size().width || y<0 || y>=foto[factual].img.size().height)
        return;
    // 1.5. Se inicia la pulsación del ratón
    if (event==EVENT_LBUTTONDOWN) {
        downx= x;
        downy= y;
    }

    // 2. Según la herramienta actual
    switch (herr_actual) {

    // 2.1. Herramienta PUNTO
    case HER_PUNTO:
        if (flags==EVENT_FLAG_LBUTTON && event!=EVENT_LBUTTONUP)
            cb_punto(factual, x, y);
        else
            ninguna_accion(factual, x, y);
        break;

    // 2.2. Herramienta ARCOIRIS
    case HER_ARCOIRIS:
        if (flags==EVENT_FLAG_LBUTTON && event!=EVENT_LBUTTONUP)
            cb_arcoiris(factual, x, y);
        else
            ninguna_accion(factual, x, y);
        break;

        // 2.3. Herramienta LINEA
    case HER_LINEA:
        if (event==EVENT_LBUTTONUP)
            cb_linea(factual, x, y);
        else if (event==EVENT_MOUSEMOVE && flags==EVENT_FLAG_LBUTTON)
            cb_ver_linea(factual, x, y);
        else
            ninguna_accion(factual, x, y);
        break;

        // 2.4. Herramienta SELECCION
    case HER_SELECCION:
        if (event==EVENT_LBUTTONUP)
            cb_seleccionar(factual, x, y);
        else if (event==EVENT_MOUSEMOVE)
            cb_ver_seleccion(factual, x, y, flags!=EVENT_FLAG_LBUTTON);
        break;
        // 2.5 Herramienta RECTANGULO
    case HER_RECTANGULO:
        if (event==EVENT_LBUTTONUP)
            cb_rectangulo(factual, x, y);
        else if (event==EVENT_MOUSEMOVE && flags==EVENT_FLAG_LBUTTON)
            cb_ver_rectangulo(factual, x, y);
        else
            ninguna_accion(factual, x, y);
        break;
        // 2.6 Herramienta ELIPSE
    case HER_ELIPSE:
        if (event==EVENT_LBUTTONUP)
            cb_elipse(factual, x, y);
        else if (event==EVENT_MOUSEMOVE && flags==EVENT_FLAG_LBUTTON)
            cb_ver_elipse(factual, x, y);
        else
            ninguna_accion(factual, x, y);
        break;
    }
    escribir_barra_estado();
}


///////////////////////////////////////////////////////////////////
/////////  FUNCIONES DE PROCESAMIENTO DE IMAGENES    //////////////
///////////////////////////////////////////////////////////////////

void invertir (int nfoto, int nres)
{
    Mat img(foto[nfoto].img.size(), foto[nfoto].img.type());
    bitwise_not(foto[nfoto].img, img);
    crear_nueva(nres, img);
}

//---------------------------------------------------------------------------

void rotar_angulo (Mat imagen, Mat &imgRes, double angulo, double escala, int modo)
{
    double w= imagen.size().width, h= imagen.size().height;
    Size sres;
    if (modo==0) {     // Reescalar con proporción al original
        sres.width= int(w*escala);
        sres.height= int(h*escala);
    }
    else if (modo==1)  // Reescalar y ampliar para caber entera
        sres.width= sres.height= int(sqrt(w*w + h*h)*escala);
    else               // Reescalar y recortar para no mostrar borde
        sres.width= sres.height= int(min(w, h)*escala/sqrt(2.0));
    imgRes.create(sres, imagen.type());
    double sa= sin(angulo*M_PI/180), ca= cos(angulo*M_PI/180);
    double cx= -w/2*ca-h/2*sa, cy= w/2*sa-h/2*ca;
    Mat M= getRotationMatrix2D(Point2f(0,0), angulo, escala);
    M.at<double>(0,2)= sres.width/2+cx*escala;
    M.at<double>(1,2)= sres.height/2+cy*escala;
    imgRes= color_pincel;
    warpAffine(imagen, imgRes, M, sres, INTER_CUBIC);
}

//---------------------------------------------------------------------------

void rotar_exacto (int nfoto, int nres, int grado)
{
    assert(nfoto>=0 && nfoto<MAX_VENTANAS && foto[nfoto].usada);
    assert(nres>=0 && nres<MAX_VENTANAS && !foto[nres].usada);
    Mat entrada= foto[nfoto].img;
    Mat salida;
    if (grado == 0)
        salida= entrada.clone();
    else if (grado == 1) {
        transpose(entrada, salida);
        flip(salida, salida, 1);
    }
    else if (grado == 2)
        flip(entrada, salida, -1);
    else if (grado == 3) {
        transpose(entrada, salida);
        flip(salida, salida, 0);
    }
    crear_nueva(nres, salida);
}

//---------------------------------------------------------------------------

void ver_brillo_contraste_gama (int nfoto, double suma, double prod, double gama, bool guardar)
{
    assert(nfoto>=0 && nfoto<MAX_VENTANAS && foto[nfoto].usada);
    Mat img;
    foto[nfoto].img.convertTo(img, CV_8UC3, prod, suma);

    Mat img32;
    img.convertTo(img32, CV_32FC3, 1.0/255);
    pow(img32, 1/gama, img32);
    img32.convertTo(img, CV_8UC3, 255);

    imshow(foto[nfoto].nombre, img);
    if (guardar) {
        img.copyTo(foto[nfoto].img);
        foto[nfoto].modificada= true;
    }
}

//---------------------------------------------------------------------------

void ver_suavizado (int nfoto, int ntipo, int tamx, int tamy, bool guardar)
{
    assert(nfoto>=0 && nfoto<MAX_VENTANAS && foto[nfoto].usada);
    assert(tamx>0 && tamx&1 && tamy>0 && tamy&1);
    Mat img= foto[nfoto].img.clone();
    Mat trozo = img(foto[nfoto].roi);
    if (ntipo == 1)
        GaussianBlur(trozo, trozo, Size(tamx, tamy), 0);
    else if (ntipo == 2)
        blur(trozo, trozo, Size(tamx, tamy));
    else if (ntipo == 3)
        medianBlur(trozo, trozo, tamx);
    imshow(foto[nfoto].nombre, img);
    if (guardar) {
        img.copyTo(foto[nfoto].img);
        foto[nfoto].modificada= true;
    }
}

//---------------------------------------------------------------------------

void ver_histograma(int nfoto, int canal, int nres) {
    QImage imq= QImage(":/imagenes/histbase.png");
    Mat histograma(imq.height(),imq.width(),CV_8UC4,imq.scanLine(0));
    cvtColor(histograma, histograma, COLOR_RGBA2RGB);

    Mat gris;
    Mat hist;
    cvtColor(foto[nfoto].img, gris, COLOR_BGR2GRAY); // Conversión a gris
    int canales[1]= {0};
    int bins[1]= {256};
    float rango[2]= {0, 256};
    const float *rangos[]= {rango};
    if(canal == 3) {
        calcHist(&gris, 1, canales, noArray(), hist, 1, bins, rangos);
    } else {
        calcHist(&foto[nfoto].img, 1, &canal, noArray(), hist, 1, bins, rangos);
    }
    double vmin, vmax;
    minMaxLoc(hist, &vmin, &vmax);
    for (int i= 0; i<256; i++) {
        rectangle(histograma, Point(3+i*391/256, 185), Point(3+(i+1)*391/256, 185 - hist.at<float>(i)*182/vmax), CV_RGB(canal==2?255:0,
                                                                                                                        canal==1?255:0,
                                                                                                                        canal==0?255:0), -1);
    }
    crear_nueva(nres, histograma);
        //qDebug("Celda %d: %g", i, hist.at<float>(i));

}

//---------------------------------------------------------------------------

void media_ponderada (int nf1, int nf2, int nueva, double peso)
{
    assert(nf1>=0 && nf1<MAX_VENTANAS && foto[nf1].usada);
    assert(nf2>=0 && nf2<MAX_VENTANAS && foto[nf2].usada);
    assert(nueva>=0 && nueva<MAX_VENTANAS && !foto[nueva].usada);
    Mat img= foto[nf1].img.clone();
    Mat cop;
    resize(foto[nf2].img, cop, img.size());
    addWeighted(img, peso, cop, 1.0-peso, 0, img);
    crear_nueva(nueva, img);
}

//

void copiar_a_nueva (int nfoto, int nres)
{
    Mat nueva = foto[nfoto].img(foto[nfoto].roi);
    crear_nueva(nres, nueva);
}

//---------------------------------------------------------------------------

void ver_ajuste_lineal(int nfoto, double pmin, double pmax, bool guardar)
{
    //Convertimos a grises
    Mat gris, hist;
    cvtColor(foto[nfoto].img, gris, COLOR_RGB2GRAY);

    //Calcular el histograma
    int canales[1]= {0};
    int bins[1]= {256};
    float rango[2]= {0, 256};
    const float *rangos[]= {rango};
    calcHist(&gris, 1, canales, noArray(), hist, 1, bins, rangos);

    normalize(hist, hist, 100, 0, NORM_L1);

    int m, M;
    double acum;
    for(m=0, acum=0; m < 256 && acum < pmin; m++) {
        acum += hist.at<float>(m);
    }
    for(M = 255, acum = 0; M >= 0 && acum < pmax; M--) {
        acum += hist.at<float>(M);
    }

    //Comprobamos por si se cruzan
    if(M <= m)
        M = m + 1;

    double alfa = 255.0 / (M - m);
    double beta = -m * 255.0 / (M -m);

    Mat res;
    foto[nfoto].img.convertTo(res, CV_8UC3, alfa, beta);

    imshow(foto[nfoto].nombre, res);
    if(guardar) {
        res.copyTo(foto[nfoto].img);
        foto[nfoto].modificada = true;
    }
}

//---------------------------------------------------------------------------

void ver_bajorrelieve (int nfoto, int nres, double grado, double angulo, int tam, int textura, bool guardar) {

    QString nombres[4] = {":/imagenes/arena.jpg", ":/imagenes/cielo.jpg", ":/imagenes/gris.png", ":/imagenes/madera.jpg"};

    QImage imq= QImage(nombres[textura]);
    Mat img(imq.height(),imq.width(),CV_8UC4,imq.scanLine(0));
    cvtColor(img, img, COLOR_RGBA2RGB);
    imshow("Imagen", img);

    Mat gris;
    cvtColor(foto[nfoto].img, gris, COLOR_BGR2GRAY);

    Mat rotada;
    rotar_angulo(gris, rotada, angulo, 1.0, 1);

    Mat sobel;

    double factor = grado /pow(4, tam-3);

    Sobel(rotada, sobel, -1, 1, 0, tam, factor, 128, BORDER_REFLECT);

    rotar_angulo(sobel, rotada, -angulo, 1.0, 0);

    Rect roi((rotada.cols-gris.cols)/2, (rotada.rows-gris.rows)/2, gris.cols, gris.rows);

    gris = rotada(roi);

    cvtColor(gris, gris, COLOR_GRAY2RGB);
    resize(img, img, gris.size(), 0, 0, INTER_CUBIC);

    addWeighted(img, 1.0, gris, 1.0, -128, img);

    imshow("Bajorrelieve", img);
    if (guardar) {

        crear_nueva(nres, img);
    }

}

//---------------------------------------------------------------------------

void escala_color(int nfoto, int nres) {
    Mat gris;
    cvtColor(foto[nfoto].img, gris, COLOR_BGR2GRAY);

    cvtColor(gris, gris, COLOR_GRAY2BGR);
    Mat lut(256, 1, CV_8UC3);

    int vr = color_pincel.val[2];
    int vg = color_pincel.val[1];
    int vb = color_pincel.val[0];

    int vgris = (vr+vg+vb/3);

    for(int A=0; A<256; A++) {
        if(A<vgris) {
            lut.at<Vec3b>(A) = Vec3b(vb*A/vgris, vg*A/vgris, vr*A/vgris);
        } else {
            lut.at<Vec3b>(A) = Vec3b(vb+(255-vb)*(A-vgris)/(256-vgris), vg+(255-vg)*(A-vgris)/(256-vgris), (vr+(255-vr)*(A-vgris)/(256-vgris)));
        }
    }

    Mat res;
    LUT(gris, lut, res);
    crear_nueva(nres, res);
}

//---------------------------------------------------------------------------

void ver_pinchar_estirar(int nfoto, int cx, int cy, double radio, double grado, bool guardar) {
    Mat S(foto[nfoto].img.size(), CV_32FC1);
    double r2 = radio * radio;
    for(int y = 0; y < S.rows; y++) {
        for(int x = 0; x < S.cols; x++) {
            S.at<float>(y,x) = exp(-((x-cx)*(x-cx)+(y-cy)*(y-cy))/r2);
        }
    }
    //imshow("S",S);
    Mat Gx, Gy;
    Sobel(S, Gx, -1, 1, 0, 3, grado);
    Sobel(S, Gy, -1, 0, 1, 3, grado);

    multiply(S, Gx, Gx);
    multiply(S, Gy, Gy);

    for(int y = 0; y < S.rows; y++) {
        for(int x = 0; x < S.cols; x++) {
            Gx.at<float>(y,x) += x;
            Gy.at<float>(y,x) += y;
        }
    }

    Mat res;
    remap(foto[nfoto].img, res, Gx, Gy, INTER_CUBIC, BORDER_REFLECT);
    imshow("Pinchar/Estirar", res);
    if(guardar) {
        res.copyTo(foto[nfoto].img);
        foto[nfoto].modificada = true;
        mostrar(nfoto);
    }
}

//---------------------------------------------------------------------------

void ver_matiz_sat_lum(int nfoto, int matiz, double sat, double lum, bool guardar) {
    Mat hls;
    cvtColor(foto[nfoto].img, hls, COLOR_BGR2HLS_FULL);

    Mat canales[3];
    split(hls, canales);

    Mat im16;
    canales[0].convertTo(im16, CV_16S, 1, matiz);
    bitwise_and(im16, Scalar(255), im16);
    im16.convertTo(canales[0], CV_8U);
    //canales[0]+=matiz;
    canales[1]*=lum;
    canales[2]*=sat;

    merge(canales, 3, hls);
    Mat res;
    cvtColor(hls, res, COLOR_HLS2BGR_FULL);
    imshow(foto[nfoto].nombre, res);
    if(guardar) {
        res.copyTo(foto[nfoto].img);
        foto[nfoto].modificada = true;
    }
}

//---------------------------------------------------------------------------

void espectro(int nfoto, int nres) {
    Mat canales[3];
    split(foto[nfoto].img, canales);
    for(int i=0; i<3; i++) {
        Mat im32;
        canales[i].convertTo(im32, CV_32F);
        Mat imgdtf;
        dft(im32, imgdtf, DFT_COMPLEX_OUTPUT + DFT_SCALE);
        Mat can2[2];
        split(imgdtf, can2);
        Mat mag;
        magnitude(can2[0], can2[1], mag);
        //imshow("dft", mag);
        //waitKey(0);
        mag.convertTo(canales[i], CV_8U, -255, 255);
    }
    Mat res;
    merge(canales, 3, res);
    //crear_nueva(nres, res);

    Mat res2 = res.clone();
    int H = res.rows;
    int W = res.cols;
    Rect roi1(0, 0, W/2, H/2);
    Rect roi2((W+1)/2, (H+1)/2, W/2, H/2);
    res(roi1).copyTo(res2(roi2));

    roi1 = Rect(W/2, 0, (W+1)/2, H/2);
    roi2 = Rect(0, (H+1)/2, (W+1)/2, H/2);
    res(roi1).copyTo(res2(roi2));

    roi1 = Rect(0 , H/2, W/2, (H+1)/2);
    roi2 = Rect((W+1)/2, 0, W/2, (H+1)/2);
    res(roi1).copyTo(res2(roi2));

    roi1 = Rect(W/2 , H/2, (W+1)/2, (H+1)/2);
    roi2 = Rect(0, 0, (W+1)/2, (H+1)/2);
    res(roi1).copyTo(res2(roi2));

    crear_nueva(nres, res2);
}

//---------------------------------------------------------------------------

void copiar_al_portapapeles(int nfoto) {
    assert(nfoto >= 0 && nfoto < MAX_VENTANAS && foto[nfoto].usada);
    Mat roi = foto[nfoto].img(foto[nfoto].roi);
    cvtColor(roi, roi, COLOR_BGR2RGB); // Convert BGR to RGB
    QImage qimg(roi.data, roi.cols, roi.rows, roi.step, QImage::Format_RGB888);
    QClipboard *clipboard = QGuiApplication::clipboard();
    clipboard->setImage(qimg);
}

//---------------------------------------------------------------------------


void ver_histograma_2d(int nfoto, int canal1, int canal2, int nres, int bins) {
    Mat hist;
    int canales[] = {canal1, canal2};
    int histSize[] = {bins, bins};
    float rango[] = {0, 256};
    const float* rangos[] = {rango, rango};

    calcHist(&foto[nfoto].img, 1, canales, noArray(), hist, 2, histSize, rangos, true, false);
    normalize(hist, hist, 0, 255, NORM_MINMAX);

    Mat histImage = Mat::zeros(bins, bins, CV_8UC3);
    for (int i = 0; i < bins; i++) {
        for (int j = 0; j < bins; j++) {
            float binVal = hist.at<float>(i, j);
            histImage.at<Vec3b>(i, j) = Vec3b::all(binVal);
        }
    }

    resize(histImage, histImage, Size(512, 512), 0, 0, INTER_NEAREST);
    applyColorMap(histImage, histImage, COLORMAP_JET);

    // Add scale values
    int margin = 50;
    Mat histImageWithScale(histImage.rows + margin, histImage.cols + margin, CV_8UC3, Scalar(255, 255, 255));
    histImage.copyTo(histImageWithScale(Rect(margin, 0, histImage.cols, histImage.rows)));

    for (int i = 0; i <= bins; i += bins / 8) {
        int pos = i * 512 / bins;
        putText(histImageWithScale, to_string(i * 256 / bins), Point(margin + pos, histImage.rows + 20), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 0, 0));
        putText(histImageWithScale, to_string(i * 256 / bins), Point(5, histImage.rows - pos), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 0, 0));
    }

    crear_nueva(nres, histImageWithScale);
}

//---------------------------------------------------------------------------

void mostrar_info_imagen(int nfoto) {
    assert(nfoto >= 0 && nfoto < MAX_VENTANAS && foto[nfoto].usada);

    Mat img = foto[nfoto].img;
    int width = img.cols;
    int height = img.rows;
    int depth = img.depth();
    int channels = img.channels();
    size_t memory = img.total() * img.elemSize();

    Scalar mean_color = mean(img);
    Vec3b mean_color_bgr(mean_color[0], mean_color[1], mean_color[2]);

    QString info = QString("Tamaño: %1x%2\nProfundidad: %3\nCanales: %4\nMemoria: %5 bytes\nColor medio (BGR): [%6, %7, %8]")
                   .arg(width)
                   .arg(height)
                   .arg(depth)
                   .arg(channels)
                   .arg(memory)
                   .arg(mean_color_bgr[0])
                   .arg(mean_color_bgr[1])
                   .arg(mean_color_bgr[2]);

    QMessageBox::information(w, "Información de la imagen", info);

    Mat color_representation(100, 100, CV_8UC3, mean_color_bgr);
    imshow("Color medio", color_representation);
}

//---------------------------------------------------------------------------

void ver_perspectiva(int norig, int ndest, Point2f ptorig[4], Point2f ptdest[4], bool guardar) {
    Mat M = getPerspectiveTransform(ptorig, ptdest);
    Mat res = foto[ndest].img.clone();
    warpPerspective(foto[norig].img, res, M, res.size(), INTER_CUBIC, BORDER_TRANSPARENT);

    if(guardar) {
        res.copyTo(foto[ndest].img);
        foto[ndest].modificada = true;
    }

    for(int i=0; i<4; i++) {
        line(res, ptdest[i], ptdest[(i+1)%4], CV_RGB(255,255,255), 2);
    }
    for(int i=0; i<4; i++) {
        circle(res,  ptdest[i], 8, CV_RGB(255,255,255), -1);
        circle(res, ptdest[i], 6, CV_RGB(0,255,0), -1);
    }

    imshow("Perspectiva", res);
}

//---------------------------------------------------------------------------

    string Lt1(string cadena)
{
    QString temp= QString::fromUtf8(cadena.c_str());
    return temp.toLatin1().data();
}
