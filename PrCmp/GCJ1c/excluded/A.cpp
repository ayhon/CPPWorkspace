#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

using vi = vector<int>;
using pi = pair<int, int>;
using vvi = vector<vi>;
using vl = vector<long long>;
using vvl = vector<vl>;

pi trans(char c) {
	pi pos = make_pair(0,0);
	switch(c) {
		case 'N':
			pos.second = 1;
			break;
		case 'S':
			pos.second = -1;
			break;
		case 'E':
			pos.first = 1;
			break;
		case 'W':
			pos.first = -1;
			break;
	}
	return pos;
}

void resuelveCaso() {
	int x, y; cin >> x >> y;
	string m; cin >> m;
	int time = 0;
	while(abs(x) + abs(y) > time && time < m.length()) {
		pi disp = trans(m[time]);
		x += disp.first;
		y += disp.second;
		time++;
	}
	if(abs(x) + abs(y) <= time) cout << time;
	else cout << "IMPOSSIBLE";
	cout << '\n';
}

int main() {
	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": ";
		resuelveCaso();
	}
	return 0;
}


