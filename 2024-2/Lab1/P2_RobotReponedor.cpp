/* 
 * File:   main.cpp
 * Author: cueva
 *
 * Created on 12 de septiembre de 2024, 07:58 PM
 */

#include <iostream>
using namespace std;

#define N 5
#define M 5

int robot(int x,int y,int max,int tablero[N][M], int solu[N][M]){
    // Reemplazar el máximo si el elemento del tablero actual es mayor
    if (max < tablero[x][y])
        max = tablero[x][y];
    // Actualizar matriz de solución
    if (x < N && y < M) {
        max = robot(x,y+1,n,m,max,tablero,solu); // Seguir buscando el máximo en la siguiente columna
    } else if (y == M) {
        max = robot(x+1,0,n,m,max,tablero,solu); // Seguir buscando el máximo en la siguiente fila
    }
    // Cuando ya se tenga el máximo en todo el arreglo, actualizar el tablero de solución
    solu[x][y] = max - tablero[x][y];
    return max;
}



int main(int argc, char** argv) {
    int tablero[N][M] = {{4,3,6,8,7},
                        {6,3,8,4,10},
                        {2,15,1,2,13},
                        {5,1,10,11,2},
                        {10,4,7,9,4}};
    int solu[N][M] = {{}};
    // Imprimir máximo
    cout << robot(0,0,n,m,0,tablero,solu)<< endl;
    // Imprimir matriz
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout << solu[i][j] << " ";
        cout << endl;
    }
    
    return 0;
}

