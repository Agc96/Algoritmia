/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * Archivo: funciones.cpp
 * Autor:   Anthony Gutiérrez
 * Fecha:   24 de noviembre de 2024, 03:01 PM
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "funciones.h"
using namespace std;

void leerDatos(int **&muestras, int &cantEstratos) {
    ifstream arch("Muestras.txt", ios::in);
    if (!arch) {
        cerr << "No se pudo abrir el archivo Muestras.txt" << endl;
        exit(1);
    }
    arch >> cantEstratos;
    muestras = new int *[cantEstratos];
    for (int i = 0; i < cantEstratos; i++) {
        muestras[i] = new int[cantEstratos];
        for (int j = 0; j < cantEstratos; j++)
            arch >> muestras[i][j];
    }
}

void imprimirDatos(int **muestras, int cantEstratos) {
    for (int i = 0; i < cantEstratos; i++) {
        for (int j = 0; j < cantEstratos; j++)
            cout << setw(2) << muestras[i][j] << ' ';
        cout << endl;
    }
}

void calcularMaximaPureza(int **muestras, int cantEstratos) {
    int maxPureza = 0, maxMuestra, maxEstrato, max, col;
    for (int fil = 0; fil < cantEstratos; fil++) {
        obtenerMaximo(muestras[fil], cantEstratos, max, col);
        if (max > maxPureza) {
            maxPureza = max;
            maxMuestra = fil+1;
            maxEstrato = col+1;
        }
    }
    cout << "La maxima pureza de las muestras es: " << maxPureza
            << " (encontrado en la muestra " << maxMuestra
            << ", en el estrato " << maxEstrato << ")" << endl;
}

void obtenerMaximo(int *arreglo, int cant, int &max, int &pos) {
    int izq = 0, der = cant-1, med;
    while (izq < der) {
        med = (izq+der) / 2;
        if (arreglo[med] > arreglo[med+1]) {
            // El pico está en la mitad izquierda, incluyendo el medio
            der = med;
        } else {
            // El pico está en la mitad derecha, excluyendo el medio
            izq = med+1;
        }
    }
    max = arreglo[izq];
    pos = izq;
}

void celcularNivelesConMasMinerales(int **muestras, int cantEstratos) {
    int maxNivel = 0, *maxEstratos = new int[cantEstratos]{}, cantMaxNivel = 0,
            cantCeros, nivel;
    for (int fil = 0; fil < cantEstratos; fil++) {
        // Calcular la cantidad de ceros
        if (muestras[fil][0] == 0)
            cantCeros = contarCerosIzquierda(muestras[fil], cantEstratos);
        else
            cantCeros = contarCerosDerecha(muestras[fil], cantEstratos);
        // Evaluar si es el máximo
        nivel = cantEstratos - cantCeros;
        if (nivel > maxNivel) {
            maxNivel = nivel;
            cantMaxNivel = 0;
        }
        if (nivel == maxNivel) {
            maxEstratos[cantMaxNivel++] = fil+1;
        }
    }
    cout << "Las muestras con mayor cantidad de niveles con minerales son: ";
    for (int i = 0; i < cantMaxNivel; i++) {
        if (i != 0) cout << ", ";
        cout << maxEstratos[i];
    }
    cout << " con " << maxNivel << " estratos de minerales." << endl;
}

int contarCerosIzquierda(int *arreglo, int cant) {
    int izq = 0, der = cant-1, med;
    while (izq <= der) {
        med = (izq+der) / 2;
        if (arreglo[med] == 0) {
            // Voy a la derecha y ya tengo los ceros de la izquierda
            izq = med+1;
        } else {
            // Voy a la izquierda y no tengo ceros porque el medio no es 0
            der = med-1;
        }
    }
    return izq;
}

int contarCerosDerecha(int *arreglo, int cant) {
    int izq = 0, der = cant-1, med;
    while (izq <= der) {
        med = (izq+der) / 2;
        if (arreglo[med] == 0) {
            der = med-1;
        } else {
            izq = med+1;
        }
    }
    return cant-der-1;
}
