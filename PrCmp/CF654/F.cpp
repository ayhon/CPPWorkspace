#include <iostream>
#include <climits>
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

void flip(vector<bool> & conv, int l, int r) {
	for(int i = l; i <= r; i++) {
		conv[i] = !conv[i];
	}
}

int scan(vector<bool> const& conv, int l, int r) {
	int maxi = 0, current = 0;
	bool toRight = false;
	if(conv[l]) {
		toRight = true;
		current = 1;
	}
	else {
		maxi = 1;
	}

	for(int i = l+1; i <= r; i++) {
		if(conv[i] && !toRight) {
			maxi = max(maxi, current);
			current = 1;
		}
		else current++;

		toRight = conv[i];
	}
	
	return maxi;
}

void query(vector<bool> & conv, int l, int r) {
	flip(conv, l, r);
	cout << scan(conv, l, r) << '\n';
	
}

void resuelveCaso() {
	int n, q; cin >> n >> q;
	cin.ignore(INT_MAX, '\n');
	vector<bool> conv(n, false);
	for(int i =0; i < n; i ++) {
		char aux; cin.get(aux);
		if(aux == '>') conv[i] = true;
	}
	for(int i = 0; i < q; i++){
		int l, r; cin >> l >> r;
		l--; --r;
		query(conv, l, r);
	}
}

int main() {
	resuelveCaso();
	return 0;
}


