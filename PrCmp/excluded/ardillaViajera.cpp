#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<long long>;
using vvl = vector<vl>;
using pi = pair<int,int>;

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

bool collide(pi & t1, pi & t2, int rad) {
	double dist = sqrt( pow(t1.first - t2.first, 2) + pow(t1.second - t2.second, 2));
	return dist <= rad;
}

bool resuelveCaso() {
	int n, m, rad, numTrees; cin >> n >> m >> rad >> numTrees;
	if(!cin) return false;
	
	vector<pair<int, int> > trees;
	for(int i = 0; i < numTrees; i++){
		pi aux; cin >> aux.first >> aux.second;
		trees.push_back(aux);
	}
	
	UFDS relTrees(numTrees);
	bool found = false;
	int i = 0;
	for(i = numTrees-1; i >= 0 && !found; i--){
		pi & currentTree = trees[i];
		if(currentTree.first - rad <= 0) relTrees.touchNorth[relTrees.find(i)] = true;
		if(currentTree.first + rad >= n)  relTrees.touchSouth[relTrees.find(i)] = true;
		bool finished = false;
		for(int j = i+1; j < numTrees && !finished; j++) {
			pi & pastTree = trees[j];
			if(collide(pastTree, currentTree, rad)) {
				relTrees.join(i, j);
				finished = true;
			}
		}
		int parent = relTrees.find(i);
		if(relTrees.touchNorth[parent] && relTrees.touchSouth[parent]) found = true;
	}

	if (found) 
		cout << trees[i+1].first << " " << trees[i+1].second << '\n';
	else 
		cout << "NUNCA SE PUDO\n";

	return true;
}

int main() {
	while( resuelveCaso());
	return 0;
}


