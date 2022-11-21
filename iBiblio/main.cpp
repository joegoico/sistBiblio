/* ACLARACION: EN LOS CASOS QUE SE QUIERA
BUSCAR UN LIBRO QUE EN EL TITULO CONTENGA UNA Ñ
NO LO ENCONTRARA YA QUE EL ENTORNO NO RECONOCE LA Ñ*/
#include <iostream>
#include <sstream>
#include <fstream>
#include <clocale>
#include "Libro.h"
#include "Lista.h"
#include "string.h"
using namespace std;

/**
 * Abre el archivo según el origen, procesa las líneas del mismo y
 * almacena la información resultante en el contenedor pasado por referencia.
 **/
void listarPorRango(Lista listaDeLibros,int inicio,int fin){
    listaDeLibros.Primero();
    while ((listaDeLibros.CursorPublico!=NULL) and (listaDeLibros.CursorPublico->elemento.getAnio()<=fin)) {
        if (listaDeLibros.CursorPublico->elemento.getAnio()>=inicio){
            listaDeLibros.CursorPublico->elemento.imprimir();
            listaDeLibros.CursorPublico=listaDeLibros.CursorPublico->sig;
        }
        else
            listaDeLibros.CursorPublico=listaDeLibros.CursorPublico->sig;
    }
}
void imprimirVendidos(Lista listaVendidos){
    listaVendidos.Primero();
    int i=0;
    while((listaVendidos.CursorPublico!=nullptr) && i<10){
        listaVendidos.CursorPublico->elemento.imprimir();
        listaVendidos.CursorPublico=listaVendidos.CursorPublico->sig;
        i++;
    }
}
void masVendidos(Lista listaDeLibros,string genero){
    listaDeLibros.Primero();
    Lista listaVendidos;
    while (listaDeLibros.CursorPublico!=nullptr){
        if (listaDeLibros.CursorPublico->elemento.compararGeneros(genero))
            listaVendidos.vincularListaVendidos(listaDeLibros.CursorPublico->elemento);
        listaDeLibros.CursorPublico=listaDeLibros.CursorPublico->sig;
    }
    imprimirVendidos(listaVendidos);
}
void procesar_archivo_entrada(string origen,Lista &listaDeLibros);//, Contenedor & contenedor);
void pedirRango(Lista listaLibros){
    int rangoInf=0, rangoSup=0;
    cout<<"ingrese el rango inferior"<<endl;
    cin>>rangoInf;
    cout<<"ingrese el rango superior"<<endl;
    cin>>rangoSup;
    listarPorRango(listaLibros,rangoInf,rangoSup);
}
void buscarLibro(Lista lista){
    string t,titulo;
    cout<<"Ingrese el titulo que desea buscar:"<<endl;
    fflush(stdin);//esta funcion me permite que el getline funcione correctamente
    getline(cin,titulo);//uso esta funcion para que me tome todo el string de la consola, y nos solo la primer palabra
    if (lista.existeLibro(titulo))
        cout<<"El libro pertenece a la coleccion."<<endl;
    else
        cout<<"El libro no pertenece a la coleccion."<<endl;
}
void listarVendidos(Lista lista){
    string genero;
    cout<<"Introduzca un genero:"<<endl;
    cin>>genero;
    masVendidos(lista,genero);
}
void menu(Lista listaLibros){
    int i;
    char menuAbierto='y';
    while (menuAbierto=='y'){
        cout<<"---------------Menu---------------"<<endl;
        cout<<"1-Verificar si existe un libro"<<endl;
        cout<<"2-Listar los libros lanzados entre dos años"<<endl;
        cout<<"3-Listar los 10 libros mas vendidos de un genero"<<endl;
        cout<<"Introduzca una opcion:"<<endl;
        cin>>i;
        while ((i!=1) and (i!=2) and (i!=3)){
            cout<<"La opcion ingresada no es correcta."<<endl;
            cout<<"Introduzca una opcion:"<<endl;
            cin>>i;
        }
        if (i==1)
            buscarLibro(listaLibros);
        if (i==2)
            pedirRango(listaLibros);
        if (i==3)
            listarVendidos(listaLibros);
        cout<<"desea seguir operando entre las opciones?(y/n): "<<endl;
        cin>>menuAbierto;
        cout<<"---------------------------------------------------------------------------";
    }
}
int main()
{
    setlocale(LC_ALL, ""); //asegurarse que el archivo de texto fue guardado como Ansi y no como Unicode
    Lista listaDeLibros;
    procesar_archivo_entrada("libros.csv",listaDeLibros);
    menu(listaDeLibros);

    return 0;
}

//Comentarios: atoi y atof requieren un char * para converter a número, usamos c_str de la clase string.
void procesar_archivo_entrada(string origen,Lista &listaDeLibros)
{
    ifstream archivo(origen);
    if (!archivo.is_open())
        cout << "No se pudo abrir el archivo: " << origen << endl;
    else {
        string linea;
        getline(archivo, linea);
        int cantidad_libros = atoi(linea.c_str());
        cout << "Se cargarán " << cantidad_libros << " libros." << endl;

        //Leemos de una linea completa por vez (getline).
        int nroLibro = 1;
        while (getline(archivo, linea)) {
            //Primer posición del separador ;
            int pos_inicial = 0;
            int pos_final = linea.find(',');

            //int idLibro = 1;

            //Informacion entre pos_inicial y pos_final
            string idLibro = linea.substr(pos_inicial, pos_final);

             //Segunda posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            string titulo = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Tercera posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            string autor = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Cuarta posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            string editorial = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Quinta posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            int anio = atoi(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());

            //Sexta posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            string nro_edicion = linea.substr(pos_inicial, pos_final - pos_inicial);


            //Septima posición del separador ;
             //LISTA de GENEROS
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            string lst_generos = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Octava posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            int nro_paginas = atoi(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());


            //Novena posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            int ejemplares_vendidos = atoi(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());

            //Decima posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            string precio = linea.substr(pos_inicial, pos_final - pos_inicial);



            Libro libro(titulo,autor,editorial,anio,nro_edicion,nro_paginas,ejemplares_vendidos,precio,idLibro,lst_generos);
            listaDeLibros.vincularPorAnio(libro);


            /*cout << "LIBRO Nro "<< nroLibro<< ": " << endl;
            cout << "   ISBN: " << idLibro << endl;
            cout << "   TITULO: " << titulo<< endl;
            cout << "   AUTOR: " << autor<< endl;
            cout << "   EDITORIAL: " << editorial<<endl;
            cout << "   AñO EDICION: " << anio<< endl;
            cout << "   NÚMERO EDICION: " << nro_edicion<< endl;
            cout << "   GENEROS: " << lst_generos<<endl;
            cout << "   PAGINAS: " << nro_paginas <<endl;
            cout << "   EJEMPLARES VENDIDOS: " << ejemplares_vendidos <<endl;
            cout << "   PRECIO: " << precio <<endl<<endl;*/


/*
            //TO DO: Completar la lectura de los generos de la cancion

            //Desde esta posición hasta el final se encuentra un número variable de géneros de cada canción.
            //no tomo en cuenta los corchetes
            string generos = lst_generos.substr(1, lst_generos.size()-2);


            // el siguiente código de prueba separa los diferentes géneros en un arreglo de 10 posiciones
            string listaGeneros[10];
            int pos_inicial_generos = 0, pos_final_generos = 0;
            int nroGenero = 0;
            while (pos_final_generos != -1) {
                pos_final_generos = generos.find('|', pos_inicial_generos);
                listaGeneros[nroGenero] = generos.substr(pos_inicial_generos, pos_final_generos - pos_inicial_generos);
                pos_inicial_generos = pos_final_generos + 1;
                nroGenero++;
            }

            for (int i=0; i<10; i++){
                cout << "   GENERO " <<i<<": " << listaGeneros[i] <<endl;
            }
*/
            nroLibro++;
        }
    }
}
