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
	int a, b, c; cin >> a >> b >> c;
	bool print1 = false, print2 = false;
	if (a >= c) {
		print1 = true;
	}
	else if (c/b >= a) print2= true;
	cout << (print1? -1 : 1) << " " << (print2? -1 : b);
}

int main() {
	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		//cout << "Case #" << i << ": ";
		resuelveCaso();
	}
	return 0;
}


