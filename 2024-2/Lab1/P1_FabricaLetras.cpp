/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: david
 *
 * Created on 12 de setiembre de 2024, 19:32
 */

#include <cstdlib>
#include <iostream>
#include <cmath>

#define N 8
#define M 10

using namespace std;

/*
 * 
 */

void cargaBin(int n, int cromo[N], int size){
	// Limpiar el arreglo
    for (int i=0; i<size; i++){
        cromo[i] = 0;
    }
    int i=0;
    // Genera una representación binaria inversa del número, por ejemplo 53 = 0b00110101,
    // entonces cada bit lo coloco en un arreglo y según eso voy uniendo las letras
    // El arreglo final sería: {1,0,1,0,1,1,0,0}
    while (n>0){
        cromo[i] = n%2;
        n = n/2;
        i++;
    }
}

void validarPalabra(char letras[N], int cromo[N],int cantidad, int size,
        char palabras[M][N],int totalPalabras,int totales[M],int tamanhos[M]){
    char palabraAux[N];
    for (int i=0; i<totalPalabras; i++){
        // Solo continuar si la cantidad de letras es la misma que la palabra deseada
        if (tamanhos[i]==cantidad){
            // Copiamos la palabra buscada para asegurar que no se repitan
            for (int j=0; j<cantidad; j++){
                palabraAux[j] = palabras[i][j];
            }
            // Buscar si cada letra escogida en la combinatoria coincide con la palabra
            int letrasEncontradas=0;
            for (int j=0; j<size; j++){
                if (cromo[j]==1){
                    for (int k=0; k<cantidad; k++){
                        if (letras[j]==palabraAux[k]){
                            palabraAux[k] = ' ';
                            letrasEncontradas++;
                            break;
                        }
                    }
                }
            }
            // Si coincide, imprimimos el resultado e incrementamos el contador
            if (letrasEncontradas==cantidad){
                totales[i]++;
                if (i==1){
                    for (int l=0; l<size; l++){
                        cout << cromo[l] << " ";
                    }
                    cout << endl;
                }
            }
        }
    }
}

int main(int argc, char** argv) {
    char letras[N] = {'G','A','L','A','O','G','L','M'};
    char palabras[M][N] = {{'G','O','L',0},
                           {'G','A','L','A',0},
                           {'A','L','A',0},
                           {'L','O','M','A',0}};
    int tamanhos[M] = {3,4,3,4};
    int cromo[N];
    int totales[M] = {0};
    int size=8, totalPalabras=4;
    int combinaciones = pow(2,size); // 2^8=256
    // 
    for (int i=0; i<combinaciones; i++){
        cargaBin(i,cromo,size);
        // Obtener cantidad de 1s en el arreglo
        int cantidad = 0;
        for (int j=0; j<size; j++){
            if (cromo[j]==1){
                cantidad++;
            }
        }
        validarPalabra(letras,cromo,cantidad,size,palabras,totalPalabras,totales,tamanhos);
    }
    for (int i=0; i<totalPalabras; i++){
        cout << "La palabra: " << palabras[i] << " tiene " << totales[i] << " combinaciones" << endl;
    }
    return 0;
}

