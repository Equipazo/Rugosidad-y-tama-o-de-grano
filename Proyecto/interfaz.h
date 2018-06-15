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
    void invertir();
    char nombre_2[60];
    QPixmap pix();
    interfaz(QWidget *parent = 0);

    ~interfaz();
/*protected:
    void changeEvent(QEvent *e);*/
private:
    Ui::interfaz *ui;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();
};

#endif // INTERFAZ_H
