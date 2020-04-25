#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <set>
#include <algorithm>
using namespace std;

int hallarVect(vector<int> const& vct, int ini, int fin) {
	if(fin - ini <= 2) return min(vct[ini], vct[fin-1]);
	int mid = ini + (fin - ini)/2;
	if (vct[mid-1] > vct[mid] && vct[mid+1] > vct[mid]) return vct[mid];

	if(vct[mid-1] < vct[mid]) return hallarVect(vct, ini, mid );
	else return hallarVect(vct, mid, fin);
}

bool resuelveCaso() {
	int tamVct; cin >> tamVct;
	if(!cin) return false;

	vector<int> curva(tamVct);
	int mini = INT_MAX;
	for(int & e: curva) {
		cin >> e;
		mini = min(e, mini);
	}
	cout << hallarVect(curva, 0, curva.size()) << '\n';

	return true;
}

int main() {
	while(resuelveCaso());
	return 0;
}


