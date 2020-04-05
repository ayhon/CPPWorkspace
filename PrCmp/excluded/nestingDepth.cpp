#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;

void ponerParentesis(string & s, int cant) {
    if (cant > 0) {
        for (size_t i = 0; i < cant; i++) s += "(";
    }
    else if (cant < 0) {
        cant *= (-1);
        for (size_t i = 0; i < cant; i++) s += ")";
    }
}

int toInt(char c) {
    return int(c) - int('0');
}

void resuelveCaso() {
    string S, res;
    cin >> S;

    int pre = 0;
    for (size_t i = 0; i < S.length(); i++) {
        int dif = toInt(S[i]) - pre;
        pre = toInt(S[i]);
        ponerParentesis(res, dif);
        res += S[i];
    }
    ponerParentesis(res, -1*toInt(S.back()));
    cout << res << '\n';
}

int main() {
    int T; cin >> T;
    for (size_t i = 1; i <= T; i++) {
       cout << "Case #" << i << ": ";
       resuelveCaso(); 
    }
    
    return 0;
}