#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<long long>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using vpi = vector<pi>;

bool conexoBFS(vvi const& grafo, int origen = 0) {
	queue<int> nodosProcesar;
	nodosProcesar.push(origen);
	vector<bool> vis(grafo.size(), false);

	while(!nodosProcesar.empty()) {
		int nodoA = nodosProcesar.front();
		nodosProcesar.pop();
		vis[nodoA] = true;
		for(int vecino : grafo[nodoA]) {
			if(!vis[vecino]) nodosProcesar.push(vecino);
		}

	}

	bool res = true;
	for(int i = 0; i < vis.size() && res; i++) res = vis[i];
	return res;

}

bool conexoDFS(vvi const& grafo, int origen = 0) {
	stack<int> nodosProcesar;
	nodosProcesar.push(origen);
	vector<bool> vis(grafo.size(), false);

	while(!nodosProcesar.empty()) {
		int nodoA = nodosProcesar.top();
		vis[nodoA] = true;
		nodosProcesar.pop();
		for(int vecino : grafo[nodoA]) {
			if(!vis[vecino]) nodosProcesar.push(vecino);
		}
	}
	
	bool res = true;
	for(int i=0; i < vis.size() && res; i++) res = vis[i];
	return res;
}


bool resuelveCaso() {
	int interes, caminos; cin >> interes >> caminos;
	if(!cin) return false;

	vvi grafo(interes);
	for(int i = 0; i < caminos; i++) {
		pi aux;
		cin >> aux.first >> aux.second;
		aux.first--;
		aux.second--;

		grafo[aux.first].push_back(aux.second);
		grafo[aux.second].push_back(aux.first);
	}
	
	if(conexoDFS(grafo)) cout << "BICI";
	else cout << "A PIE";
	cout << '\n';

	return true;
}

int main() {
	/*
	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		//cout << "Case #" << i << ": ";
		resuelveCaso();
	
	}
	// */

	//*
	while(resuelveCaso());
	// */
	return 0;
}


