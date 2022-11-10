#include "Lista.h"
#include "Libro.h"
#include<string>
#include<iostream>

using namespace std;
Lista::Lista()
{
    this->pAnio=nullptr;
}
void Lista::imprimirVendidos(Lista listavendidos){
    nodo *aux;
    aux=this->pAnio;
    for (int i=0;i<10;i++){
        listavendidos.imprimir(aux->elemento);
    }
}
void Lista::vincularListaVendidos(Libro elemento,Lista &listavendidos){
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
bool compararGeneros(string generoLista, string generoUsuario){
    int i=1, n=0;
    bool coincide=false;
    while((i<generoLista.size()) and (n<generoUsuario.size()) and (coincide==false)){
        if(generoLista[i]==generoUsuario[n]){
            i++;
            n++;
        }
        else if(((generoLista[i]== '|') or (generoLista[i]== ']'))  and (n=generoUsuario.size()))
            coincide=true;
        else if (generoLista[i]!=generoUsuario[n]){
            n=0;
            while (generoLista[i]!='|')
                i++;
            i++;
        }
    }
    return coincide;
}
void Lista::masVendidos(Lista listalibros, string genero){
    nodo *aux;
    aux=this->pAnio;
    Lista listaVendidos;
    while (aux!=nullptr){
        if (compararGeneros(aux->elemento.getListaGeneros(),genero))
            vincularListaVendidos(aux->elemento,listaVendidos);
        aux=aux->sig;
    }
    //listaVendidos.imprimirVendidos(listalibros);
}
const void Lista::listarPorRango(int inicio,int fin,Lista elemento){
    nodo *aux;
    aux=this->pAnio;
    while ((aux!=NULL) and (aux->elemento.getAnio()<=fin)) {
        if (aux->elemento.getAnio()>=inicio){
            elemento.imprimir(aux->elemento);
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
    while ((aux!=NULL) and (coincide==false)){
            coincide=compararTitulos(aux->elemento.getTitulo(),titulo);
            aux=aux->sig;
    }
   return coincide;
}
void Lista::vincularPorAnio(Libro elemento,Lista &listalibros){
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
