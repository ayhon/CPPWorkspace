#include <iostream>
#include <vector> 
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<long long>;
using vvl = vector<vl>;

vi poss (10, 1023);
map<char, int> tr;
vector<char> invTr;
int trCount = 0;
int target = 1;

string formSol(vi const& poss) {
	string res = "";
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			if(poss[j] == 1<<i) {
				res += invTr[j];
				break;
			}
		}
	}

	return res;
}

void found(int target, char c) {
	poss[tr[c]] = 1<<target;
	for(int i = 0; i < 10; i++) {
		if(i != tr[c]) 
			poss[i] &= ~(1<<target);
	}
	target++;
}

void analizar(string & num, string & output) {
	for(char c : output) {
		auto it = tr.find(c);
		if(tr.size() == 0 || it == tr.end()) {
			tr[c] = trCount;
			invTr.push_back(c);
			trCount++;
		}
	}
	while( __builtin_popcount( poss[tr[output[0]]] ) == 1) {
			num = num.substr(1);
			output = output.substr(1);
	}

	if(num.size() != output.size()) return;

	if(num[0] == target) found(target, output[0]);
	else {
			int top = (int) num[0] - (int)'0' + 1;
			poss[tr[output[0]]] &= (1<<top) - 1;
	}
}

void resuelveCaso() {
	int U; cin >> U;
	string query, output; cin >> query >> output;
	analizar(query, output);
	for(int i = 0; i < 10000 && target < 10; i++) {
		cin >> query >> output;
		analizar(query, output);
	}

	if(target == 10) cout << formSol(poss) << '\n';
}

int main() {
	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": ";
		resuelveCaso();
	}
	return 0;
}


