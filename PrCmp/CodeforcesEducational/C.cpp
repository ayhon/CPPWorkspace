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
using pi = pair<int, int>;
using vpi = vector<pi>;
using pl = pair<long long, long long>;
using vpl = vector<pl>;

long long dmged(int i, vpl const& monsters) {
	if(i == 0)  return monsters[i].first - monsters.back().second;
	return monsters[i].first - monsters[i-1].second;
}


void resuelveCaso() {
	int n; cin >> n;
	long long res = 0;
	vi indx(n);
	vpl monsters(n);
	pl aux;
	long long lastDmg = 0;
	for (int i = 0; i < n; i++) {
		cin >> monsters[i].first >> monsters[i].second;
		if(aux.first > lastDmg) {
			indx.push_back(i);
		}
		lastDmg = aux.second;
	}

	long long maxIni = 1e12;
	int ini;
	for (int idx : indx) {
		long long aux = max(dmged(idx, monsters), maxIni);
		if(maxIni != aux) {
			ini = idx;
			maxIni = aux;
		}
	}

	cout << res << '\n';
}

int main() {
	int T; cin >> T;
	for (int i = 0; i < T; i++) resuelveCaso();
	return 0;
}

