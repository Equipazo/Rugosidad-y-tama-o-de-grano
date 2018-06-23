#include "interfaz.h"
#include "ui_interfaz.h"
#include <QtCore/QBuffer>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include<string.h>
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
    cout << "Mostrar la matriz" << endl;
    for (int x=0; x<alto; x++) {

        for (int y=0; y<ancho; y++)
            cout << matriz[y][x] << " ";
    }


    if (ferror(fichero))
        puts("I/O error al leer");
    else if (feof(fichero))
        puts("fin satisfactorio");


    fclose(fichero);
    delete [] matriz;
}
