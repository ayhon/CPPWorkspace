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

void resuelveCaso() {
	int T; cin >> T;
	map<string, int> clientes;
	pair<string, int> maxi;
	for(int i = 0; i < T; i++) {
		int n; cin >> n;
		string nombre, aux; cin >> nombre;
		int & fun = clientes[nombre];
		for(int j = 0; j < n; j++) {
			int diverValor;
			cin >> aux >> diverValor;
			fun += diverValor;
		}
		if(maxi.second < fun) {
			maxi = make_pair(nombre, fun);
		}
	}

	cout << maxi.first << " " << maxi.second << '\n';
	
}

int main() {
	resuelveCaso();
	return 0;
}

