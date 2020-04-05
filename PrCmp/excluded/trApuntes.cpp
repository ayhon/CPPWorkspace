#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ii = pair<int, int>;

bool resuelveCaso() {
    int n; cin >> n;
    if(n == 0) return false;
    
    vector<ii> inter(n);
    for (size_t i = 0; i < n; i++) {
        cin >> inter[i].first >> inter[i].second;

    }
    sort(inter.begin(), inter.end());
    int idxIni = inter[0].first, idxFin = inter[0].second, res = idxFin - idxIni + 1;
    for (size_t i = 1; i < n; i++) {
        if(inter[i].second > idxFin) {
            idxIni = max(idxFin+1, inter[i].first);
            idxFin = inter[i].second;
            res += idxFin - idxIni + 1;
        }
    }
    cout << res << '\n';
    
    return true;
}

int main() {
    while(resuelveCaso());
    return 0;
}