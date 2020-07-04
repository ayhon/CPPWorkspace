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

void resuelveCaso() {
	int n; cin >> n;
	vector<int> a(n);
	for(int & e : a) cin >> e;

	int ini = a.size(), fin = 0, valMax = 0, valAct;
	for(int i = 0; i < a.size(); i+=2) {
		if(a[i] > a[i-1]){
			if(valAct == 0) {
				valAct = a[i] - a[i+1];
			}
			else {

			}
		} else {
			ini = i+2;
			fin = i+2;
		}
	}

}

int main() {
	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		//cout << "Case #" << i << ": ";
		resuelveCaso();
	}
	return 0;
}


