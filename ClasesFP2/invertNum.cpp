#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int digAt(int num, long long pot) {
	return (num % pot) * 10 / pot;
}


int inv(int num, long long pot) {
	if(num < 10) return num;
	else return num%10 * pot + inv(num/10, pot/10);
}

bool resuelveCaso() {
	int n; cin >> n;
	if(!cin) return false;
	long long pot;
	for(pot = 1; pot <= n; pot*=10);
	pot/=10;

	cout << inv(n, pot) << '\n';
	
	return true;
}

int main () {
	while(resuelveCaso());
	return 0;
}
