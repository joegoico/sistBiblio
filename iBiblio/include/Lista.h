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
        void Primero();
        void vincularListaVendidos(Libro elemento);
        void vincularPorAnio(Libro elemento);
        const bool existeLibro(string titulo);
        nodo *CursorPublico;
        virtual ~Lista();
};

#endif // LISTA_H
