/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "funciones.h"
using namespace std;

void leerDatos(int *registros, int &cantRegistros) {
    ifstream arch("Datos.txt", ios::in);
    if (!arch) {
        cerr << "No se pudo abrir el archivo Datos.txt" << endl;
        exit(1);
    }
    cantRegistros = 0;
    while (true) {
        arch >> registros[cantRegistros];
        if (arch.eof()) break;
        cantRegistros++;
    }
}

void ordenar(int *registros, int cantRegistros) {
    mergeSort(registros, 0, cantRegistros-1);
}

void mergeSort(int *registros, int ini, int fin) {
    if (ini == fin) return;
    int med = (ini+fin)/2;
    mergeSort(registros, ini, med);
    mergeSort(registros, med+1, fin);
    merge(registros, ini, med, fin);
}

void merge(int *registros, int ini, int med, int fin) {
    int auxiliar[MAX_REGISTROS], i = ini, j = med+1, index = 0;
    // Insertar ordenadamente de ambos arreglos
    while (i <= med && j <= fin) {
        if (registros[i] < registros[j]) {
            auxiliar[index++] = registros[i++];
        } else {
            auxiliar[index++] = registros[j++];
        }
    }
    // Agregar datos sobrantes del primer arreglo
    while (i <= med)
        auxiliar[index++] = registros[i++];
    // Agregar datos sobrantes del segundo arreglo
    while (j <= fin)
        auxiliar[index++] = registros[j++];
    // Reinsertar en el arreglo original
    for (i = ini; i <= fin; i++)
        registros[i] = auxiliar[i-ini];
}

void imprimirDatos(int *registros, int cantRegistros) {
    for (int i = 0; i < cantRegistros; i++) {
        if (i != 0) cout << ' ';
        cout << registros[i];
    }
    cout << endl;
}

/* int evaluar(int *registros, int cantRegistros) {
    int anterior = 0, cantidad = 0;
    for (int i = 0; i < cantRegistros; i++) {
        // Verificar si cambiamos de empleado
        if (registros[i] != anterior) {
            if (cantidad % 2 != 0) break;
            // Reiniciar contador
            anterior = registros[i];
            cantidad = 0;
        }
        cantidad++;
    }
    return anterior;
} */

int evaluar(int *arreglo, int cant) {
    int ini = 0, fin = cant-1, med, anterior, actual, siguiente;
    while (ini <= fin) {
        med = (ini+fin) / 2;
        anterior = (med-1 >= 0) ? arreglo[med-1] : 0;
        actual = arreglo[med];
        siguiente = (med+1 < cant) ? arreglo[med+1] : 0;
        // Ver si hay 3 registros del empleado
        if (actual == anterior && actual == siguiente)
            return actual;
        // Ver hacia dónde ir segun el par de registros que coinciden
        if (actual == anterior) { // Ejemplo: 1 1 2
            if (med % 2 == 0) {
                // Ejemplo:  0 1 2 3 4
                //          {1,1,1,2,2}
                fin = med; // Ir hacia la izquierda
            } else {
                // Ejemplo:  0 1 2 3 4 5 6
                //          {1,1,2,2,3,3,3}
                ini = med+1; // Ir hacia la derecha
            }
        } else { // Ejemplo: 1 2 2
            if (med % 2 == 0) {
                // Ejemplo:  0 1 2 3 4
                //          {1,1,2,2,2}
                ini = med; // Ir hacia la derecha
            } else {
                // Ejemplo:  0 1 2 3 4 5 6
                //          {1,1,1,2,2,3,3}
                fin = med-1; // Ir hacia la izquierda
            }
        }
    }
    // En caso no se encuentre ningún trío de números
    return 0;
}
