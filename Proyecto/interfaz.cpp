#include "interfaz.h"
#include "ui_interfaz.h"
#include <QtCore/QBuffer>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include<string.h>
#include<math.h>
using namespace std;


interfaz::interfaz(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::interfaz)
{
    ui->setupUi(this);
    QPixmap pix(":/img/img/nanotec.png");
    ui->label->setPixmap(pix);
    QPixmap pix2(":/img/img/nanotec2.jpg");
    ui->label_2->setPixmap(pix2);
    QPixmap pix3(":/img/img/nanotec2.jpg");
    ui->label_3->setPixmap(pix3);
}

interfaz::~interfaz()
{
    ///cerrar el archivo!!!*****************************
        if(!fclose(fichero_1)){
            printf("\narchivo cerrado\n");
        }else{
            printf("error: no se pudo cerrar el archivo");
        }
           if(!fclose(fichero_2)){
            printf("\narchivo cerrado\n");
        }else{
            printf("error: no se pudo cerrar el archivo");
        }
    delete ui;
}

void interfaz::on_pushButton_clicked()
{
    QFileDialog dialog(this);
    dialog.setNameFilter(tr("Imagenes (*.png *jpeg *.xpm *.pgm"));
    dialog.setViewMode(QFileDialog::Detail);
     fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Images"),"/home/esmeralda/Escritorio/", tr("Image Files (*.png *.jpeg *.bmp *.pgm)"));
if(!fileName.isEmpty())
{
    QImage image(fileName);
    ui->label->setPixmap(QPixmap::fromImage(image));
}
}
void interfaz::on_pushButton_2_clicked()
{
    invertir();
}
void interfaz::invertir()
{

    int *matriz;
    char dato[500];
    char datoP[500];
    unsigned int t_po;
    int c,i;
   // char nombre[60]="/home/esmeralda/Escritorio/nano.pgm";
    const char* nombre = fileName.toLatin1().data();
    char nombre_2[60]="/home/esmeralda/Escritorio/inversa.pgm";
    fichero_1 = fopen(nombre, "r" );
    fichero_2 = fopen(nombre_2, "w" );


    if(!fichero_1) {
        perror("fallo al abrir");
    }

    matriz=&c;
    cout<<&matriz<<endl;
    i=0;
    fprintf(fichero_2, "%s","P");
    while ((c = fgetc(fichero_1)) != EOF) {

       i++;
       putchar(c);
       fscanf(fichero_1, "%s", &dato);

       if(i>4){
       t_po=atoi(dato);
       t_po=255 - t_po;
       sprintf(datoP,"%d",t_po);
       }
       else{

       sprintf(datoP,"%s",dato);

       }

       fprintf(fichero_2, "%s",datoP);
       fprintf(fichero_2, "%s","\n");

    }

    if (ferror(fichero_1))
        puts("I/O error al leer");
    else if (feof(fichero_1))
        puts("fin satisfactorio");

        fclose (fichero_2);
        fclose(fichero_1);
        QPixmap pix1(nombre_2);
    ui->label_2->setPixmap(pix1);
}
void interfaz::on_pushButton_4_clicked()
{
  connect(ui->pushButton_4,SIGNAL(clicked()),qApp,SLOT(quit()));
}
void interfaz::on_pushButton_5_clicked()
{
  escala();
}
void interfaz::escala(){

    char dato[100];
    char datoP[100];
    unsigned int t_po;
    int c,i;
    const char* nombre = fileName.toLatin1().data();
    char nombre_2[60]="/home/esmeralda/Escritorio/escala.pgm";
    fichero_1 = fopen(nombre, "r" );
    fichero_2 = fopen(nombre_2, "w" );

    if(!fichero_1) {
        perror("fallo al abrir");
    }

    i=0;
    fprintf(fichero_2, "%s","P");
    while ((c = fgetc(fichero_1)) != EOF) {

       i++;
       putchar(c);
       fscanf(fichero_1, "%s", &dato);

       if(i>4){
       t_po=atoi(dato);

       if(t_po<102){
           t_po=0;
       }
       if(t_po>101){
           t_po=255;
       }
       sprintf(datoP,"%d",t_po);
       }
       else{
       sprintf(datoP,"%s",dato);
       }
       fprintf(fichero_2, "%s",datoP);
       fprintf(fichero_2, "%s","\n");
    }

    if (ferror(fichero_1))
        puts("I/O error al leer");
    else if (feof(fichero_1))
        puts("fin satisfactorio");

        fclose (fichero_2);
        fclose(fichero_1);
        QPixmap pix1(nombre_2);
    ui->label_3->setPixmap(pix1);
}
void interfaz::on_pushButton_6_clicked()
{
system("xdg-open /home/esmeralda/Escritorio/Binaria.txt");
}
void interfaz::on_pushButton_7_clicked()
{
    system("xdg-open /home/esmeralda/Escritorio/ATSM.jpg");
}
void interfaz::on_pushButton_3_clicked()
{
    analisis_matriz();
}
void interfaz::analisis_matriz()
{
    int alto=0;
    int ancho=0;
    QPixmap pix1("/home/esmeralda/Escritorio/escala.pgm");
    alto=pix1.height();
    ancho=pix1.width();
    char nombre[60]="/home/esmeralda/Escritorio/escala.pgm";
    char nombre3[60]="/home/esmeralda/Escritorio/Binaria.txt";
    char dato[100];
    char datoP[100];
    unsigned int t_po;
    int c,i,j,k;
    int zeros=0;
    fichero = fopen(nombre, "r" );
    fichero3 = fopen(nombre3, "w" );

    if(!fichero) {
    perror("fallo al abrir");
    }

    int **matriz = new int*[ancho];
    for (int k = 0; k < ancho; k++){
        matriz[k] = new int[alto];}

    i=0;
    while ((c = fgetc(fichero)) != EOF){
       i++;
       fscanf(fichero, "%s", &dato);
       if(i>4){
       t_po=atoi(dato);
       if(k<ancho){
            if(t_po==255)
            {
              matriz[k][j]=1;
            }
            else
            {
              matriz[k][j]=0;
            zeros++;
            }

            if(j<alto){
            sprintf(datoP,"%d",matriz[k][j]);
            fprintf(fichero3, "%s",datoP);
            fprintf(fichero3, "%s"," ");
            k++;
            }}

        else{
            if(j<alto){
                j++;
            k=0;}
            if(t_po==255)
            {
              matriz[k][j]=1;
            }
            else
            {
              matriz[k][j]=0;
              zeros++;
            }
             if(j<alto){
             sprintf(datoP,"%d",matriz[k][j]);
             fprintf(fichero3, "%s","\n");
             fprintf(fichero3, "%s",datoP);
             fprintf(fichero3, "%s"," ");
             k++;}

             else{fclose (fichero3);
             }

             }
       }
       else{
           k=0;
           j=0;
       }

    }
    int z=0;
    int p=0;
    float granos=0;

    int x=0,y=0,q=0,w=0,e=0,r=0;
    cout << "Mostrar la matriz" << endl;
    for ( x=0; x<alto; x++){

        for (y=0; y<ancho; y++){
            cout << matriz[y][x] << " ";
 p=0;
        if (matriz[y][x]==0){

            e=x+8; r=y+8;
            if(e>alto ){e=alto;}
            if(r>ancho){r=ancho;}
            for ( q=x; q<e; q++) {

                for ( w=y; w<r; w++){
                    if(matriz[w][q]==0){
                        z=1;
                    }
                    else{z=0;}
                    p=p+z;

}}
            if(p>60){granos++;
            y=y+8;
            }
            else if(p<61){granos=granos+0;}
        }
    else{z=0;}
        }}

granos=granos/4;
cout<<granos<<endl;
cout<<zeros<<endl;
float N, tama;
N= granos/((alto*ancho)/(25.4*25.4));

tama=(log(N)/log(2))+ 1;


//FUNCION TAMAÑO REAL
int pix;
QString escala=ui->lineEdit->text();
switch (escala.toInt()) {
case 100:
    pix=60;
    break;
case 200:
    pix=61;
    break;
case 50:
    pix=66;
    break;
case 10:
    pix=39;
    break;
}

float area, pixlong, longitud;
area=zeros/granos;
pixlong=sqrt(area);
longitud=(pixlong*escala.toInt())/pix;

    if (ferror(fichero))
        puts("I/O error al leer");
    else if (feof(fichero))
        puts("fin satisfactorio");


    fclose(fichero);
    delete [] matriz;
    ui->lcdNumber->display(granos);
    ui->lcdNumber_2->display(tama);
    ui->lcdNumber_3->display(longitud);
}




