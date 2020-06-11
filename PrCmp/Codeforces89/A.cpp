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
	int a, b; cin >> a >> b;
	if(a > b) swap(a,b);

	if(b < 2 || a == 0) cout << 0;
	else if(b >= 2*a) cout << a;
	else cout << (a+b)/3;
	cout << '\n';
	 /*
		O también podía haber puesto

	int a, b; cin >> a >> b;
	if(a > b) swap(a,b);
	cout << (b >= 2*a? a : (a+b)/3) << '\n';

		Que básicamente hace lo mismo, pero es más rápido.
	  */
}

int main() {
	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		resuelveCaso();
	}
	return 0;
}


