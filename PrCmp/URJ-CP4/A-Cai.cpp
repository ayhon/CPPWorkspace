#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <string>
#include <queue>
#include <cmath>
using namespace std;

using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;
using vvii = vector<vii>;

const int INF = 2000 * 1000 * 1000;

void dijkstra(int nodoInicial, vvii const& listaAdy, vi& distancias) {
	distancias[nodoInicial] = 0;
	priority_queue<ii, vii, greater<ii> > pq;    
	pq.push({ 0, nodoInicial });    

	while (!pq.empty()) {
		ii estadoAct = pq.top();
		pq.pop();
		int nodoAct = estadoAct.second;
		int distAct = estadoAct.first;

		if (distancias[nodoAct] < distAct) continue;            

		for (int i = 0; i < listaAdy[nodoAct].size(); ++i) {
			int nodoSig = listaAdy[nodoAct][i].first;
			int costeArista = listaAdy[nodoAct][i].second;

			if (costeArista + distAct < distancias[nodoSig]) {
				distancias[nodoSig] = costeArista + distAct;    
				pq.push({ distancias[nodoSig], nodoSig });      
			}
		}

	}
}

bool mySort(ii e1, ii e2) {
	if (e1.first == e2.first) {
		return e1.second < e2.second;
	}
	return e1.first < e2.first;
}

int main() {
	int N, C;
	cin >> N >> C;

	vvii listaAdy(N);

	int ini, fin, coste;
	for (int i = 0; i < C; ++i) {
		cin >> ini >> fin >> coste;

		listaAdy[ini].push_back({ fin, coste });
		listaAdy[fin].push_back({ ini, coste }); 
	}

	int origin;
	cin >> origin;

	vi result(N, INF);
	dijkstra(origin, listaAdy, result);

	int E;
	cin >> E;

	vector<pair<int, int>> v;

	int dest, P;
	for (int i = 0; i < E; ++i) {
		cin >> dest >> P;
		v.push_back({ P + result[dest], i });
	}

	sort(v.begin(), v.end(), mySort);

	int winner = v[0].second;
	cout << winner;

	for (int i = 1; i < v.size(); ++i) {
		if (v[i].first == v[i-1].first) {
			cout << " = ";
		}
		else {
			cout << " -> ";
		}

		cout << v[i].second;
	}

	cout << "\n";
	return 0;
}
