#include <iostream>
#include <vector>
using namespace std;

int countEven(int val) {
	if(val%2 == 0) return 1;
	else return 0;
}

int rec1(vector<int> & v, int ini, int fin) {
	if(fin - ini == 1) return countEven(v[fin-1]);
	else {
		return rec1(v, ini, fin -1) + countEven(v[fin-1]);
	}
	
}
int rec2(vector<int> & v, int ini, int fin) {
	if(fin - ini == 1) return countEven(v[ini]);
	else {
		return rec1(v, ini+1, fin) + countEven(v[ini]);
	}
}
int rec3(vector<int> & v, int ini, int fin) {
	if(fin - ini == 1) return countEven(v[ini]);
	else {
		int mid = (fin + ini) / 2;
		return rec3(v, ini, mid) + rec3(v, mid, fin);
	}
}

bool resuelveCaso() {
	int n; cin >> n;
	if(!cin) return false;

	vector<int> v(n);

	for(int & e : v) {
		cin >> e;
	}

	cout << rec1(v, 0, v.size()) << '\n';
	cout << rec2(v, 0, v.size()) << '\n';
	cout << rec3(v, 0, v.size()) << '\n';

	return true;
}


int main() {
	while(resuelveCaso());
	return 0;
}
