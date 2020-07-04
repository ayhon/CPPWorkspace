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
	long long a, b, n, m; cin >> a >> b >> n >> m;
	bool answer = true;

	if(n+m > a+b) answer = false;
	else if((a == 0 || b == 0) && m != 0) answer = false;
	if(min(a,b) < m && max(a,b) - n < m && abs(a-b) < n) answer = false;

	cout << (answer? "YES" : "NO") << '\n';
}

int main() {
	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		//cout << "Case #" << i << ": ";
		resuelveCaso();
	}
	return 0;
}


