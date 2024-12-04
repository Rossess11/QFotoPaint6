#include "perspectiva.h"
#include "ui_perspectiva.h"
#include "imagenes.h"

int pr_norig, pr_ndest;
Point2f pr_pt[2][4];
int pr_corresp[MAX_VENTANAS];

void pintar_origen(Mat imagen) {
    for(int i=0; i<4; i++) {
        line(imagen, pr_pt[0][i], pr_pt[0][(i+1)%4], CV_RGB(255,255,255), 2);
    }
    for(int i=0; i<4; i++) {
        circle(imagen,  pr_pt[0][i], 8, CV_RGB(255,255,255), -1);
        circle(imagen, pr_pt[0][i], 6, CV_RGB(255,0,0), -1);
    }
}

void pr_callback(int evento, int x, int y, int flags, void *pt) {
    int pos = (long long) pt;

    if(flags==EVENT_FLAG_LBUTTON) {
        int mindist = 400;
        int minpt;
        for(int i=0; i<4; i++) {
            int dist = abs(x-pr_pt[pos][i].x) + abs(y-pr_pt[pos][i].y);
            if(dist<mindist) {
                mindist = dist;
                minpt = i;
            }
        }
        if(mindist<400) {
            pr_pt[pos][minpt] = Point2f(x, y);
            ver_perspectiva(pr_norig, pr_ndest, pr_pt[0], pr_pt[1]);
        }

        if(pos==0) {
            Mat clon = foto[pr_norig].img.clone();
            pintar_origen(clon);
            imshow("Imagen de origen", clon);
        }
    }
}

Perspectiva::Perspectiva(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Perspectiva)
{
    ui->setupUi(this);
    for (int i= 0, pos= 0; i<MAX_VENTANAS; i++) {
        if (foto[i].usada) {
            ui->listWidget->addItem(QString::fromStdString(foto[i].nombre));
            ui->listWidget_2->addItem(QString::fromStdString(foto[i].nombre));
            pr_corresp[pos++]= i;
        }
    }
    pr_ndest = foto_activa();
    pr_norig = pr_corresp[0] == pr_ndest ? pr_corresp[1] : pr_corresp[0];
    // Mejora

    int w = foto[pr_norig].img.cols;
    int h = foto[pr_norig].img.rows;
    pr_pt[0][0] = Point2f(0, 0);
    pr_pt[0][1] = Point2d(w, 0);
    pr_pt[0][2] = Point2f(w, h);
    pr_pt[0][3] = Point2f(0, h);

    w = foto[pr_ndest].img.cols;
    h = foto[pr_ndest].img.rows;
    pr_pt[1][0] = Point2f(w*0.1, h*0.1);
    pr_pt[1][1] = Point2d(w*0.9, 0*0.1);
    pr_pt[1][2] = Point2f(w*0.9, h*0.9);
    pr_pt[1][3] = Point2f(w*0.1, h*0.9);

    Mat clon = foto[pr_norig].img.clone();
    pintar_origen(clon);

    imshow("Imagen de origen", foto[pr_norig].img);
    ver_perspectiva(pr_norig, pr_ndest, pr_pt[0], pr_pt[1]);

    setMouseCallback("Imagen de origen", pr_callback, (void*)0);
    setMouseCallback("Perspectiva", pr_callback, (void*)1);
}

Perspectiva::~Perspectiva()
{
    delete ui;
}

void Perspectiva::on_listWidget_currentRowChanged(int currentRow)
{
    int W1 = foto[pr_norig].img.cols;
    int H1 = foto[pr_norig].img.rows;

    pr_norig = pr_corresp[currentRow];

    double W2 = foto[pr_norig].img.cols;
    double H2 = foto[pr_norig].img.rows;
    for(int i= 0; i<4; i++) {
        pr_pt[0][i].x*=W2/W1;
        pr_pt[0][i].y*=H2/H1;
    }

    Mat clon = foto[pr_norig].img.clone();
    pintar_origen(clon);
    imshow("Imagen de origen", clon);
    ver_perspectiva(pr_norig, pr_ndest, pr_pt[0], pr_pt[1]);
}


void Perspectiva::on_listWidget_2_currentRowChanged(int currentRow)
{
    pr_ndest = pr_corresp[currentRow];
    ver_perspectiva(pr_norig, pr_ndest, pr_pt[0], pr_pt[1]);
}


void Perspectiva::on_Perspectiva_accepted()
{
    ver_perspectiva(pr_norig, pr_ndest, pr_pt[0], pr_pt[1], true);
    destroyWindow("Imagen de origen");
    destroyWindow("Perspectiva");
}


void Perspectiva::on_Perspectiva_rejected()
{
    destroyWindow("Imagen de origen");
    destroyWindow("Perspectiva");
}

//Callback de perspctiva hacer

