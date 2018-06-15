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
    QPixmap pix("/home/esmeralda/Escritorio/nanotec.png");
    ui->label->setPixmap(pix);
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
