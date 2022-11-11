#ifndef LISTA_H
#define LISTA_H
#include<iostream>
#include "Libro.h"

using namespace std;
class Lista
{
    private:
        struct nodo {
            Libro elemento;
            nodo *sig;
        };
        nodo *pAnio;
    public:
        Lista();
        void imprimirVendidos();
        void vincularListaVendidos(Libro elemento);
        void masVendidos(string genero);
        void vincularPorAnio(Libro elemento);
        const bool existeLibro(string titulo);
        const void imprimir(Libro listaLibros );
        const void listarPorRango(int inicio,int fin);
        virtual ~Lista();
};

#endif // LISTA_H
