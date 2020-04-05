#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ii = pair<int, int>;
using iii = pair<ii, int>;

void resuelveCaso() {
    int n; cin >> n;
    vector<iii> tareas(n);
    for (int i = 0; i < n; i++) {
        cin >> tareas[i].first.first >> tareas[i].first.second;
        tareas[i].second = i;
    }

    sort(tareas.begin(), tareas.end());

    int idxC = 0, idxJ = 0;
    bool possible = true;
    vector<char> output(n);
    for (size_t i = 0; i < n && possible; i++) {
        int & iniActual = tareas[i].first.first, 
              finActual = tareas[i].first.second;
        if(iniActual < idxC) {
            if(iniActual < idxJ) {
                possible = false;
            }
            else {
                output[tareas[i].second] = 'J';
                idxJ = finActual;
            }
        }
        else {
            output[tareas[i].second] = 'C';
            idxC = finActual;
        }
    }

    if(possible) {
        for (size_t i = 0; i < n; i++) cout << output[i];
        cout << '\n';
    }
    else {
        cout << "IMPOSSIBLE\n";
    }
    

}

int main() {
    int T; cin >> T;
    for (size_t i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": ";
        resuelveCaso();
    }
    
    return 0;
}