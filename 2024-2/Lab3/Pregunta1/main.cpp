/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: alulab14
 *
 * Created on 2 de noviembre de 2024, 08:25
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "funciones.h"
using namespace std;

int main(int argc, char** argv) {
    int registros[MAX_REGISTROS]{}, cantRegistros, resultado;
    leerDatos(registros, cantRegistros);
    imprimirDatos(registros, cantRegistros);
    ordenar(registros, cantRegistros);
    imprimirDatos(registros, cantRegistros);
    resultado = evaluar(registros, cantRegistros);
    cout << "El empleado " << resultado << " ingresó y no salió" << endl;
    return 0;
}
