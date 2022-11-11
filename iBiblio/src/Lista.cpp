#include "Lista.h"
#include "Libro.h"
#include "string.h"
#include<iostream>

using namespace std;
Lista::Lista()
{
    this->pAnio=nullptr;
}
void Lista::imprimirVendidos(){
    nodo *aux;
    aux=this->pAnio;
    int i=0;
    while((aux!=nullptr) && i<10){
        this->imprimir(aux->elemento);
        aux=aux->sig;
        i++;
    }
}
bool compararGeneros(string generoLista, string generoUsuario){
    int i=1, n=0;
    bool coincide=false;
    while((i<generoLista.size()) and (n<generoUsuario.size()) and (coincide==false)){
        if(generoLista[i]==generoUsuario[n]){
            i++;
            n++;
            if(((generoLista[i]== '|') or (generoLista[i]== ']'))  and (n==generoUsuario.size()))
                coincide=true;
        }
        else {//if (generoLista[i]!=generoUsuario[n]){   redundante con el if de arriba
            n=0;
            while (generoLista[i]!='|' and generoLista[i]!=']')
                i++;
            i++;
        }
    }
    return coincide;
}
void Lista::vincularListaVendidos(Libro elemento){
    nodo *aux= new nodo;
    if(this->pAnio==NULL){
        aux->elemento=elemento;
        aux->sig=NULL;
        this->pAnio=aux;
    }
    else if(this->pAnio->elemento.getVendidos()<elemento.getVendidos()){
        aux->elemento=elemento;
        aux->sig=this->pAnio;
        this->pAnio=aux;
    }
    else{
        aux=this->pAnio;
        while((aux->sig!=NULL) and (aux->sig->elemento.getVendidos()<=elemento.getVendidos())){
            aux=aux->sig;
        }
        nodo *agregado= new nodo;
        agregado->elemento=elemento;
        agregado->sig=aux->sig;
        aux->sig=agregado;
        delete(agregado);
    }
    delete(aux);
}
void Lista::masVendidos(string genero){
    nodo *aux;
    aux=this->pAnio;
    Lista listaVendidos;

    while (aux!=nullptr){
        if (compararGeneros(aux->elemento.getListaGeneros(),genero))
            listaVendidos.vincularListaVendidos(aux->elemento);
        aux=aux->sig;
    }
    listaVendidos.imprimirVendidos();
}
const void Lista::listarPorRango(int inicio,int fin){
    nodo *aux;
    aux=this->pAnio;
    while ((aux!=NULL) and (aux->elemento.getAnio()<=fin)) {
        if (aux->elemento.getAnio()>=inicio){
            this->imprimir(aux->elemento);
            aux=aux->sig;
        }
        else
            aux=aux->sig;
    }
}
bool compararTitulos(string tLista,string tBuscado){
    int i=0, n=0;
    bool coincide=true;
    while((i<tLista.size()) and (n<tBuscado.size()) and coincide){
        if(tBuscado[n]=='*'){
            while((i<tLista.size()) and (tLista[i]!=' '))
                i++;
            n++;
        }
        else if((tBuscado[n]==tLista[i]) or (tBuscado[n]=='?')){
            n++;
            i++;
        }
        else
            coincide=false;
    }
    return coincide;
}
const bool Lista::existeLibro(string titulo){
    nodo *aux;
    aux=this->pAnio;
    bool coincide=false;
    while ((aux!=NULL) and (!coincide)){
            coincide=compararTitulos(aux->elemento.getTitulo(),titulo);
            aux=aux->sig;
    }
   return coincide;
}
void Lista::vincularPorAnio(Libro elemento){
    nodo *aux= new nodo;
    if(this->pAnio==NULL){
        aux->elemento=elemento;
        aux->sig=NULL;
        this->pAnio=aux;
    }
    else if(this->pAnio->elemento.getAnio()>elemento.getAnio()){
        aux->elemento=elemento;
        aux->sig=this->pAnio;
        this->pAnio=aux;
    }
    else{
        aux=this->pAnio;
        while((aux->sig!=NULL) and (aux->sig->elemento.getAnio()<=elemento.getAnio())){
            aux=aux->sig;
        }
        nodo *agregado= new nodo;
        agregado->elemento=elemento;
        agregado->sig=aux->sig;
        aux->sig=agregado;
        delete(agregado);
    }
    delete(aux);
}
const void Lista::imprimir(Libro libro){
        cout << "   ISBN: " << libro.getISBN() << endl;
        cout << "   TITULO: " << libro.getTitulo()<< endl;
        cout << "   AUTOR: " << libro.getAutor()<< endl;
        cout << "   EDITORIAL: " << libro.getEditorial()<<endl;
        cout << "   AñO EDICION: " << libro.getAnio()<< endl;
        cout << "   NÚMERO EDICION: " << libro.getNumeroEdicion()<< endl;
        cout << "   GENEROS: " << libro.getListaGeneros()<<endl;
        cout << "   PAGINAS: " << libro.getPaginas() <<endl;
        cout << "   EJEMPLARES VENDIDOS: " << libro.getVendidos() <<endl;
        cout << "   PRECIO: " << libro.getPrecio() <<endl<<endl;
}
Lista::~Lista()
{
    //dtor
}
