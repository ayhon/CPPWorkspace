#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> memo(1000001,-1);

int resolver(int n) {
    if(memo[n] == -1) {
        int mid = n/2, sol = resolver(n - mid) + resolver(mid+1) - 1;
        return memo[n] = sol;
    }
    else {
        return memo[n];
    }
}

int resolver2(int n) {
}
bool resuelveCaso() {
    int n; cin >> n;
    if(n == 0) return false;
    cout << resolver(n) << '\n';
    return true;
}

int main() {
    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 1;
    memo[3] = 2;
    memo[4] = 2;
    memo[5] = 3;
    while(resuelveCaso());
    return 0;
}