#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cassert>
#include <cmath>
#include <climits>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;

class SegmentTree {
	private:
		vector<int> segmenttree;
		int tam;
	public:

	SegmentTree(int maxN) {
		segmenttree.assign(4* maxN + 10, 0);
	}

	SegmentTree(vector<int> & values) {
		segmenttree.assign(4 * values.size() + 10, 0);
		build(values);
	}

	bool empty() {
		return segmenttree.empty();
	}

	void build(vector<int> & values) {
		tam = values.size();
		build(values, 1, 0, tam-1);
	}

	void build(vector<int> & values, int p, int l, int r) {
		if (l == r) {
			segmenttree[p] = values[l];
			return;
		}
		int m = (l+r)/2;
		build(values, 2*p, l, m);
		build(values, 2*p+1, m+1, r);
		segmenttree[p] = segmenttree[2*p]+segmenttree[2*p+1];
	}

	int query(int a, int b) {
		return query(1, 0, tam-1, a, b);
	}

	int query(int vertex, int L, int R, int i, int j) {

		if (i > R || j < L) {
			return 0;
		}

		if (L >= i && R <= j)
			// Segmento completamente dentro de la consulta
			return segmenttree[vertex];

		int mitad = (L + R) / 2;

		return query(2*vertex, L, mitad, i, j) +
			query(2*vertex+1, mitad+1, R, i, j);
	}

	void update(int pos, int newVal) {
		update(1, 0, tam-1, pos, newVal);
	}

	void update(int vertex, int l, int r, int pos, int newVal) {
		if ((pos < l) || (r < pos)) {
			return;
		}

		if (l == r) {
			segmenttree[vertex] = newVal;
			return;
		}

		int m = (l+r) / 2;
		if ((l <= pos) && (pos <= m))
			update(2 * vertex, l, m, pos, newVal);
		else
			update(2 * vertex + 1, m+1, r, pos, newVal);

		segmenttree[vertex] = segmenttree[2*vertex] + segmenttree[2*vertex + 1];
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

int caso = 0;

bool resuelveCaso(int espacio_o_no_por_la_punetera_UVA) {
	int n; cin >> n;
	if(n == 0) return false;
	caso++;
	if(espacio_o_no_por_la_punetera_UVA) cout << '\n';
	
	vector<int> potmeters(n);
	for(int i = 0; i < n; i++) {
		cin >> potmeters[i];
	}

	SegmentTree st(potmeters);
	string command; int op1, op2;

	cout << "Case " << caso << ":\n";
	cin >> command;
	while(command != "END") {
		cin >> op1 >> op2;
		op1--; --op2;
		if(command == "S") {
			st.update(op1, op2+1);
		} else if(command == "M") {
			cout << st.query(op1, op2) << '\n';
		}
		cin >> command;
	}
	
	return true;
}

int main() {
	bool ok = resuelveCaso(0);
	while(ok) {
		ok = resuelveCaso(1);
	}
	return 0;
}
