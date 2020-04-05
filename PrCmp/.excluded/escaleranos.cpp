#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;
vector<int> peld;
vector<long long> memo;

long long resolver(int n) {
    long long res = 0;
    if(memo[n] > -1) return memo[n];
    else if (n == 0) return 1;
    else if (n < 0) return 0;
    else if (memo[n] == -1){
        for (size_t i = 0; i < peld.size(); i++) {
            int dif = n - peld[i];
            if(dif >= 0) {
                memo[dif] = resolver(dif);
                res += (memo[dif] % MOD);
            } 
        }
    }
    return memo[n] = res;
}

bool resuelveCaso() {
    int n, k; cin >> n;
    if(n==0) return false;
    cin >> k;

    memo = vector<long long> (101, -1);
    long long sol;
    peld.resize(k);
    for (size_t i = 0; i < k; i++) {
        cin >> peld[i];
    }

    sol = resolver(n);
    
    cout << (sol % MOD) << '\n';

    return true;
}

int main() {
    while(resuelveCaso());
    return 0;
}