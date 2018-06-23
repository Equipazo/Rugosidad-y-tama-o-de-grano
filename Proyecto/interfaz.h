#ifndef INTERFAZ_H
#define INTERFAZ_H
#include<QFileDialog>
#include<QLabel>
#include <QMainWindow>
#define PGMHANDLE_H

namespace Ui {
class interfaz;
}

class interfaz : public QMainWindow
{
    Q_OBJECT

public:
    QString fileName;
    FILE *fichero_1;
    FILE *fichero_2;
    FILE *fichero;
    FILE *fichero3;
    char nombre_2[60];
    char nombre[60];
    char nombre3[60];
    int  **matriz;
    QPixmap pix();
    QPixmap pix1();
    QPixmap pix3();
    void invertir();
    void escala();
    void analisis_matriz();
    interfaz(QWidget *parent = 0);

    ~interfaz();

private:
    Ui::interfaz *ui;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_5_clicked();
};

#endif // INTERFAZ_H
