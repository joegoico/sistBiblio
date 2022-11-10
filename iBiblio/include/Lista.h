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
        void imprimirVendidos(Lista listavendidos);
        void vincularListaVendidos(Libro elemento,Lista &listavendidos);
        void masVendidos(Lista listalibros, string genero);
        void vincularPorAnio(Libro elemento,Lista &listalibros);
        const bool existeLibro(string titulo);
        const void imprimir(Libro listaLibros );
        const void listarPorRango(int inicio,int fin,Lista elemento);
        virtual ~Lista();
};

#endif // LISTA_H
