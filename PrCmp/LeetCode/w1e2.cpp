#include <iostream>
#include <set>
using namespace std;

bool isHappy(int n) {
	int aux = n;
	int suma;
	set<int> nums;
	while(nums.find(aux) == nums.end() && aux != 1) {
		suma = 0;
		nums.insert(aux);
		while(aux) {
			suma += (aux%10) * (aux%10);
			aux /= 10;
		}
		aux = suma;
	}
	return aux == 1;
}

int main() {
	int n; cin >> n;
	cout << (isHappy(n)? "true" : "false") << '\n';
}
