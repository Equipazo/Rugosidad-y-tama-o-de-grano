#ifndef INTERFAZ_H
#define INTERFAZ_H
#include<QFileDialog>
#include<QLabel>
#include <QMainWindow>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include<string.h>

namespace Ui {
class interfaz;
}

class interfaz : public QMainWindow
{
    Q_OBJECT

public:
    interfaz(QWidget *parent = 0);
    ~interfaz();
/*protected:
    void changeEvent(QEvent *e);*/
private:
    Ui::interfaz *ui;

private slots:
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

};

#endif // INTERFAZ_H
