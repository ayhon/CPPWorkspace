#include <bits/stdc++.h>
using namespace std;

void resuelveCaso() {
	int n; cin >> n;
	string s, sol = ""; cin >> s;

	assert(s.size() == 2 * n - 1);

	for(int i = 0; i < s.size(); i += 2) sol += s[i];
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


