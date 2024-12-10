/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * Archivo: main.cpp
 * Autor:   Anthony Gutiérrez
 * Fecha:   24 de noviembre de 2024, 12:29 PM
 */

#include <iostream>
#include <cstdlib>
#include "funciones.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int **muestras, cantNiveles = 0;
    leerDatos(muestras, cantNiveles);
    // imprimirDatos(muestras, cantNiveles);
    calcularMaximaPureza(muestras, cantNiveles);
    celcularNivelesConMasMinerales(muestras, cantNiveles);
    return 0;
}

