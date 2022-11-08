#include "Lista.h"
#include "Libro.h"
Lista::Lista()
{
    this->pAnio=NULL;
}
/*void Lista::listarPorRango(int inicio,int fin,Lista elemento){
    nodo *aux;
    aux=this->pAnio;
    while ((aux!=NULL) and (aux->elemento.getAnio()<=fin)) {
        if (aux->elemento.getAnio()>=inicio)
            elemento.imprimir();
        else
            aux=aux->sig;
    }
}*/
/*bool Lista::existeLibro(string titulo){
    nodo *aux;
    aux=pAnio;
    while ((aux!=NULL) and (aux->elemento.getTitulo()!= titulo)){
        aux=aux->sig;
    }
    if (aux->elemento.getTitulo()== titulo)
        return true;
    else
        return false;
}*/
void Lista::vincularPorAnio(Libro elemento){
    if(this->pAnio==NULL){
        //new(pAnio);
        this->pAnio->elemento=elemento;
        this->pAnio->sig=NULL;
    }
    else if(this->pAnio->elemento.getAnio()>elemento.getAnio()){
        nodo *aux= new nodo;
        aux->elemento=elemento;
        aux->sig=this->pAnio;
        this->pAnio=aux;
        delete(aux);
    }
    else{
        nodo *aux= new nodo;
        aux=this->pAnio;
        while((aux->sig!=NULL) and (aux->sig->elemento.getAnio()<=elemento.getAnio()))
            aux=aux->sig;
        nodo *agregado= new nodo;
        agregado->elemento=elemento;
        agregado->sig=aux->sig;
        aux->sig=agregado;
        delete(aux);
        delete(agregado);
    }
}
void Lista::imprimir(){
    nodo *aux;
    aux=this->pAnio;
    while (aux!=NULL){
        cout << "   ISBN: " << aux->elemento.getISBN() << endl;
        cout << "   TITULO: " << aux->elemento.getTitulo()<< endl;
        cout << "   AUTOR: " << aux->elemento.getAutor()<< endl;
        cout << "   EDITORIAL: " << aux->elemento.getEditorial()<<endl;
        cout << "   AñO EDICION: " << aux->elemento.getAnio()<< endl;
        cout << "   NÚMERO EDICION: " << aux->elemento.getNumeroEdicion()<< endl;
        cout << "   GENEROS: " << aux->elemento.getListaGeneros()<<endl;
        cout << "   PAGINAS: " << aux->elemento.getPaginas() <<endl;
        cout << "   EJEMPLARES VENDIDOS: " << aux->elemento.getVendidos() <<endl;
        cout << "   PRECIO: " << aux->elemento.getPrecio() <<endl<<endl;
        aux=aux->sig;
    }
}
Lista::~Lista()
{
    //dtor
}
