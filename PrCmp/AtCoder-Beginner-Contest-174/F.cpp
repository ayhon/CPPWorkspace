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
void resuelveCaso() {
	int n, q; cin >> n >> q;
	vi colors;
	for(int i =0; i < n; i++) {
		int col; cin >> col;
		col--;
	}
}

void resuelveCasoNo() {
	int n, q; cin >> n >> q;
	vi dc(n);
	set<int> colors;
	for(int i = 0; i < n; i++) {
		int col; cin >> col;
		if(colors.find(col) == colors.end()) colors.insert(col);
		dc[i] = colors.size();
	}
	for(int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		cout << dc[r-1] - dc[l-1] << endl;
	}
}

int main() {
	int T = 1;
	for (int i = 1; i <= T; i++) {
		//cout << "Case #" << i << ": ";
		resuelveCaso();
	}
	return 0;
}


