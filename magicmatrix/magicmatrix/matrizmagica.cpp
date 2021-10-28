#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int IsMagicMatrix(int** matriz, int n);
int main()
{
	int** matriz = new int* [3];
	for (int i = 0; i < 3; i++) {
		matriz[i] = new int[3];
	}
	for (int f = 0; f < 3; f++)
	{
		for (int c = 0; c < 3; c++)
		{
			matriz[f][c] = 1;
		}
	}
	int mag = IsMagicMatrix(matriz, 3);
	if (mag == 1)
		printf("Matriz magica");


	if (matriz != NULL) {
		for (int i = 0; i < 3; i++) {
			if (matriz[i] != NULL)
				delete[]matriz[i];
		}
		delete[]matriz;
	}
	return 0;
}
int IsMagicMatrix(int** matriz, int n) {
	int sumafila = 0;
	int* vertical = new int[n];
	int* horizontal = new int[n];
	int diags = 0, diagp = 0;
	int sumacolumna = 0;
	int f = 0;
	for (f = 0; f < n; f++)
	{
		sumafila = 0;
		for (int c = 0; c < n; c++)
		{
			sumacolumna = 0;
			for (int h = 0; h < n; h++)
			{
				sumacolumna = sumacolumna + matriz[h][c];
			}
			vertical[c] = sumacolumna; // misma columna
			sumafila = sumafila + matriz[f][c];
			if (f == c) // diagonal principal
				diagp = diagp + matriz[f][c];
			if (f + c == n - 1) // diagonal secundaria
				diags = diags + matriz[f][c];
		}
		horizontal[f] = sumafila; // misma fila
		
	}
	if (sumafila == sumacolumna && diagp == diags && sumafila == diagp && sumafila == diags && sumacolumna == diagp && sumacolumna == diags) {
		delete[] vertical;
		delete[] horizontal;
		return 1;
	}
	delete[] vertical;
	delete[] horizontal;
		return 0; // si no entra a la condicion es porque eran distintos
}