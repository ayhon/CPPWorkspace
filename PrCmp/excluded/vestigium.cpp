#include <iostream>
#include <vector>
#include <utility>
using namespace std;
using ii = pair<int, int>;

int trace(vector<vector<int> > & mat) {
    int res = 0;
    for(int i = 0; i < mat.size(); i++) {
        res += mat[i][i];
    }

    return res;
}

int sumar(int op, vector<vector<int> > & mat, int pos) {
    int res = 0;
    if(op == 0)
        for(int i = 0; i < mat.size(); i++)  {
            res += mat[i][pos];
        }
    else if (op == 1) {
        for(int i = 0; i < mat[0].size(); i++)  {
            res += mat[pos][i];
        }
    }
    return res;
}

int OneToN(int n) {
    return n * (n+1) / 2;
}

bool check(vector<vector<int> > const& mat, int idx, int op) {
    vector<int> apar(mat.size(), 0);
    bool fallo = false;
    if(op == 0) {
        for (size_t i = 0; i < mat.size() && !fallo; i++) {
            apar[mat[i][idx]-1] += 1;
            if (apar[mat[i][idx]-1] > 1)
                fallo = true;
        }
    }
    else if (op == 1) {
        for (size_t i = 0; i < mat.size() && !fallo; i++) {
            apar[mat[idx][i]-1] += 1;
            if(apar[mat[idx][i]-1] > 1)  fallo = true;
        }
        
    }
    return fallo;
}

ii scan(vector<vector<int> > & mat) {
    ii res = make_pair(0,0);
    for (int i = 0; i < mat.size(); i++) {
        if(check(mat,i,0)) res.first++;    
    }

    for (int i = 0; i < mat.size(); i++) {
        if(check(mat,i,1)) res.second++;
    }
    return res;
}

void resuelveCaso() {
    int n; cin >> n;
    vector<vector<int> > mat(n, vector<int> (n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }
    
    ii sol = scan(mat);
    cout << trace(mat) << " " << sol.second << " " << sol.first << '\n';
}

int main() {
    int T, c = 1; cin >> T;
    while(T--) {
        cout << "Case #" << c << ": ";
        resuelveCaso();
        c++;
    }
    return 0;
}

