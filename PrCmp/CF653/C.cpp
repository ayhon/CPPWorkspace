#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <set>
#include <algorithm>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<long long>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using vpi = vector<pi>;

int numCorrections(string const& s) {
	int check = 0, fallos = 0;
	for(int i = 0; i < s.length(); i++) {
		if (s[i] == '(') check++;
		else if (s[i] == ')') check--;
		if(check<0) {
			check = 0;
			fallos++;
		}
	}
	return fallos;
}

bool isCorrect(string const& s) {
	int check = 0;
	for(int i = 0; i < s.length(); i++) {
		if (s[i] == '(') check++;
		else if (s[i] == ')') check--;
		if(check<0) break;
	}
	return check<0;
}

void resuelveCaso() {
	int n; cin >> n;
	cin.ignore(INT_MAX, '\n');
	string s; 
	getline(cin, s);
	cout << numCorrections(s) << '\n';
}

int main() {
	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		//cout << "Case #" << i << ": ";
		resuelveCaso();
	}
	return 0;
}


