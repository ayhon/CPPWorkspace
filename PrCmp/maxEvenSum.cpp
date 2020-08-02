#include <bits/stdc++.h>
using namespace std;

/*
You are given an array a consisting of n integers. Indices of the array start from zero (i. e. the first element is a0, the second one is a1 , and so on).
You can reverse at most one subarray (continuous subsegment) of this array. Recall that the subarray of a with borders l and r is a[l;r]=al,al+1,…,ar.
Your task is to reverse such a subarray that the sum of elements on even positions of the resulting array is maximized (i. e. the sum of elements a0,a2,…,a2k for integer k=⌊(n−1)/2⌋ should be maximum possible).
You have to answer t independent test cases.
 */

using vll = vector<long long>;

void resuelveCaso() {
	int n; cin >> n; 
	vll a(n);
	for(auto & e : a) cin >> e;
	long long ogSum = 0;
	for(int i = 0; i < a.size(); i+=2) ogSum += a[i];
	long long inc = 0, incMax = 0;
	for(int i = 1; i < a.size(); i += 2) {
		inc += a[i] - a[i-1];
		if(inc < 0) inc = 0;
		incMax = max(incMax, inc);
	}
	inc = 0;
	for(int i = 2; i < a.size(); i += 2) {
		inc += a[i-1] - a[i];
		if(inc < 0) inc = 0;
		incMax = max(incMax, inc);
	}
	cout << ogSum + incMax << endl;
}

int main() {
	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		//cout << "Case #" << i << ": ";
		resuelveCaso();
	}
	return 0;
}


