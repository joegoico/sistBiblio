#ifndef LIBRO_H
#define LIBRO_H
#include<iostream>

using namespace std;
class Libro
{
    public:
        Libro();
        Libro(string titulo, string autor, string editorial, int anio, string numeroEdicion, int paginas, int vendidos, string precio, string ISBN,string listaGeneros);
        string getTitulo() ;
        string getAutor() ;
        string getEditorial() ;
        int getAnio() ;
        string getNumeroEdicion() ;
        int getPaginas() ;
        int getVendidos() ;
        string getPrecio() ;
        string getListaGeneros() ;
        string getISBN() ;
        virtual ~Libro();
    private:
            string titulo,autor, editorial,precio,numero_edicion,isbn,listaGeneros;
            int anio,paginas,cant_vendidos;
};

#endif // LIBRO_H
