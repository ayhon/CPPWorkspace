#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

pair<bool, pair<int, int> > parcialOrdenado(vector<int> const& vct, int ini, int fin) {
	pair<bool, pair<int, int> > res;
	if(fin - ini == 1) return make_pair(true, make_pair(vct[ini], vct[ini]));
	if(fin - ini == 2) return make_pair(vct[ini] <= vct[fin-1], make_pair(max(vct[fin-1], vct[ini]), min(vct[ini], vct[fin-1])));
	else {
		int mid = (ini + fin) / 2;
		auto res_left = parcialOrdenado(vct, ini, mid);
		auto res_right = parcialOrdenado(vct, mid, fin);
		if(res_left.first && res_right.first) {
			res.first = (res_left.second.first <= res_right.second.first) && (res_left.second.second <= res_right.second.second);
		}
		else res.first = false;
		res.second.first = max(res_left.second.first, res_right.second.first);
		res.second.second = min(res_left.second.second, res_right.second.second);
	}
	return res;
}

bool resuelveCaso() {
	vector<int> vct(1); cin >> vct.front();
	if(vct.front() == 0) return false;
	int aux; cin >> aux;
	while(aux != 0) {
		vct.push_back(aux);
		cin >> aux;
	}

	if(parcialOrdenado(vct, 0, vct.size()).first) cout << "SI\n";
	else cout << "NO\n";

	return true;
}

int main() {
	while(resuelveCaso());
	return 0;
}


