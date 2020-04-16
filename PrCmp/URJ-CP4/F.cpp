#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<long long>;
using vvl = vector<vl>;

vi padre;
vi rango;

int raiz(int p) {
	if(padre[p] == p) return p;
	else return padre[p] = raiz(padre[p]);
}

void resuelveCaso() {
	int N, M; cin >> N >> M;
	N++;
	if(N==0) {
		for(int i = 0; i < M; i++) cout << "NO\n";
		return;
	}
	string opt;

	vector<bool> infectados(N);
	padre.assign(N, 0);
	rango.assign(N, 0);
	for(int i = 0; i < padre.size(); i++) padre[i] = i;

	for(int i = 0; i < M; i++) {
		cin >> opt;
		if(opt == "CONTACTO") {
			int p1, p2; cin >> p1 >> p2;
			if(rango[p1] < rango[p2]) {
				infectados[raiz(p2)] = infectados[raiz(p2)] || infectados[raiz(p2)];
				padre[raiz(p1)] = p2;
				rango[raiz(p2)] = max(rango[raiz(p2)], rango[raiz(p1)]+1);
			}
			else {
				infectados[raiz(p1)] = infectados[raiz(p1)] || infectados[raiz(p2)];
				padre[raiz(p2)] = p1;
				rango[raiz(p1)] = max(rango[raiz(p1)], rango[raiz(p2)]+1);
			}
		}
		else if (opt ==  "POSITIVO") {
			int p; cin >> p;
			infectados[raiz(p)] = true;
		}
		else if (opt == "?") {
			int p; cin >> p;
			cout << (infectados[raiz(p)]? "POSIBLE" : "NO") << '\n';
		}
		else {
			cout << "WHaaAat\n";
		}
	}
}

int main() {
	resuelveCaso();
	return 0;
}
// 6 8 CONTACTO 1 2 CONTACTO 3 4 CONTACTO 2 3 ? 5 POSITIVO 1 ? 4 CONTACTO 2 5 ? 5
