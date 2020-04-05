#include <iostream>
#include <vector>
using namespace std;
using ii = pair<int, int>;
using vii = vector<ii>;

const vector<ii> movsAltos = {make_pair(1,2), make_pair(1,-2)};
const vector<ii> movsBajos = {make_pair(2,1), make_pair(2,-1)};
vector<vector<bool> > mat;

bool valid(ii ant, ii pos) {
    return ant.first == pos.first || ant.second == pos.second || ant.first - ant.second == pos.first - pos.second || ant.first + ant.second == pos.first + pos.second;
}

ii operator+(ii const& i1, ii const& i2) {
    return make_pair((i1.first + i2.first + mat.size()) % mat.size(), (i1.second + i2.second + mat[0].size()) % mat[0].size());
}

void visitar(ii pos, vector<vector<bool> > & mat) {
    mat[pos.first][pos.second] = true;
}

vii resolverPicos(int maxi, int mini) {
    vii movimientos;
    int x = mini, y = maxi;
    mat.clear();
    mat.resize(x, vector<bool> (y, false));
    ii pos;
    
    for (int i = 0; i < y; i++) {
        pos = make_pair(0,i);
        movimientos.push_back(pos);
        visitar(pos, mat);
        for (int j = 1; j < x; j++) {
            pos = pos + movsAltos[((j+1)%2)];
            if(mat[pos.first][pos.second]) cout << "\e[32;1mERROR\e[m " << pos.first << "-" << pos.second << " ya visitado.\n";
            movimientos.push_back(pos);
            visitar(pos, mat);
        }
    }
    
    return movimientos;
}

vii resolverEscalando(int maxi, int mini) {
    vii movimientos;
    int x = mini, y = maxi;
    if(mini != 2) return resolverPicos(maxi, mini);
    else  {
        ii pos = make_pair(0,0);
        mat.clear();
        mat.resize(x, vector<bool>(y, false));
        for(int i = 0; i < maxi && !mat[0][i]; i++) {
            pos = make_pair(0,i);
            for (size_t j = 0; j < mini; j++) {
                pos = make_pair(j,i);
                movimientos.push_back(pos);
                visitar(pos, mat);
                while (pos.second < y - 2) {
                    pos = pos + make_pair(1, 2);
                    movimientos.push_back(pos);
                    visitar(pos, mat);
                }
            }
        }
    }
    return movimientos;
}

void resuelveCaso() {
    int rows, columns; cin >> rows >> columns;
    bool possible = max(rows, columns) + min(rows, columns) >= 7;

    if(possible) {
        cout << "POSSIBLE\n";
        int n = max(rows, columns);
        int m = min(rows, columns);
        vii movimientos;
        if (m != 2) 
            movimientos = resolverPicos(n, m);
        else 
            movimientos = resolverEscalando(n, m);
        for (size_t i = 0; i < movimientos.size(); i++) {
            cout << movimientos[i].first << " ";
            cout << movimientos[i].second << '\n';
        }
        
    }
    else cout << "IMPOSSIBLE\n";
}

int main() {
    int T; cin >> T;
    // while(true) { int aux1, aux2; cin >> aux1 >> aux2; cout << aux1 % aux2 << '\n'; }
    for (size_t i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        resuelveCaso();
    }
    
    return 0;
}
