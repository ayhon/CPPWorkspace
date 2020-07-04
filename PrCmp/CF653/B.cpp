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

int quePot2(int num, int ini = 0, int fin = 31) {
	if(num == 1) return 0;
	if(num == 2) return 1;
	if(fin - ini <= 1) return ini;

	int mid = ini + (fin-ini)/2;
	if(num == 1<<mid) return mid;
	if(num >  1<<mid) return quePot2(num, mid, fin);
	if(num <  1<<mid) return quePot2(num, ini, mid);
}

void resuelveCaso() {
	int n; cin >> n;
	int sol = 0, aux = n;
	while(aux%3 == 0 && aux>0) {
		aux /= 3;
		sol++;
	}
	if(aux==1) cout << 2*sol << '\n';
	else {
		int pot = quePot2(aux);
		if(pot <= sol && aux == 1<<pot)  {
			cout << 2*sol - pot << '\n';
		}
		else cout << -1 << '\n';
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


