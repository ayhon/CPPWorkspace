#include <bits/stdc++.h>
using namespace std;

void process(vector<int> & subset, int idx, vector<int> const& v) {
	if(idx >= v.size()) {
		for(int i = 0; i < subset.size(); i ++) cout << subset[i] << " ";
		cout << '\n';
	}
	else {
		subset.push_back(v[idx]);
		process(subset, idx+1, v);
		subset.pop_back();
		process(subset, idx+1, v);
	}
}

int main() {
	int n; cin >> n;
	vector<int> v(n);
	for(int & e : v) cin >> e;

	vector<int> subset;
	process(subset, 0, v);

	return 0;
}


