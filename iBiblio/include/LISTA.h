#ifndef LISTA_H
#define LISTA_H
#include"LIBRO.h"
template <typename T>
class LISTA
{
    public:
        LISTA();
        void agregarLibro(T libro);
        void listarLibrosPorRango(int rango_ing,int rango_sup);
        virtual ~LISTA();
    private:
        struct nodoAnios{
            LISTA  *sig;
            T elemento;
        }; nodoAnios *cursor;
};

#endif // LISTA_H
