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

bool check(string const& w, int x, string const& pos) {
	string s = w;
	for(int i = 0; i < w.size(); i++) {
		int op1 = 0, op2 = 0;
		if(i - x >= 0) {
			op1 = w[i-x] - '0';
		}
		if(i + x < s.size()) {
			op2 = w[i+x] - '0';
		}
		s[i] =(char) (op1 | op2) + '0';
	}

	return s == pos;
}

void resuelveCaso() {
	string s; cin >> s;
	int x; cin >> x;

	string w = s;
	
	for(int i = 0; i < s.size(); i++) {
		if(i - x >= 0) {
			w[i-x] = s[i];
		}
		if(i + x < s.size()) {
			w[i+x] = s[i];
		}
	}

	if(check(w,x,s)) cout << w << '\n';
	else cout << -1 << '\n';

}

int main() {
	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		//cout << "Case #" << i << ": ";
		resuelveCaso();
	}
	return 0;
}


