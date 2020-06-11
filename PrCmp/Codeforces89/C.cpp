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
	int n, m; cin >> n >> m;
	vi diags(n+m-1);

	int aux; 
	for(int i = 0; i < n; i++) {
		for(int j =0; j < m; j++) {
			cin >> aux;
			diags[i+j] += aux;
		}
	}

	int sol = 0;
	for(int i = 0, j = diags.size()-1; i < j; i++, j--) {
		int numUnos = diags[i] + diags[j],
			elemDiag = min({n,m,i+1});

		sol += min(numUnos /*Si cambiamos 1 a 0*/, 2*elemDiag - numUnos /* Si cambiamos 0 a 1*/);
	}
	
	cout << sol << '\n';
}

int main() {
	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		//cout << "Case #" << i << ": ";
		resuelveCaso();
	}
	return 0;
}


