#include <bits/stdc++.h>
using namespace std;

bool resuelveCaso() {
	int n; cin >> n;
	if(n == 0) return false;

	vector<pair<int, int> > data(n);

	for(auto& e : data) cin >> e.first >> e.second;
	// Sea data[i] = (xi, yi), si xi > xj -> yi > yj
	sort(data.begin(), data.end());

	bool ok = true;
	for(int i = 1; i < n && ok; i++)
		if(data[i-1].first < data[i].first) 
			ok = data[i-1].second < data[i].second;

	if(ok) cout << "SI";
	else cout << "NO";
	cout << '\n';
	return true;
}

int main() {
	while(resuelveCaso());
	return 0;
}
