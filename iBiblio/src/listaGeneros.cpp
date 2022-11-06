#include "listaGeneros.h"

listaGeneros::listaGeneros()
{
    //ctor
}
/*
void listaGeneros::agregarGenero(string genero){
    nodoGeneros *aux;
    aux==this->cursor;
    if(aux==NULL){
        aux->generos=genero;
        aux->sig=NULL;
    }
    else{
        while(aux->sig!=NULL){
            aux=aux->sig;
        }
        nodoGeneros *generoAagregar;
        generoAagregar->generos=genero;
        generoAagregar->sig=aux->sig;
        aux->sig=generoAagregar;
    }
}
void listaGeneros::listarGeneros(string titulo){
    nodoGeneros *aux;
    aux=this->cursor;
    while(aux->sig!= NULL){
        cout<<aux->generos<<" | ";
        aux=aux->sig;
    }
}*/
listaGeneros::~listaGeneros()
{
    //dtor
}
