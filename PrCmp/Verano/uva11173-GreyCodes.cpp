#include <iostream>
using namespace std;

void resuelveCaso() {
	int n, k; cin >> n >> k;

	cout << (k^(k>>1))<< '\n';
}

int main() {
	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		//cout << "Case #" << i << ": ";
		resuelveCaso();
	}
	return 0;
}


