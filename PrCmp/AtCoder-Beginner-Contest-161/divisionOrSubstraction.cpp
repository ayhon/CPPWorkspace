#include <iostream>
#include <set>
#include <vector>
#include <cmath>
using namespace std;
using vi = vector<long long>;
using ii = pair<long long, long long>;
using vii = vector<ii>;

vector<bool> criba(1000000, true);
vi primes;

void genCriba() {
	criba[0] = false;
	criba[1] = false;
	for (long long i = 2; i < criba.size(); i++) {
		if(criba[i])  {
			primes.push_back(i);
			for (long long j = 2; j*i < criba.size(); j++)
				criba[i*j] = false;
		}
	}
}

vi factorize(long long num) {
	vi factors;
	for (int i = 0; i < primes.size() && num != 1;i++) {
		int cont = 1;
		while(num % primes[i] == 0){
			num /= primes[i];
			factors.push_back( pow(primes[i],cont) );
			cont++;
		}
	}
	return factors;
}

bool check(long long n, long long N) {
	while(N % n == 0) N /= n;
	return (N % n == 1);
}

int main() {
	long long N; cin >> N;
	set<long long> sol;
	//int limit = sqrt(N);
	genCriba();
	vi factorsN = factorize(N);
	vi factorsAnt = factorize(N-1);
	for(long long fact : factorsN) {
		if(check(fact, N)) 
			sol.insert(fact);
	}
	cout << sol.size() + factorsAnt.size() + 1 << '\n';
	return 0;
}
