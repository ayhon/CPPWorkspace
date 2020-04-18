#include <iostream>
using namespace std;

char toChar(int n ) {
	return char(n + int('0'));
}

string resolver(long long n) {
	if(n == 0) return "0";
	if(n == 1) return "1";
	else return resolver(n/2) + toChar(n%2);
}

void resuelveCaso() {
	long long n; cin >> n;
	cout << resolver(n) << '\n';
}

int main() {
	int T; cin >> T;
	for(int i = 1; i <= T; i++) {
		resuelveCaso();
	}
	return 0;
}
