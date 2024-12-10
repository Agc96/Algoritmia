/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * Archivo: funciones.h
 * Autor:   Anthony Gutiérrez
 * Fecha:   24 de noviembre de 2024, 03:01 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

void leerDatos(int **&muestras, int &cantNiveles);
void imprimirDatos(int **muestras, int cantNiveles);
void calcularMaximaPureza(int **muestras, int cantNiveles);
void obtenerMaximo(int *arreglo, int cant, int &max, int &pos);
void celcularNivelesConMasMinerales(int **muestras, int cantNiveles);
int contarCerosIzquierda(int *arreglo, int cant);
int contarCerosDerecha(int *arreglo, int cant);

#endif /* FUNCIONES_H */

