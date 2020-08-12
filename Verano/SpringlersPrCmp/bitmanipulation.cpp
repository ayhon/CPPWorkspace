#include <bits/stdc++.h>
using namespace std;

void printBin(int n) {
	// cout << (n<0? 1 : 0);
	for(int i = 31; i >= 0; i--) 
		cout << (n & (1<<i)? 1 : 0 );
	cout << '\n';
}

int main() {
	int n; cin >> n;
	printBin(n);
	cout << "__builtin_clz: " << __builtin_clz(n);
	cout << " (Count of the left zeroes)\n";
	cout << "__builtin_ctz: " << __builtin_ctz(n);
	cout << " (Count of the right zeroes)\n";
	cout << "__builtin_popcount: " << __builtin_popcount(n);
	cout << " (Number of 1s)\n";
	cout << "__builtin_parity: " << __builtin_parity(n);
	cout << " (Parity of the number of 1s)\n";
	return 0;
}


