#include <iostream>
#include <climits>
#include <vector>
using namespace std;

class UFDS {
private:
	vector<int> p;
public:
	int numSets;
	UFDS(int N) : numSets(N), p(N, -1) {}

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
		--numSets;
	}

	int size(int i ) {
		return -p[find(i)];
	}
};

bool resuelveCaso() {
	int n, m; cin >> n >> m;
	if(n == 0) return false;
	UFDS ufds(n);
	for(int i = 0; i < m; i++) {
		int p; cin >> p;
		int member; cin >>member;
		for(int j = 1; j < p; j++) {
			int elem; cin >> elem;
			ufds.join(member, elem);
		}
	}
	cout << ufds.size(0) << '\n';
	return true;
}

int main() {
	while(resuelveCaso());
	return 0;
}

