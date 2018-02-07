#include <iostream>
#include <fstream>


using namespace std;
//Provisionnar la matriz de chars para el laberinto



//Liberar memoria de la matriz 


//Imprimir la matriz


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

	}
	

	return 0;
}
