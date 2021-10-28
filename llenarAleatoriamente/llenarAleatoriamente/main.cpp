#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
void LlenarAleatoriamente(int**& matriz, int tam);
void imprimir(int** matriz, int tam);
void RestarPrimeraUltimaFila(int**& matriz, int tam);
int main() {
	srand(time(NULL));
	int tam = 0;
	
		printf("Tam de matriz: ");
		scanf("%d", &tam);
		
		int** matriz = new int* [tam];
		if (matriz != NULL) {
			for (int i = 0; i < tam; i++)
				matriz[i] = new int[tam];
		}

	for (int i = 0; i < tam; i++) {
		for (int j = 0; j < tam; j++) {
			matriz[i][j] = 1;
		}
	}
	imprimir(matriz, tam);
	printf("aleatorios: \n");
	LlenarAleatoriamente(matriz, tam);
	imprimir(matriz, tam);
	printf("fila 1 restada con fila %d: \n", tam);
	RestarPrimeraUltimaFila(matriz, tam);
	imprimir(matriz, tam);
	for (int i = 0; i < tam; i++)
		delete[]matriz[i];
	delete[]matriz;
}
void LlenarAleatoriamente(int**& matriz, int tam) {
	for (int f = 0; f < tam; f++) {
		for (int c = 0; c < tam; c++) {
			matriz[f][c] = 6 + rand() % 16; // llena de numeros aleatorios del 6 al 21. 
		}
	}
}
void imprimir(int** matriz, int tam) {
	for (int i = 0; i < tam; i++) {
		for (int j = 0; j < tam; j++) {
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void RestarPrimeraUltimaFila(int**& matriz, int tam) {
	
		for (int c = 0; c < tam; c++) {
			matriz[0][c] = matriz[0][c] - matriz[tam-1][c];
		}
}