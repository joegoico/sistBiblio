#include "LIBRO.h"
#include<iostream>

using namespace std;
LIBRO::LIBRO()
{
    //ver como hacer para importar los libros
}
LIBRO::LIBRO(string t, string a, string e, int an, int ne, int p, int v, int pre, double ISBN){
    this->isbn=ISBN;
    this->titulo=t;
    this->autor=a;
    this->editorial=e;
    this->anio=an;
    this->numero_edicion=ne;
    this->paginas=p;
    this->cant_vendidos=v;
    this->precio=pre;
}
string LIBRO::getTitulo(){
    return this->titulo;
}
string LIBRO::getAutor(){
    return this->autor;
}
string LIBRO::getEditorial(){
    return this->editorial;
}
int LIBRO::getAnio(){
    return this->anio;
}
int LIBRO::getNumeroEdicion(){
    return this->numero_edicion;
}
int LIBRO::getPaginas(){
    return this->paginas;
}
int LIBRO::getVendidos(){
    return this->cant_vendidos;
}
int LIBRO::getPrecio() {
    return this->precio;
}
/*void LIBRO::getListaGeneros(){

}*/
double LIBRO::getISBN(){
    return this->isbn;
}
LIBRO::~LIBRO()
{
    //dtor
}
