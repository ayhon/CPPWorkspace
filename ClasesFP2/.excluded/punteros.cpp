//Author: Ayhon
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	//Incializar un puntero
	int* punt;
	int* punt = nullptr;

	//Asignar a un puntero la dir de una var.
	int i = 5, j;
	punt = &i;

	// Es necesario dar el tipo al puntero
	// para saber el tamaño

	//Para acceder al valor en memoriaç
	j = *punt;

	/* PUNTEROS A EXTRUCTURAS */
	cout << "\nPUNTEROS A EXTRUCTURAS\n";
	struct tRegistro {
		int codigo;
		string nombre;
		double sueldo;
	};
	using tRegisrtroPtr = tRegistro*;
	tRegistro registro;
	tRegistroPtr puntero = &registro;

	// puntero apunta a registro
	if(registro == *puntero) cout<<"SI\n";
	else cout << "NO\n";

	// Para acceder a los distintos campos
	if(puntero->nombre == (*puntero).nombre)
		cout << "SI\n";
	else cout << "NO\n";


	return 0;
}

