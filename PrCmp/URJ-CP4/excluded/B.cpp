
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
	int M; cin >> M;
	vi presup(M);
	for(int & i: presup) {
		cin >> i;
	}
	int C; cin >> C;
	vi cartas(C);
	for(int & i : cartas) {
		cin >> i;
	}
	int R; cin >> R;
	vi raras(R);
	for(int & c : raras) {
		cin >> c;
	}
	vvi fluct(M);
	for(vi & jugadas : fluct) {
		int n; cin >> n;
		jugadas.resize(n);
		for(int & c : jugadas) {
			cin >> c;
		}
	}

	for(int mes = 0; mes < M; mes++) {
		
	}

}

int main() {
	int T;  T =  1;
	for (int i = 1; i <= T; i++) {
		//cout << "Case #" << i << ": ";
		resuelveCaso();
	}
	return 0;
}

