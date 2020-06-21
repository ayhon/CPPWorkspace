#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <climits>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;

class UFDS {
private:
	vector<int> p;
public:
	vector<bool> touchNorth;
	vector<bool> touchSouth;
	int numSets;
	UFDS(int N) : numSets(N), p(N, -1),touchSouth(N, false), touchNorth(N, false) {}

	int find(int i ) {
		return (p[i] < 0? i : p[i] = find(p[i]));
	}

	bool areRelated(int i, int j) {
		return find(i) == find(j);
	}

	void join(int i, int j) {
		int x = find(i), y = find(j);
		if(x==y) return;
		if(p[x] < p[y])  // |p[x]| > |p[y]|
			swap (x,y); // Cogemos y como grande, x como pequeño
		p[y] += p[x]; p[x] = y;
		touchNorth[y] = touchNorth[y] || touchNorth[x];
		touchSouth[y] = touchSouth[y] || touchSouth[x];
		--numSets;
	}

	int size(int i ) {
		return -p[find(i)];
	}
};

using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;
using vvi = vector<vi>;
using vvpi = vector<vpi>;
using pl = pair<long long, long long>;
using vl = vector<long long>;
using vpl = vector<pl>;
using vvl = vector<vl>;
using vvpl = vector<vpl>;

pair<int, int> resolver(priority_queue<pair<int, pair<int, int>>> & cables) {
	UFDS arm(cables.size());
	auto pq = cables; pi suma = {0, 0};
	while(!pq.empty() && arm.numSets != 1) {
		int x = pq.top().second.first, y = pq.top().second.second;
		if(arm.areRelated(x,y)){ 
			suma += pq.top().first;
			arm.join(x, y);
		}

		pq.pop();
	}

	return suma;
}

void resuelveCaso() {
	int schools, connects; cin >> schools >> connects;
	priority_queue<pair<int, pair<int, int>>> cables;
	for(int i = 0; i < connects; i++) {
		int aux1, aux2, aux3; cin >> aux1 >> aux2 >> aux3; aux1--; --aux2;
		cables.push({aux3, make_pair(aux1, aux2)});
	}
	/*
	vvpi grafo;
	for(int i = 0; i < connects; i++) {
		int aux1, aux2, aux3; cin >> aux1 >> aux2 >> aux3; aux1--; --aux2;
		grafo[aux1].push_back({aux2, aux3});
		grafo[aux2].push_back({aux1, aux3});
	}
	*/
	int sol1 = resolver(cables), sol2;
	cables.pop(); sol2 = resolver(cables);

}

int main() {
	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		//cout << "Case #" << i << ": ";
		resuelveCaso();
	}
	return 0;
}


