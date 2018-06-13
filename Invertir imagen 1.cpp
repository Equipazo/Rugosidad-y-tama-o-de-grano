#include <cstdio>
#include <cstdlib>
#include <iostream>
#include<string.h>
using namespace std;
int main()
{
    FILE *fichero_1;
    FILE *fichero_2;
    int *matriz;
    char dato[500];
    char datoP[500];
    unsigned int t_po;
    int c,i;
    char nombre[60]="/home/esmeralda/Escritorio/nano.pgm";
    char nombre_2[60]="/home/esmeralda/Escritorio/inversa.pgm";
    fichero_1 = fopen(nombre, "r" );
    fichero_2 = fopen(nombre_2, "w" );


    if(!fichero_1) {
        perror("fallo al abrir");
        return EXIT_FAILURE;
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


        cout<<*(matriz)<<endl;

    }

    if (ferror(fichero_1))
        puts("I/O error al leer");
    else if (feof(fichero_1))
        puts("fin satisfactorio");

        fclose (fichero_2);
        fclose(fichero_1);
}

