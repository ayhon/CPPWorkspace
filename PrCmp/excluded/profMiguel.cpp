#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
using ii = pair<int, int>;
using vii = vector<ii>;
using vvii = vector<vii>;
using vi = vector<int>;

const int INF = 2000 * 1000 * 1000;

void dijkstra(int posJoven, int posViejo, vvii const& grafoJoven, vvii const& grafoViejo, vii & soluciones) {
    vi distJoven(26, INF); distJoven[posJoven] = 0;
    vi distViejo(26, INF); distViejo[posViejo] = 0;
    
    priority_queue<ii, vii, greater<ii> > pqJ; pqJ.push(make_pair(0, posJoven));
    priority_queue<ii, vii, greater<ii> > pqV; pqV.push(make_pair(0, posViejo));

    set<int> visitedJoven;
    set<int> visitedViejo;

    int nodoActualJ, nodoActualV;
    while(!pqJ.empty() || !pqV.empty()) {
        // Joven
        if(!pqJ.empty()) {
            nodoActualJ = pqJ.top().second;
            int distActualJ = pqJ.top().first;
            pqJ.pop();

            visitedJoven.insert(nodoActualJ);

            if(distActualJ <= distJoven[nodoActualJ]) {
                // if nodoActualJ in visitedViejo
                if(visitedViejo.find(nodoActualJ) != visitedViejo.end()) {
                    int dist = distActualJ + distViejo[nodoActualJ];
                    soluciones.push_back(make_pair(dist, nodoActualJ));
                } 

                for (size_t i = 0; i < grafoJoven[nodoActualJ].size(); i++) {
                    int nodoVecino = grafoJoven[nodoActualJ][i].first;
                    int costeVecino = grafoJoven[nodoActualJ][i].second;
                    
                    if(distActualJ + costeVecino < distJoven[nodoVecino]) {
                        distJoven[nodoVecino] = distActualJ + costeVecino;
                        pqJ.push(make_pair(distJoven[nodoVecino], nodoVecino));
                    }
                }
                
            }
        }
        // Viejo
        if(!pqV.empty()) {
            nodoActualV = pqV.top().second;
            int distActualV = pqV.top().first;
            pqV.pop();

            visitedViejo.insert(nodoActualV);

            if (distActualV <= distViejo[nodoActualV]) {
                // if nodoActualV in visitedJoven
                if(visitedJoven.find(nodoActualV) != visitedJoven.end()) {
                    int dist = distActualV + distJoven[nodoActualV];
                    soluciones.push_back(make_pair(dist, nodoActualV));
                }

                for (size_t i = 0; i < grafoViejo[nodoActualV].size(); i++) {
                    int nodoVecino = grafoViejo[nodoActualV][i].first;
                    int costeVecino = grafoViejo[nodoActualV][i].second;

                    if(distActualV + costeVecino < distViejo[nodoVecino]) {
                        distViejo[nodoVecino] = distActualV + costeVecino;
                        pqV.push(make_pair(distViejo[nodoVecino], nodoVecino));
                    }
                }
                
            }
        }
    }
}

int toInt(char c) {
    return int(c) - int('A');
}

char toChar(int i) {
    return char(i + int('A'));
}

bool resuelveCaso() {
    int n; cin >> n;
    if(n==0) return false;

    vvii grafoJoven(26);
    vvii grafoViejo(26);
    for (size_t i = 0; i < n; i++) {
        char type, direc, o, d;
        int w;
        cin >> type >> direc >> o >> d >> w;
        int x = toInt(o);
        int y = toInt(d);
        if(type == 'Y') {
            grafoJoven[x].push_back(make_pair(y, w));
            if(direc == 'B') grafoJoven[y].push_back(make_pair(x, w));
        }
        else  if(type == 'M'){
            grafoViejo[x].push_back(make_pair(y, w));
            if(direc == 'B') grafoViejo[y].push_back(make_pair(x, w));
        }
        else cout << "CUIDADO, que la has cagado en algo\n";
    }

    char m, p;
    cin >> m >> p;
    vii soluciones;
    dijkstra(toInt(m), toInt(p), grafoJoven, grafoViejo, soluciones);
    if(soluciones.empty()) cout << "You will never meet.";
    else {
        sort(soluciones.begin(), soluciones.end());
        int distMin = soluciones[0].first;
        cout << distMin;
        int i = 0;
        while(i < soluciones.size() && soluciones[i].first == distMin) {
            cout << " " << toChar(soluciones[i].second);
            ++i;
        }
    }
    cout << '\n';
    
    return true;
}

int main() {
    while(resuelveCaso());
    return 0;
}