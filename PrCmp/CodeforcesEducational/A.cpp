#include <iostream>
using namespace std;

void resuelveCaso() {
	int n; cin >> n;
	pair<int, int> input, last = make_pair(0,0);
	bool ok = true;
	for(int i = 0; i < n; i++) {
		cin >> input.first >> input.second;
		if(input < last || ((input.first == last.first) && last.second != input.second)) ok = false;
		last = input;
	}

	cout << (ok? "YES" : "NO") << '\n';
}

int main() {
	int T; cin >> T;
	for(int i = 0; i < T; i++) resuelveCaso();
	return 0;
}
