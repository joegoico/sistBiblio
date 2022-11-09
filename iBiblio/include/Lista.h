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
        void vincularPorAnio(Libro elemento, Lista &listalibros);
        bool existeLibro(string titulo);
        void imprimir(Libro listaLibros );
        void listarPorRango(int inicio,int fin,Lista elemento);
        virtual ~Lista();
};

#endif // LISTA_H
