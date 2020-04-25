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

void hanoi (int numDiscos, char desde, char hacia,char aux) {
	if(numDiscos == 1)  {
		cout << desde << " → " << hacia << '\n';
	}
	else {
		hanoi(numDiscos-1, desde, aux, hacia);
		cout << desde << " → " << hacia << '\n';
		hanoi(numDiscos-1, aux, hacia, desde);
	}
}

bool resuelveCaso() {
	char p1, p2, p3; cin >> p1 >> p2 >> p3;

	
}

int main() {
	while(resuelveCaso());
	return 0;
}


