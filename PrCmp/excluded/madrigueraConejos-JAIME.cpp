#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <queue>
#include <functional>

using namespace std;

using ll = long long int;
using vi = vector <int>;
using vvi = vector <vi>;
using ii = pair <int, int>;
using vii = vector <ii>;
using vvii = vector <vii>;
using vb = vector <bool>;
using vvb = vector <vb>;
#define mp make_pair

const int INF = 1000 * 1000 * 1000;


bool resuelveCaso() {
	int n; cin >> n;
	if (n == 0) return false;

	vi v(n);
	priority_queue <ii, vii, greater <ii> > pq;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	pq.push(mp(v[0], 0));
	ll sol = 0;
	for (int i = 1; i < n; ++i) {
		while (!pq.empty() && v[i] > pq.top().first) {
			sol = sol + ll((i - pq.top().second));
			pq.pop();
		}
		pq.push(mp(v[i], i));
	}
	while (!pq.empty()) {
		sol = sol + ll((n - pq.top().second));
		pq.pop();
	}
	cout << sol << '\n';

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}
