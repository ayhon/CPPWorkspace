#include <iostream>
using namespace std;

int main() {
	unsigned int n; cin >> n;
	cout << -n << '\n';
	cout << ((-n ^ -int(n)) == 0? "Sigue convirtiendolo a C2 aunque no lo interprete así" : "Hace algo raro") << '\n';
	return 0;
}
