//
// Created by sauls on 12/04/2026.
//

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

#include "Circulo.h"
#include "Figura.h"
using namespace std;

// Ejercicio 5
void numerarLineas(const string& nombreEntrada, const string& nombreSalida) {
    ifstream archivoEntrada;
    ofstream archivoSalida;

    archivoEntrada.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    archivoSalida.exceptions(std::ofstream::badbit | std::ofstream::failbit);

    try {
        archivoEntrada.open(nombreEntrada);
        archivoSalida.open(nombreSalida);

        string linea;
        int contador = 1;

        archivoEntrada.exceptions(std::ifstream::badbit);

        while (getline(archivoEntrada, linea)) {
            archivoSalida << contador <<  ":" << linea << endl;
            contador++;
        }
        archivoEntrada.close();
        archivoSalida.close();
    }catch (const exception& e) {
        throw runtime_error("Error al procesar archvios" + string (e.what()));
    }
}

int main() {

    //Simulacro A
    Figura* fig1 = new Circulo("Azul", 10.0);

    cout << "El color es: " << fig1->getColor() << endl;
    cout << "Area es: " << fig1->area() << endl;

    /*
     Lo que ocurre aqui es upcasting, la clase hijo se viste o actua como la clase padre,
     es decir que convertimos el Circulo en una Figura
     */

    //Downcast
    // Un ejemplo de downcast inseguro seria que trate de hacer pasar una figura que es un triangulo como un circulo
    // el programa se pondria a buscarlo en la memoria y al no encontrar que el triangulo se pueda comportar como un circulo ya que
    //cuenta con una altura en lugar de un radio o algun atributo del circulo ocasionaria un comportamiento inesperado


    Figura* fig2 = new Circulo("Azul", 10.0);
    Circulo* circuloVerdadero = dynamic_cast<Circulo*>(fig2);

    cout << "El color es: " << circuloVerdadero->getColor() << endl;
    cout << "Area es: " << circuloVerdadero->area() << endl;

    delete fig1;
    delete fig2;
    // Fin Simulacro B



    return 0;
}


/*

Ejercicio 5 – Flujo de texto (20 pts)
Escriba una función void numerarLineas(const string& nombreEntrada, const string& nombreSalida) que:

abra nombreEntrada para lectura de texto;
escriba en nombreSalida cada línea precedida por su número (1: ..., 2: ...);
use try/catch y lance o capture adecuadamente si el archivo de entrada no existe o no se puede abrir.
No hace falta main completo, pero el código debe ser compilable con inclusiones razonables.

 */