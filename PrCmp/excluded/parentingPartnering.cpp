#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ii = pair<int, int>;
using iii = pair<ii, int>;

bool superp(ii const& i1, ii const& i2) {
    return i1.second > i2.first && i2.second > i1.first;
}

void resuelveCaso() {
    int N;
    cin >> N;
    vector<ii> inter(2*N);
    vector<iii> schedule(N);

    for (size_t i = 0; i < N; i++) {
        cin >> schedule[i].first.first >> schedule[i].first.second;
        schedule[i].second = i;
        inter[2*i].first = schedule[i].first.first;
        inter[2*i+1].first = schedule[i].first.second;
        inter[2*i].second = 1;
        inter[2*i+1].second = 0;
    }

    sort(inter.begin(), inter.end());
    sort(schedule.begin(), schedule.end());
    
    int cont = 0;
    for (size_t i = 0; i < N && cont < 3; i++) {
        if(inter[i].second == 1) cont++;
        else if(inter[i].second == 0) cont--;
    }

    if(cont == 3) cout << "IMPOSSIBLE\n";
    else {
        vector<char> output(N);
        ii actual = make_pair(-1,-1);
        for (size_t i = 0; i < N; i++) {
            if(superp(actual, schedule[i].first)) {
                output[schedule[i].second] = 'J';
            }
            else {
                actual = schedule[i].first;
                output[schedule[i].second] = 'C';
            }
        }
        for (size_t i = 0; i < N; i++) cout << output[i];
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