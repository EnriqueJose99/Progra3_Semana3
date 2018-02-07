#include <iostream>
#include <fstream>


using namespace std;
//Provisionnar la matriz de chars para el laberinto
char** provisionarMatriz(int);


//Liberar memoria de la matriz 
void liberarMatriz(char**&, int);

//Imprimir la matriz
void imprimirMatriz(char**, int);

//Slair del laberinto: lab, size, x, y



int main(){
	//Abrir el archivo
	ifstream file("laberinto.txt");

	int size =0;

	char** labMatrix = NULL;
	//si el archivo existe
	
	if(file.is_open){
		//leer el tamano
		file >> size;
	

		//inicializar la matriz del archivo
		labMatrix = provisionarMatriz(size);
		//leer la matriz del archivo 
		for(int i=0;i<size;i++)
			for(int j=0;j<size;j++)
				file >> labMatrix[i][j];

		
		file.close();

		//imprimir laberinto 
		imprimirMatriz(labMatrix, size);

		//salir del laberinto


		//liberar matriz
		liberarMatriz(labMatrix, size);


	}//END IF
	return 0;
}//END MAIN

//provisionar matriz
char** provisionarMatriz(int size){
	char** retValue = new char*[size];
	for(int i=0;i<size;i++){
		retValue[i] = new char[size];
		
	}
	return retValue;
}

//Liberar memoria de la matriz;
void liberarMatriz (char**& matrix, int size){
	for(int i=0;i<size;i++){
		delete[] matrix[i];
		matrix[i]  = NULL;
		//Buena paractica asignar null al variable
	}
	delete matrix;
}


//Imprimir matriz

void imprimirMatriz(char** matriz, int size){
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			cout<<matriz[i][j]<< " ";
		}
		cout << endl;
	}
}
