#include <bits/stdc++.h>
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

double dist(long long x, long long y) {
	return sqrt(x*x + y*y);
}

void resuelveCaso() {
	int n; double d; cin >> n >> d;
	long long x, y, c = 0;
	for(int i = 0; i < n; i++) {
		cin >> x >> y;
		if( dist(x,y) <= d ) c++;
	}
	cout << c << endl;
}

int main() {
	int T=1;
	for (int i = 1; i <= T; i++) {
		//cout << "Case #" << i << ": ";
		resuelveCaso();
	}
	return 0;
}


