#include <iostream>
using namespace std;

long long prod(long long a, long long b) {
	if(b == 0) return 0;
	if(b == 1) return a;
	if(b%2 == 0) return prod(2*a, b/2);
	else return prod(2*a,b/2) + a;
}

void resuelveCaso() {
	long long a, b; cin >> a >> b;
	cout << prod(a,b) << '\n';
}

int main() {
	int T; cin >> T;
	for(int i = 1; i <= T; i++) resuelveCaso();
	return 0;
}
