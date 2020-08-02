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
	int n; cin >> n;
	vi stones(n, 0);
	string s; cin >> s;
	int numW = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == 'W'){
			numW++;
			stones[n-i-1] = 1; 
		} 
	}
	int moves = 0;
	for(int i = 0; i < numW; i++) {
		if (stones[i] == 0) moves++;
	}
	cout << moves << endl;

}

int main() {
	int T = 1;
	for (int i = 1; i <= T; i++) {
		//cout << "Case #" << i << ": ";
		resuelveCaso();
	}
	return 0;
}


