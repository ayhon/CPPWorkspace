#include <bits/stdc++.h>
using namespace std;

//TODO: Ineficiente. Es un algoritmo cubico. Hazlo cuadrático

void queens(int n, vector<int> & placed, vector<bool> taken) {
	if(placed.size() == n) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cout << (j == placed[i]? '@' : '-');
			}
			cout << '\n';
		}
		cout << '\n';
	}
	else {
		for(int i = 0; i < n; i++) {
			if(taken[i]) continue;
			int useThisPlace = true;
			for(int j = 0; j < placed.size() && useThisPlace; j++) {
				useThisPlace = (placed[j] + j != i + placed.size()) && (placed[j] - j != i - placed.size());
			}
			if(!useThisPlace) continue;

			placed.push_back(i);
			taken[i] = true;

			queens(n, placed, taken);

			placed.pop_back();
			taken[i] = false;
		}
	}
}

void solveNQueens(int n, vector<int> & placed, vector<bool> taken) {
	if(placed.size() == n) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cout << (j == placed[i]? '@' : '-');
			}
			cout << '\n';
		}
		cout << '\n';
	}
	else {
		for(int i = 0; i < n; i++) {
			// Make sure they are not on the same vertical
			if(taken[i]) continue;
			// Make sure they are not on the same diagonal
			int useThisPlace = true;
			for(int j = 0; j < placed.size() && useThisPlace; j++) {
				// placed[j] gives the y coordinate of the queen at (j, placed[j])
				// We are testing for queen at (place.size(), i)
				useThisPlace = (placed[j] + j != i + placed.size()) && (placed[j] - j != i - placed.size());
			}
			if(!useThisPlace) continue;

			// Take this position
			placed.push_back(i);
			taken[i] = true;

			// Try with this position
			solveNQueens(n, placed, taken);

			// Reset to the original state
			placed.pop_back();
			taken[i] = false;
		}
	}
}


int main() {
	int n; cin >> n;
	vector<int> placed;
	vector<bool> taken(n, false);
	solveNQueens(n, placed, taken);

	return 0;
}


