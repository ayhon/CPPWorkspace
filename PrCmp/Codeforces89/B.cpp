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

void resuelveCaso() {
	int n, x, m; cin >> n >> x >> m;
	x--;
	int intTop = x, intBot = x;
	for(int i = 0; i < m; i++) {
		int l, r; cin >> l >> r;
		l--; --r;
		if(intTop < l || intBot > r) continue;
		else {
			intBot = min(intBot, l);
			intTop = max(intTop, r);
		}
	}
	cout << intTop - intBot + 1 << '\n';
}

int main() {
	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		resuelveCaso();
	}
	return 0;
}


