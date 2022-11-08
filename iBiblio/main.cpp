#include <iostream>
#include <sstream>
#include <fstream>
#include <clocale>
#include "Libro.h"
#include "Lista.h"
using namespace std;

/**
 * Abre el archivo seg�n el origen, procesa las l�neas del mismo y
 * almacena la informaci�n resultante en el contenedor pasado por referencia.
 **/
void procesar_archivo_entrada(string origen,Lista listaLibros);//, Contenedor & contenedor);

int main()
{
    setlocale(LC_ALL, ""); //asegurarse que el archivo de texto fue guardado como Ansi y no como Unicode
    Lista lista;
    procesar_archivo_entrada("libros.csv",lista);
    //lista.imprimir();

    return 0;
}

//Comentarios: atoi y atof requieren un char * para converter a n�mero, usamos c_str de la clase string.
void procesar_archivo_entrada(string origen,Lista listaLibros)
{
    ifstream archivo(origen);
    if (!archivo.is_open())
        cout << "No se pudo abrir el archivo: " << origen << endl;
    else {
        string linea;
        getline(archivo, linea);
        int cantidad_libros = atoi(linea.c_str());
        cout << "Se cargar�n " << cantidad_libros << " libros." << endl;

        //Leemos de una linea completa por vez (getline).
        int nroLibro = 1;
        while (getline(archivo, linea)) {
            //Primer posici�n del separador ;
            int pos_inicial = 0;
            int pos_final = linea.find(',');

            //int idLibro = 1;

            //Informacion entre pos_inicial y pos_final
            string idLibro = linea.substr(pos_inicial, pos_final);

             //Segunda posici�n del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            string titulo = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Tercera posici�n del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            string autor = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Cuarta posici�n del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            string editorial = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Quinta posici�n del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            int anio = atoi(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());

            //Sexta posici�n del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            string nro_edicion = linea.substr(pos_inicial, pos_final - pos_inicial);


            //Septima posici�n del separador ;
             //LISTA de GENEROS
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            string lst_generos = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Octava posici�n del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            int nro_paginas = atoi(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());


            //Novena posici�n del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            int ejemplares_vendidos = atoi(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());

             //Decima posici�n del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            string precio = linea.substr(pos_inicial, pos_final - pos_inicial);



            Libro libro(titulo,autor,editorial,anio,nro_edicion,nro_paginas,ejemplares_vendidos,precio,idLibro,lst_generos);
            listaLibros.vincularPorAnio(libro);


            /*cout << "LIBRO Nro "<< nroLibro<< ": " << endl;
            cout << "   ISBN: " << idLibro << endl;
            cout << "   TITULO: " << titulo<< endl;
            cout << "   AUTOR: " << autor<< endl;
            cout << "   EDITORIAL: " << editorial<<endl;
            cout << "   A�O EDICION: " << anio<< endl;
            cout << "   N�MERO EDICION: " << nro_edicion<< endl;
            cout << "   GENEROS: " << lst_generos<<endl;
            cout << "   PAGINAS: " << nro_paginas <<endl;
            cout << "   EJEMPLARES VENDIDOS: " << ejemplares_vendidos <<endl;
            cout << "   PRECIO: " << precio <<endl<<endl;*/


/*
            //TO DO: Completar la lectura de los generos de la cancion

            //Desde esta posici�n hasta el final se encuentra un n�mero variable de g�neros de cada canci�n.
            //no tomo en cuenta los corchetes
            string generos = lst_generos.substr(1, lst_generos.size()-2);


            // el siguiente c�digo de prueba separa los diferentes g�neros en un arreglo de 10 posiciones
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

