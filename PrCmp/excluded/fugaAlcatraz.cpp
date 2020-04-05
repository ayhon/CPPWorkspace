#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
using ii = pair<double, double>;
using vii = vector<ii>;

const int VIS = 10;

vector<int> parent;

int findRoot(int i){
    if(parent[i] == i) return i;
    else return findRoot(parent[i]);
    return -1;
}

bool collide(ii const& p1, ii const& p2) {
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second)) <= 2*VIS;
}

bool resuelveCaso() {
    int b, h, n; cin >> b;
    if(b == 0) return false;
    cin >> h >> n;
    bool sePuede = true;

    parent = vector<int> (n);
    vector<bool> tocaEste(n, false);
    vector<bool> tocaOeste(n, false);
    
    vector<ii> pos(n);
    for (size_t i = 0; i < n; i++) {
        cin >> pos[i].first >> pos[i].second;
        parent[i] = i;
    }

    size_t i;
    for (i = 0; i < n && !(tocaOeste[i] && tocaEste[i]); i++) {
        if (pos[i].first <= VIS) {
            tocaEste[findRoot(i)] = true;
        }
        else if (pos[i].first >= b-VIS) {
            tocaOeste[findRoot(i)] = true;
        }

        bool found = false;
        for(int j = 0;j < i && !found; j++) {
            if(collide(pos[j], pos[i])) {
                found = true;
                parent[i] = j;
                if(tocaEste[i]){
                    tocaEste[findRoot(j)] = true;
                }
                else if(tocaOeste[i]) {
                    tocaOeste[findRoot(j)] = true;
                }
            }
        }

    }

    for (int i = 0; i < n; i++) {
        if(tocaOeste[i] && tocaEste[i]) sePuede = false;
    }
    

    if(sePuede) cout << "SI\n";
    else cout << "NO\n";

    return true;
}

int main() {
    while(resuelveCaso());   
    return 0;
}