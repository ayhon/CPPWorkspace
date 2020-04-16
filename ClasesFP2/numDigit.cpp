#include <iostream>
using namespace std;

int numDig(long long num) {
	if(num < 10) return 1;
	else return 1 + numDig(num/10);
}

bool resuelveCaso() {
	long long num; cin >> num;
	if(!cin) return false;

	cout << numDig(num) << '\n';

	return true;
}

int main() {
	while(resuelveCaso());
}
