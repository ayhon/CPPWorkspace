#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <climits>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;

using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;
using vvi = vector<vi>;
using vvpi = vector<vpi>;
using pl = pair<long long, long long>;
using vl = vector<long long>;
using vpl = vector<pl>;
using vvl = vector<vl>;
using vvpl = vector<vpl>;

int resolver(vi const& a, vi const& b, int ini, int fin) {
	int mid = ini + (fin-ini)/2;
	if(fin == ini) return a[ini];
	if(b[mid] > a[mid]) {
		return resolver(a, b, ini, mid);
	}
	else {
		return resolver(a, b, mid+1, fin);
	}
}

void resuelveCaso() {
	int n; cin >> n;
	vi a(n);
	vi b(n-1);
	for(int & e : a) cin >> e;
	for(int & e : b) cin >> e;

	cout << resolver(a,b,0, a.size()-1) << '\n';
}

int main() {
	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		//cout << "Case #" << i << ": ";
		resuelveCaso();
	}
	return 0;
}


