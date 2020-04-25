// LeetCode challenge.
// Week 3, exercise 5
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

int pivotSearch(vector<int> const& vct, int ini, int fin) {
	if(fin - ini <= 2) return min(vct[ini], vct[fin-1]);

	int mid = (ini + fin)/2, last = vct.back();
	bool bajaLeft = vct[mid-1] > vct[mid];
	bool bajaRight = vct[mid] > vct[mid+1];

	if(!bajaLeft) return min(vct[mid], vct[mid-1]);
	if(!bajaRight) return min(vct[mid+1], vct[mid]);

	if(vct[mid] > last) return pivotSearch(vct, ini, mid);
	else return pivotSearch(vct, mid, fin);
}

bool resuelveCaso() {
	int tamVct; cin >> tamVct;
	if(!cin) return false;

	vector<int> vct(tamVct);
	for(int & e : vct) cin >> e;

	if(vct.front() > vct.back()) cout << vct.back();
	else cout << pivotSearch(vct, 0, vct.size());

	cout  << '\n';
	
	return true; 
}

int main() {
	while(resuelveCaso());
	return 0;
}


