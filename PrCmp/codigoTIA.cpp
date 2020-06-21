#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;
const int CODE_CHAR_SIZE = 3;
vector<long long> dp;

long long resolver(string & msg, set<string> const& dict, int idx) {
	if(idx >= msg.length()) return 1;
	if(dp[idx] != -1) return dp[idx];

	long long res = 0;
	/*
	for(int i = 1; i <= CODE_CHAR_SIZE && idx + i <= msg.length() && msg[idx+i-1] != '0'; i++) {
		auto it = dict.find(msg.substr(idx,i));
		if(it != dict.end()) {
			dp[idx+i] = (resolver(msg, dict, idx+i) % MOD);
			res += dp[idx+i];
		}
	}
	*/

	for(int i = 1; i <= CODE_CHAR_SIZE && idx + i <= msg.length(); i++) {
		auto it = dict.find(msg.substr(idx,i));
		if(it != dict.end()) {
			res += (resolver(msg, dict, idx+i) % MOD);
		}
	}
	return dp[idx] = res;
}

long long resolver(string & msg, set<string> const& dict) {
	dp.clear(); dp.resize(msg.length()+1, -1);
	return resolver(msg, dict, 0);
}

bool resuelveCaso() {
	int n; cin >> n;
	if(n==0) return false;
	set<string> dict;

	for(int i = 0; i < n; i++) {
		string aux; cin >> aux;
		dict.insert(aux);
	}

	vector<string> pals;
	string palActual = "";

	cin.ignore(INT_MAX, '\n');
	char aux; cin.get(aux);

	while(aux != '\n') {
		if(aux == '0') {
			pals.push_back(palActual);
			palActual = "";
		}
		else {
			palActual += aux;
		}
		cin.get(aux);
	}
	pals.push_back(palActual);

	long long res = 1;
	for(string & pal : pals) {
		res = (res * resolver(pal, dict)) % MOD;
		if(res == 0) break;
	}
	cout << res << '\n';
	
	return true;
}

int main() {
	while(resuelveCaso());
	return 0;
}
