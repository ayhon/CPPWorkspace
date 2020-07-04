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
	int n; cin >> n;
	if(!cin) return false;

	vi v(n);
	for(int & e: v) cin >> e;

	int sum = 0, init = 0, lon = 0;
	int sumA = sum, initA = init, lonA = lon;
	for(int i = 0; i < n; i++) {
		if(lonA == 0) initA = i;
		if(v[i]<0) {
			if(sumA > sum) {
				sum = sumA;
				init = initA; 
				lon = lonA;
			}
			sumA = 0;
			lonA = 0;
		}
		else {
			sumA += v[i];
			lonA++;
		}
	}

	cout << sum << " " << init << " " << lon;

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
	//*
	while(resuelveCaso());
	// */
	return 0;
}


