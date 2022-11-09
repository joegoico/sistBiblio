#include "Lista.h"
#include "Libro.h"
Lista::Lista()
{
    this->pAnio=nullptr;
}
void Lista::listarPorRango(int inicio,int fin,Lista elemento){
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
bool Lista::existeLibro(string titulo){
    nodo *aux;
    aux=this->pAnio;
    while ((aux!=NULL) and (aux->elemento.getTitulo()!= titulo)){
        aux=aux->sig;
    }
    if ((aux!=NULL) and (aux->elemento.getTitulo()== titulo))
        return true;
    else
        return false;
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
void Lista::imprimir(Libro libro){
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
