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
bool Libro::comparar(string tBuscado){
    int i=0, n=0;
    bool coincide=true;
    while((i<this->titulo.size()) and (n<tBuscado.size()) and coincide){
        if(tBuscado[n]=='*'){
            while((i<this->titulo.size()) and (this->titulo[i]!=' '))
                i++;
            n++;
        }
        else if((tBuscado[n]==this->titulo[i]) or (tBuscado[n]=='?')){
            n++;
            i++;
        }
        else
            coincide=false;
    }
    return coincide;
}
const void Libro::imprimir(){
        cout << "   ISBN: " << this->isbn << endl;
        cout << "   TITULO: " << this->titulo<< endl;
        cout << "   AUTOR: " << this->autor<< endl;
        cout << "   EDITORIAL: " << this->editorial<<endl;
        cout << "   AñO EDICION: " << this->anio<< endl;
        cout << "   NÚMERO EDICION: " << this->numero_edicion << endl;
        cout << "   GENEROS: " << this->listaGeneros <<endl;
        cout << "   PAGINAS: " << this->paginas <<endl;
        cout << "   EJEMPLARES VENDIDOS: " << this->cant_vendidos <<endl;
        cout << "   PRECIO: " << this->precio <<endl<<endl;
}
bool Libro::compararGeneros(string generoUsuario){
    int i=1, n=0;
    bool coincide=false;
    while((i<this->listaGeneros.size()) and (n<generoUsuario.size()) and (coincide==false)){
        if(this->listaGeneros[i]==generoUsuario[n]){
            i++;
            n++;
            if(((this->listaGeneros[i]== '|') or (this->listaGeneros[i]== ']'))  and (n==generoUsuario.size()))
                coincide=true;
        }
        else {
            n=0;
            while (this->listaGeneros[i]!='|' and this->listaGeneros[i]!=']')
                i++;
            i++;
        }
    }
    return coincide;
}
Libro::~Libro()
{
    //dtor
}
