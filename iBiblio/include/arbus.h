#ifndef ARBUS_H
#define ARBUS_H
#include"LIBRO.h"
class arbus
{
    public:
        arbus();
        void agregarLibro(LIBRO libro);
        bool existeLibro(string tittle, arbus *arbol);
        virtual ~arbus();
    private:
        struct nodoLibro{
            LIBRO libro;
            nodoLibro *mayor,*menor;
        };
        nodoLibro *raiz;
};

#endif // ARBUS_H
