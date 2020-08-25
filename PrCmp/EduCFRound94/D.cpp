#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;
using vvi = vector<vi>;
using vvpi = vector<vpi>;
using pl = pair<long long, long long>;
using vl = vector<long long>;
using vpl = vector<pl>;
using vvl = vector<vl>;
using vvpl = vector<vpl>;

void resuelveCaso() {
	int n; cin >> n;

	vector<int> a(n);
	vector<vector<int>> ap(n + 1);

	for(int i = 0; i < a.size(); i++){
		cin >> a[i];

		ap[ a[i] ].push_back(i);
	} 

	long long sol = 0;
	for(int idx1 = 0; idx1 < ap.size(); idx1++) {
		int elems = ap[idx1].size();
		if(elems < 2) continue;

		for(int i = 0; i < elems-1; i++){
			for(int k = i+1; k < elems; k++) {

				for(int idx2 = 0; idx2 < ap.size(); idx2++) {
					int elems2 = ap[idx2].size();
					if (elems2 < 2) continue;

					for(int j = 0; j < elems2-1; j++) {
						if( ap[idx1][i] < ap[idx2][j] && ap[idx2][j] < ap[idx1][k] ) {
							for(int l = j+1; l < elems2; l++) {
								if( ap[idx1][k] < ap[idx2][l] ) {
									sol++;
								}
							}
						}
						if( ap[idx1][k] <= ap[idx2][j] ) break;
					}

				}

			}
		}

	}
	
	cout << sol << '\n';
}

int main() {
	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		//cout << "Case #" << i << ": ";
		resuelveCaso();
	}
	return 0;
}


