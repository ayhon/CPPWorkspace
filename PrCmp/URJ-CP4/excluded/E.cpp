#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<long long>;
using vvl = vector<vl>;

bool resuelveCaso() {
	int J, P; cin >> J >> P;
	if(J == 0 && P == 0) return false;

	vi juegos(J);

	vector<bool> visited(J, false);
	vi dist(J);
	int idx;
	for(int i = 0; i < J; i++) {
		cin >> idx; 
		cin >> juegos[idx];
	}

	vi ciclos;
	for(int i = 0; i < J; i++) {
		if(visited[i]) continue;
		else {
			int tmp = 0;
			int ini = i;
			int idx = i;
			while(ini != juegos[idx]) {
				idx = juegos[idx];
				visited[idx] = true;
				tmp++;
			}
			ciclos.push_back(tmp);
		}
	}

	int ok = true;
	for(int i = 0; i < ciclos.size() && ok; i++) {
		ok = P > ciclos[i];
	}
	cout << (ok? "SI" : "NO") << '\n';

	return true;
}

int main() {
	while ( resuelveCaso());
	return 0;
}

// 5 4 0 1 1 2 2 3 3 0 4 4 3 1 0 0 2 1 1 2 0 0
// 10 6 0 2 2 4 4 5 5 8 8 0 1 3 3 6 6 1 7 7 9 9 10 5 0 2 2 4 4 5 5 8 8 0 1 3 3 6 6 1 7 7 9 9 0 0
