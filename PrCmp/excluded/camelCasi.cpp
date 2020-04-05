#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;

struct compCase {
    bool operator()(string const& s1, string const& s2) {
        if(s1.size() != s2.size()) return false;
        int cont;
        int top = s1.size();
        for (size_t i = 0; i < top; i++) {
            if(s1[i] != s2[i]) {
                if(tolower(s1[i] == s2[i])) return true;
                else return true;
            }
        }
        return false;
        
    }
};

string toLowerCase(string const& msg) {
    string res = "";
    for (size_t i = 0; i < msg.size(); i++) {
        res += tolower(msg[i]);
    }
    return res;
}


int main() {
    int n;
    while(cin >> n) {
        map<string, string> vars;
        vector<string> pals(n);
        for (size_t i = 0; i < n; i++) {
            cin >> pals[i];
            bool encontrado = false;
            if(vars[toLowerCase(pals[i])].empty()) {
                vars[toLowerCase(pals[i])] = pals[i];
            }
            else if (vars[toLowerCase(pals[i])] != pals[i]){
                vars[toLowerCase(pals[i])] = min(pals[i], vars[toLowerCase(pals[i])]);
                string prueba = max(pals[i], vars[toLowerCase(pals[i])]);
            }
        }

        for (size_t i = 0; i < n; i++) {
            cout << vars[toLowerCase(pals[i])] << '\n';
        }
        cout << "---\n";
        
    }
    return 0;
}