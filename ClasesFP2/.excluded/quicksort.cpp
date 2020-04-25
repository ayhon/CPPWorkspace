#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

void particion(vector<int> & V, int ini, int fin, int pivote, int & i, int & j) {
	i = ini; int k = ini + 1; j = fin;
	// i es la localización del pivote, y
	// 	marca los elementos ya procesados del principio
	// k es el índice del elemento procesado
	// j marca los elementos ya procesados del final
	// Siempre k>=i y j>k dentro del bucle
	while(k < j) {
		if(V[k] < pivote) {
			// Entonces, a la izquierda con V[k]
			swap(V[k], V[i]); ++i; ++k;
		}
		else if(pivote< V[k]) {
			// Entonces, a la derecha con V[k]
			swap(V[k], V[j-1]); --j;
		}
		else k++;
			// Es el valor del pivote, nos da igual
	}
}

void quicksort(vector<int> & V, int ini, int fin) {
	if(ini < fin-1) {
		int i, j;
		particion(V, ini, fin, V[ini], i, j);
		quicksort(V, ini, i);
		quicksort(V, j, fin);
	}
}

void resuelveCaso() {
	int n; cin >> n;
	vector<int> V(n);
	for(int & e : V) cin >> e;
	quicksort(V, 0, V.size());
	
}

int main() {
	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		//cout << "Case #" << i << ": ";
		resuelveCaso();
	}
	return 0;
}


