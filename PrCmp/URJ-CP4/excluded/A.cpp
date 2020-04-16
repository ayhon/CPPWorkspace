#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

const int INF = 1e9 + 7;
using vi = vector<int>;
using vvi = vector<vi>;
using pi = pair<int, int>;
using vpi = vector<pi>;
using vvpi = vector<vpi>;
using vl = vector<long long>;
using vvl = vector<vl>;
vi dist;

struct sortRaro {
	bool operator() (pi p1, pi p2) {
		if(p1.first == p2.first) return p1.second < p2.second;
		else return p1.first < p2.first;
	}
};

void dijkstra(int orig, vvpi const& grafo) {
	priority_queue<pi, vpi, greater<pi> > pq;
	dist[orig] = 0;
	pq.push(make_pair(dist[orig], orig));

	while(!pq.empty()) {
		pi nodoAct = pq.top(); pq.pop();

		if(nodoAct.first > dist[nodoAct.second]) continue;

		for(pi nodoSig : grafo[nodoAct.second]) {
			if(dist[nodoSig.first] > nodoAct.first + nodoSig.second) {
				dist[nodoSig.first] = nodoAct.first + nodoSig.second; 
				pq.push(make_pair(dist[nodoSig.first], nodoSig.first));
			}
		}

	}
}


void resuelveCaso() {
	int N, C; cin >> N >> C;
	vvpi grafo(N);
	int a, b, c;
	for(int i = 0; i < C; i++) {
		cin >> a >> b >> c;
		grafo[a].push_back(make_pair(b,c));
		grafo[b].push_back(make_pair(a,c));
	}
	int o; cin >> o;
	int E; cin >> E;

	dist.clear(); dist.resize(grafo.size(), INF);
	dijkstra(o, grafo);

	vpi tiempos(E);
	for(int i = 0; i < E; i++) {
	pi equipo;
		cin >> equipo.first >> equipo.second;
		tiempos[i] = make_pair(dist[equipo.first] + equipo.second, i);
	}
	sort(tiempos.begin(), tiempos.end(), sortRaro());
	cout << tiempos[0].second;
	for(int i = 1; i < E; i++) {
		int lastTmp = tiempos[i-1].first;
		if(lastTmp == tiempos[i].first) 
			cout << " = ";
		else
			cout << " -> ";

		cout << tiempos[i].second;
	}
	cout << '\n';
}

int main() {
	resuelveCaso();
	return 0;
}
