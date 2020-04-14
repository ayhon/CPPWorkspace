#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

using vvi = vector<int, vector<int>>;
using vii = vector<pair<int, int>>;
using vvii = vector<vii>;

vector<bool> status;
vector<vector<int>> grafo;
vector<bool> vis;

void dfs(int v, bool s) {
	vis[v] = true;

	for (int w : grafo[v]) {
		if (!vis[w]) {
			status[w] = s;
			dfs(w, s);
		}
	}
}

int main() {
	int N, M; cin >> N >> M;
	++N;

	grafo.assign(N, {});
	status.assign(N, false);

	string cmd;
	for (int i = 0; i < M; ++i) {
		cin >> cmd;
		
		if (cmd == "POSITIVO") {
			int person;
			cin >> person;

			/// Da positivo esa persona
			status[person] = true;
		}
		else if (cmd == "CONTACTO") {
			int p1, p2;
			cin >> p1 >> p2;

			grafo[p1].push_back(p2);
			grafo[p2].push_back(p1);
		}
		else {
			int person;
			cin >> person;

			if (status[person]) {
				cout << "POSIBLE";
			}
			else {
				vis.assign(N, false);
				for(int i = 0; i < N; ++i){
					if (status[i]) {
						dfs(i, true);
					}
				}

				if (status[person]) {
					cout << "POSIBLE";
				}
				else {
					cout << "NO";
				}
			}
			cout << '\n';
		}
	}
	return 0;
}
