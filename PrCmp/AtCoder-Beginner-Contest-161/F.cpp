#include <iostream>
#include <vector>
#include <set>
using namespace std;
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

vector<bool> criba(10000, true);
vi primes;

void genCriba() {
	criba[0] = false;
	criba[1] = false;
	for (int i = 2; i < criba.size(); i++) {
		if(criba[i])  {
			primes.push_back(i);
			for (int j = 2; j*i < criba.size(); j++)
				criba[i*j] = false;
		}
	}
}

vi factorize(int num) {
	vi factors;
	for (int i = 0; i < primes.size() && num != 1;) {
		if(num % primes[i] == 0){
			num /= primes[i];
			factors.push_back(primes[i]);
		}
		else i++;
	}
}

int main() {
	long long N; cin >> N;
	set<long long> poss;

	genCriba();
	vi factors = factorize(N);

	long long superprod = 1;
	for (long long fact : factors) superprod *= fact;
	for (int i = 0; i < factors.size(); i++) {
		if(superprod/primes[i] % primes[i] == 1)
			poss.insert(primes[i]);
	}
	poss.insert(N);
	poss.insert(N-1);

	cout << poss.size() << '\n';
	return 0;
}
