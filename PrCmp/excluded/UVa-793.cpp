#include <iostream>
#include <climits>
#include <vector>
#include <sstream>
using namespace std;

int T;

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

void resuelveCaso(int caso) {
	int n; cin >> n;	
	cin.ignore(INT_MAX, '\n');
	UFDS ufds(n);

	pair<int, int> sol = make_pair(0,0);

	char action; int op1, op2;
	if(caso == T) cin >> action;
	else cin.get(action);
	while(action == 'c' || action == 'q') {
		cin >> op1 >> op2;
		op1--; --op2;

		if(action == 'c') {
			ufds.join(op1, op2);
		}
		else if (action == 'q') {
			if(ufds.areRelated(op1, op2)) 
				sol.first++;
			else sol.second++;
		}
		if(caso != T) cin.get(action);
		else{
			cin >> action;
			if(!cin) break;
		} 
	}

	cout << sol.first << "," << sol.second << '\n';
}

int main() {
	cin >> T;
	for(int i = 1; i <= T; i++) 
		resuelveCaso(i);
	return 0;
}
