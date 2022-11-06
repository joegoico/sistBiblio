#ifndef LISTAGENEROS_H
#define LISTAGENEROS_H
#include<iostream>

using namespace std;
class listaGeneros
{
    public:
        listaGeneros();
        void agregarGenero(string genero);
        void listarGeneros(string titulo);
        virtual ~listaGeneros();
    private:
        struct nodoGeneros{
            listaGeneros *sig;
            string  generos;
        };
        nodoGeneros *cursor;
};

#endif // LISTAGENEROS_H
