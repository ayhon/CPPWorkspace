#include <bits/stdc++.h>
using namespace std;

void process(vector<int> & permutation, vector<bool> & chosen, int step, vector<int> const& v) {
	if(permutation.size() == v.size()) {
		// We could see also that step is the same as v.size()
		for(int e : permutation) cout << e << " ";
		cout << '\n';
	}
	else{
		for(int i = 0; i < v.size(); i++) {
			if(!chosen[i]) {
				// We choose the element as the `step` element of the permutation
				chosen[i] = true;
				permutation.push_back(v[i]);

				// Choose all other elments and output them
				process(permutation, chosen, step+1, v);

				// Reset to previous state
				chosen[i] = false;
				permutation.pop_back();

			}
		}
	}
}

int main() {
	int n; cin >> n;
	vector<int> v(n);
	for(int & e : v) cin >> e;

	vector<int> permutation;
	vector<bool> chosen(n, false);

	process(permutation, chosen, 0, v);

	return 0;
}


