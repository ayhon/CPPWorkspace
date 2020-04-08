#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
#include <vector>
using namespace std;

const long long INF = LLONG_MAX;

bool resuelveCaso() {
    long long n; cin >> n;
    if(n==0) return false;

    vector<long long> d(n+1);
    d[n] = INF;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    
    priority_queue<long long, vector<long long>, greater<long long> > dAnt;
    dAnt.push(d[0]);
    long long sol = 0;
    for (size_t i = 1; i < d.size(); i++) {
        sol += dAnt.size();
        while(!dAnt.empty() && dAnt.top() <= d[i]) {
            dAnt.pop();
        } 
        dAnt.push(d[i]);
    }
    
    cout << sol << '\n';

    return true;
}

int main() {
    while(resuelveCaso()); 
    return 0;
}