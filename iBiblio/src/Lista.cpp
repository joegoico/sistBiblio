#include "Lista.h"
#include "Libro.h"
#include "string.h"
#include<iostream>

using namespace std;
Lista::Lista()
{
    this->pAnio=nullptr;
    this->CursorPublico =nullptr;
}

void Lista::Primero(){
    this->CursorPublico = this->pAnio;
}

void Lista::vincularListaVendidos(Libro elemento){
    nodo *nuevoNodo= new nodo;
    nuevoNodo->elemento=elemento;

    nodo *aux1=this->pAnio;
    nodo *aux2;

    while((aux1!=nullptr) && (aux1->elemento.getVendidos()>elemento.getVendidos())){
        aux2=aux1;
        aux1=aux1->sig;
    }
    if (this->pAnio==aux1){
        this->pAnio=nuevoNodo;
    }
    else{
        aux2->sig=nuevoNodo;
    }
    nuevoNodo->sig=aux1;
}

const bool Lista::existeLibro(string titulo){
    nodo *aux;
    aux=this->pAnio;
    bool coincide=false;
    while ((aux!=NULL) and (!coincide)){
            coincide=aux->elemento.comparar(titulo);
            aux=aux->sig;
    }
   return coincide;
}
void Lista::vincularPorAnio(Libro elemento){
    nodo *nuevoNodo= new nodo;
    nuevoNodo->elemento=elemento;

    nodo *aux1=this->pAnio;
    nodo *aux2;

    while((aux1!=nullptr) && (aux1->elemento.getAnio()<elemento.getAnio())){
        aux2=aux1;
        aux1=aux1->sig;
    }
    if (this->pAnio==aux1){
        this->pAnio=nuevoNodo;
    }
    else{
        aux2->sig=nuevoNodo;
    }
    nuevoNodo->sig=aux1;
}
Lista::~Lista()
{
    //dtor
}
