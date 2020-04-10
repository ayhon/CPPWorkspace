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

vi f(vi const& a) {
	int maxi = 0;
	vi res;
	for (int i = 0; i < a.size(); i++) {
		if(a[i] > maxi){
			res.push_back(a[i]);
			maxi = max(maxi, a[i]);
		}  
	}
	return res;
}

void resuelveCaso() {
	
}

int main() {
	int T; cin >> T;
	for (int i = 0; i < T; i++) resuelveCaso();
	return 0;
}

