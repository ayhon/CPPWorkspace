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
	int n, p; cin >> n >> p;
	vector<int> a(n); 
	for(int & e : a) cin >> e;

	sort(a.begin(), a.end());
	int res = 0;
	if(a.back() > n)
	
}

int main() {
	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		//cout << "Case #" << i << ": ";
		resuelveCaso();
	}
	return 0;
}


