#include <iostream>
#include <vector>
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

int bf (string const& s) {
	int res = 0, init = 0;
	bool ok = false;

	while(!ok) {
		int cur = init;
		ok = true;
		for(int i = 0; i < s.size(); i++) {
			res = res + 1;
			if(s[i] == '+') cur++;
			else cur--;

			if(cur < 0){
				ok = false;
				break;
			} 
		}
		init++;
	}
	return res;
}


void resuelveCaso() {
	string s; cin >> s;

	int saveguard =0;
	vector<int> repes;
	for(int i = 0; i < s.size(); i++) {
		if (s[i] == '+') saveguard++;
		else {
			if(saveguard) saveguard--;
			else repes.push_back(i);
		}
	}

	long long int res = 0;
	for(int idx : repes) res += idx + 1;
	res += s.size();

	cout << res << '\n';
}

int main() {
	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		//cout << "Case #" << i << ": ";
		resuelveCaso();
	}
	return 0;
}


