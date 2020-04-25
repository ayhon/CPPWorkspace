#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<long long>;
using vvl = vector<vl>;

int ack(int m, int n) {
	if(m == 0) return n+1;
	if (m > 0 && n == 0) return ack(m-1, 1);
	if(m > 0 && n > 0) return ack(m-1, ack(m, n-1));
}

void resuelveCaso() {
	int m, n; cin >> m >> n;
	while(m >= 0 && n >= 0) {
		cout << ack(m, n) << '\n';
		cin >> m >> n;
	} 
}

int main() {
	resuelveCaso();
	return 0;
}


