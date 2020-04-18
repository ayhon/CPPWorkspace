#include <iostream>
#include <string>
using namespace std;

long long elimPares(long long num) {
	if(num < 10) return (num%2==0? 0 : num);

	int dig = num%10;
	long long res;
	if(dig%2==0) res =  elimPares(num/10);
	else res = dig + 10*elimPares(num/10);
	return res;
}


bool resuelveCaso() {
	long long n; cin >> n;
	if (!cin) return false;
	long long sol = elimPares(n);
	cout << sol << '\n';

	return true;
}

int main() {
	while(resuelveCaso());
	return 0;
}
