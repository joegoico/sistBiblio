#ifndef LIBRO_H
#define LIBRO_H
#include"LISTA.h"
#include<iostream>

using namespace std;
class LIBRO
{
    public:
        LIBRO();
        LIBRO(string titulo, string autor, string editorial, int anio, int numeroEdicion, int paginas, int vendidos, int precio, double ISBN);
        string getTitulo() ;
        string getAutor() ;
        string getEditorial() ;
        int getAnio() ;
        int getNumeroEdicion() ;
        int getPaginas() ;
        int getVendidos() ;
        int getPrecio() ;
        void getListaGeneros() ;
        double getISBN() ;
        virtual ~LIBRO();
    private:
            double isbn;
            string titulo,autor, editorial;
            int anio,numero_edicion,paginas,cant_vendidos,precio;
            //LISTA<string> generos;
};

#endif // LIBRO_H
