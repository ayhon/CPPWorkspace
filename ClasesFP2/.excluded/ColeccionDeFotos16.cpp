//Author: Ayhon
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct tFoto {
	string titulo = "";
	string tema = "";
	vector<vector<int>> imagen;
};

struct compTema {
	bool operator()(tFoto* f1, tFoto* f2) {
		return (f1->tema < f2->tema) || (f1->tema == f2->tema && f1->titulo < f2->titulo);
	}
};
struct compTitulo {
	bool operator()(tFoto* f1, tFoto* f2) {
		return f1->titulo < f2->titulo;
	}
};


bool resuelveCaso() {
	int numImagenes; cin >> numImagenes;
	if(numImagenes == 0) return false;
	vector<tFoto> album(numImagenes);
	cin.ignore();

	string aux;

	int i = 0;
	for (i = 0; i < numImagenes; ++i) {
		getline(cin, aux);
		album[i].titulo = aux;
	}

	for (int i = 0; i < numImagenes; ++i) {
		getline(cin, aux);
		album[i].tema = aux;
	}
	vector<tFoto*> albumOrdenado(numImagenes);
	for (size_t i = 0; i < numImagenes; i++) {
		albumOrdenado[i] = &album[i];
	}
	
	sort(albumOrdenado.begin(), albumOrdenado.end(), compTitulo());

	for (int i = 0; i < numImagenes; ++i){
		cout << albumOrdenado[i]->titulo << '\n';
	}
	cout << '\n';

	sort(albumOrdenado.begin(), albumOrdenado.end(), compTema());

	for (int i = 0; i < numImagenes; ++i){
		cout << albumOrdenado[i]->tema << " - " << albumOrdenado[i]->titulo << '\n';
	}
	cout << '\n';

	return true;
}

int main() {
	while(resuelveCaso());
	return 0;
}

