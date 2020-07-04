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

int sel(vi & A){
	int n = A.size(), res = 0;
	for(int i = 0; i < n-1; i++){
		int maxi = i;
		for(int j = i; j < n; j++) {
			if(A[j] < A[maxi]) maxi = j;
		}
		if(maxi != i){
			swap(A[i], A[maxi]);
			res++;
		}
	}
	return res;
}

int burb(vi & A){
	int n = A.size(), res = 0;
	for(int i = 0; i < n-1; i++) {
		for(int j = n-1; j > i; j--) {
			if(A[j] < A[j-1]){
				res++;
				swap(A[j], A[j-1]);
			}
		}
	}
	return res;
}

bool resuelveCaso() {
	int n; cin >> n;
	if(!cin) return false;

	vi v(n);
	for(int & e: v) cin >> e;
	cout << burb(v) << '\n';
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


