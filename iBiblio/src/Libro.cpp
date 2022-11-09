#include "Libro.h"
#include<iostream>

using namespace std;
Libro::Libro()
{

}
Libro::Libro(string t, string a, string e, int an, string ne, int p, int v, string pre, string ISBN, string lg){
    this->isbn=ISBN;
    this->titulo=t;
    this->autor=a;
    this->editorial=e;
    this->anio=an;
    this->numero_edicion=ne;
    this->paginas=p;
    this->cant_vendidos=v;
    this->precio=pre;
    this->listaGeneros=lg;
}
string Libro::getTitulo(){
    return this->titulo;
}
string Libro::getAutor(){
    return this->autor;
}
string Libro::getEditorial(){
    return this->editorial;
}
int Libro::getAnio(){
    return this->anio;
}
string Libro::getNumeroEdicion(){
    return this->numero_edicion;
}
int Libro::getPaginas(){
    return this->paginas;
}
int Libro::getVendidos(){
    return this->cant_vendidos;
}
string Libro::getPrecio() {
    return this->precio;
}
string Libro::getListaGeneros(){
    return this->listaGeneros;
}
string Libro::getISBN(){
    return this->isbn;
}
Libro::~Libro()
{
    //dtor
}
