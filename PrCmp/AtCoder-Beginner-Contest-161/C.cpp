#include <iostream>
using namespace std;

int main() {
	long long N, K;  cin >> N >> K;
	int maxi = max(N, K), mini = min(N,K);
	if(N == 1 || K == 1) cout << 0 << '\n';
	else if(maxi % mini != 0) cout << gcd(N, K) << '\n';
	else cout << 0 << '\n';
	return 0;
}
