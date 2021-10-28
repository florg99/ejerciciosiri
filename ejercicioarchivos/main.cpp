#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
typedef struct s_punto3D {
	int x, y, z;
}punto3d_t;
void contar_palabras(const char* nombrearchivo, int* cant);
void creararchivo(const char* nombrearchivo);
void LeerPuntos3dBinarios(const char* nombrearchivo);
void EscribirPuntoEnArchivo(const char* nombrearchivo, punto3d_t *puntito);
int main(int argc, char** argv) {
	
	char *nombre= new char[strlen(argv[1])+1]; // considero que el argumento argv[1] es el nombre del archivo, lo pasamos por command arguments
	sprintf(nombre, argv[1]);
	/*int cant = 0;
	contar_palabras("archivo.txt", &cant);
	printf("%d", cant);*/
	punto3d_t punto = { 1,2,3 };
	EscribirPuntoEnArchivo(nombre, &punto);
	LeerPuntos3dBinarios(nombre);
	delete[] nombre;
	return 0;
}
void contar_palabras(const char* nombrearchivo, int* cant){
	FILE* fp = fopen(nombrearchivo, "r");
	if (fp != NULL) {
		fseek(fp, 0, SEEK_END);
		long int tam = ftell(fp);
		tam = tam / sizeof(char);
		rewind(fp);
		char* aux = new char[tam + 2];
			aux = fgets(aux, tam, fp);
			char* linea = new char;
			if (linea != NULL) {
				linea = strtok(_strdup(aux), " ");
				while (linea != NULL) {
					linea = strtok(NULL, " ");
					(*cant) = (*cant + 1);
				}
		}
		
		delete[] aux;
		delete linea;
		fclose(fp);
	}
	else {
		printf("No existe el archivo");
	}
	}
void creararchivo(const char* nombrearchivo) {
	FILE* fp = fopen(nombrearchivo, "w");
	fclose(fp);
}
void EscribirPuntoEnArchivo(const char* nombrearchivo, punto3d_t* puntito) {
	FILE* fp = fopen(nombrearchivo, "ab");
	if (fp != NULL) {
		fwrite(puntito, sizeof(punto3d_t), 1, fp);
		fclose(fp);
	}
}
void LeerPuntos3dBinarios(const char* nombrearchivo) {
	punto3d_t buffer = {0,0,0};
	FILE* fp = fopen(nombrearchivo, "rb");
	if (fp != NULL) {
	 fread(&buffer, sizeof(punto3d_t), 1, fp);

		printf("x: %d y: %d z: %d\n", buffer.x, buffer.y, buffer.z);
		fclose(fp);

	}
	
}