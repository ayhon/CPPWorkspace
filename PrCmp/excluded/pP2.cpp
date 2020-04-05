#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ii = pair<int, int>;
using iii = pair<ii, int>;

bool superponen(ii const& a, ii const& b) {
    return a.second > b.first && b.second > a.first;
}

struct tInter {
    int i, s;
};

void resuelveCaso() {
    int n; cin >> n;
    vector<iii> tareas(n);

    for (size_t i = 0; i < n; i++) {
        cin >> tareas[i].first.first >> tareas[i].first.second;
        tareas[i].second = i;
    }

    sort(tareas.begin(), tareas.end());

    bool imposible = false;
    vector<char> output(n, '_');
    ii supAct = make_pair(-1, -1), subsupAct = make_pair(-1, -1);
    for (size_t i = 0; i < n && !imposible; i++) {
        if (superponen(supAct, tareas[i].first)) {
            if (superponen(subsupAct, tareas[i].first)) {
                imposible = true;
            }
            else {
                output[i] = 'J';
                subsupAct = tareas[i].first;
            }
        }
        else {
            output[i] = 'C';
            supAct = tareas[i].first;
        }
    }

    if (imposible)
        cout << "IMPOSSIBLE\n";
    else {
        for (size_t i = 0; i < n; i++) cout << output[i];
        cout << '\n';
    }
}

int main() {
    int T; cin >> T;
    for (size_t i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        resuelveCaso();
    }
    return 0;
}