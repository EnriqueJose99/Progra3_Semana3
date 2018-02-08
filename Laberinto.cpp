#include <iostream>
#include <fstream>


using namespace std;
//Provisionnar la matriz de chars para el laberinto
char** provisionarMatriz(int);


//Liberar memoria de la matriz 
void liberarMatriz(char**&, int);

//Imprimir la matriz
void imprimirMatriz(char**, int);

//Salir del laberinto: lab, size, x, y
bool salir(char**, int, int, int);


int main(){
	//Abrir el archivo
	ifstream file("laberinto.txt");

	int size =0;

	char** labMatrix = NULL;
	//si el archivo existe
	
	if(file.is_open()){
		//leer el tamano
		file >> size;
	

		//inicializar la matriz del archivo	char** retValue = new char*[size];
		labMatrix = provisionarMatriz(size);
		//leer la matriz del archivo 
		for(int i=0;i<size;i++)
			for(int j=0;j<size;j++)
				file >> labMatrix[i][j];

		
		file.close();

		//imprimir laberinto 
		imprimirMatriz(labMatrix, size);

		//salir del laberinto
		salir(labMatrix, size, 1, 0);
		//imprimir de nuevo 
		imprimirMatriz(labMatrix, size);

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


//Salir
bool salir(char** matriz, int size, int x, int y){
	bool salio = false;
	if(x >= 0 && x<= size - 1 && y>= 0 && y<= size -1){
		matriz[x][y] == '*';
		if(y ==  size - 1){
			return true;

		}else{

			if(x > 0){
				if(matriz[x-1][y] == '.'){
					salir(matriz, size, x-1, y);
				}
			}
			if(x < size -1){
				if(matriz[x+1][y] == '.'){
					salir(matriz, size, x+1,y);	
				}
			}
			if(y > size -1 ){
				if(matriz[x][y+1] == '.'){
					salir(matriz, size, x, y+1);
				}
			}
			if(y > 0){
				if(matriz[x][y-1] == '.'){
					salir(matriz, size, x, y-1);
				}
			}
		}

	}else{
		return false;
	}

}


