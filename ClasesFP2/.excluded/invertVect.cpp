#include <iostream>
#include <vector>
#include <string>
using namespace std;

void invert(vector<int> & v, int ini, int fin) {
	if(fin - ini > 1) {
		int tmp = v[ini];
		v[ini] = v[fin-1];
		v[fin-1] = tmp;
		invert(v, ini+1, fin-1);
	}
}

bool resuelveCaso() {
	int n; cin >> n;
	if(!cin) return false;

	vector<int> v(n);
	for(int & e : v) cin >> e;
	
	invert(v, 0, v.size());
	cout << v[0];
	for(int i = 1; i < v.size(); i++) {
		cout <<  " " << v[i];
	}
	cout << '\n';

	return true;
}

int main() {
	while(resuelveCaso());
	return 0;
}
