#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int digAt(int num, long long pot) {
	return (num % pot) * 10 / pot;
}


int inv(int num, long long pot) {
	// Necesita que pot sea la potencia inmediatamente mayor al número dado
	if(num < 10) return num;
	else return num%10 * pot + inv(num/10, pot/10);
}

void inv2(int pred, int & sol) {
	if(pred < 10)  {
		sol = sol * 10 + pred;
		pred = 0;
	}
	else {
		sol = sol * 10 + pred%10;
		pred /= 10;
		inv2(pred, sol);
	}
}

bool resuelveCaso() {
	int n; cin >> n;
	if(!cin) return false;
	/*
	long long pot;
	for(pot = 1; pot <= n; pot*=10);
	pot/=10;
	cout << inv(n, pot) << '\n';
	*/
	int sol = 0;
	inv2(n, sol);
	cout << sol << '\n';
	
	return true;
}

int main () {
	while(resuelveCaso());
	return 0;
}
