#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<long long>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using vpi = vector<pi>;

using opc = pair<pair<int, int> , string>;

bool resuelveCaso() {
	int n; cin >> n;
	if(n==0) return false;

	stack<opc> pos;
	for(int i = 0; i<n; i++) {
		opc act;
		cin >> act.second >> act.first.first >> act.first.second;
		while(!pos.empty() && act.first.first >= pos.top().first.second){
			pos.pop();
		}
		pos.push(act);
	}

	string res = "";
	int len = 0;
	while(!pos.empty()) {
		if(pos.top().first.second != -1) {
			res += pos.top().second + " ";
			len++;
		}
		pos.pop();
	}

	if(res == "") cout << "Ninguno\n";
	else {
		cout << len << '\n';
		cout << res << '\n';
	}
	
	return true;
}

int main() {
	/*
	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		//cout << "Case #" << i << ": ";
		resuelveCaso();
	
	}
	// */
	//*
	while(resuelveCaso());
	// */
	return 0;
}


