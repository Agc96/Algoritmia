/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: alulab14
 *
 * Created on 2 de noviembre de 2024, 08:28
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_REGISTROS 15

void leerDatos(int *registros, int &cantRegistros);

void ordenar(int *registros, int cantRegistros);
void mergeSort(int *registros, int ini, int fin);
void merge(int *registros, int ini, int med, int fin);

void imprimirDatos(int *registros, int cantRegistros);
int evaluar(int *registros, int cantRegistros);
int evaluarOptimizado(int *arreglo, int cant);

#endif /* FUNCIONES_H */
