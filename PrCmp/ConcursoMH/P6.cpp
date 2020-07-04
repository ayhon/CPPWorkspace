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

bool resuelveCaso() {
	int n, p; cin >> n >> p;
	if(!cin) return false;

	vvi mat(n, vi(n));
	for(auto v : mat) for(int & e : v) cin >> e;

	vector<vector<int>> subsumas(n, vector<int>(n-2));
	for(int i = 0; i < n; i++) {
		int k = 0;
		for(int j = 0; j < n-2; j++) {
			subsumas[i][j] = mat[i][]
		}
	}

	return true;
}

int main() {
	/*
	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		//cout << "Case #" << i << ": ";
		resuelveCaso();
	
	}
	// */
	///*
	while(resuelveCaso());
	// */
	return 0;
}


