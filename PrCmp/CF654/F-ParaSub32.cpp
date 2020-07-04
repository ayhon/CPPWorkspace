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

// Query part 1
void flip (int & n, int l, int r) {
	int mascara = (1<<r)-1 - (1<<l)-1;
	int aux = mascara & -n-1;
	n = n & ~mascara + aux;
}

// Query part 2
int scan (int & n, int l, int r) {
	int maxi = 0;
	bool enUnos = false;
	int current = 0;
	if (1<<(l-1)) {
		enUnos = true;
		current = 1;
	}
	else maxi = 1;

	for(int i = 1; i < r-l; i++) {
		int bit = n & 1<<(l-1+i);
		if(bit && !enUnos) {
			maxi = max(maxi, current);
			current = 1;
		}
		else current++;

		if(bit) enUnos = true;
		else enUnos = false;
	}
	return maxi;
}


void resuelveCaso() {
	int n, q; cin >> n >> q;
	for(int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		flip(n, l, r);
		cout << scan(n, l, r) << '\n';
	}
	
}

int main() {
	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		//cout << "Case #" << i << ": ";
		resuelveCaso();
	}
	return 0;
}


