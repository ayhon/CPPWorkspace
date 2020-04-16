#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void resuelveCaso() {
	int n, x; cin >> n >> x;
	vector<int> money(n);
	int suma = 0;
	for (int i = 0; i < n; i++) {
		cin >> money[i];
		suma += money[i];
	}
	sort(money.begin(), money.end());
	int mPp = suma / n, i = 1;
	while(mPp < x && i < n) {
		suma -= money[i-1];
		mPp = suma / (n-i);
		i++;
	}

	if(mPp >= x) cout << n - i + 1 << '\n';
	else cout << 0 << '\n';
}

int main() {
	int T; cin >> T;
	for (int i = 0; i < T; i++) resuelveCaso();
	return 0;
}
