#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<long long>;
using vvl = vector<vl>;

vi pot2(32);

void genPot() {
	pot2[0] = 1;
	for(int i = 1; i < 32; i++) {
		pot2[i] = 2*pot2[i-1];
	}
}

int binSearch(int target) {
	int ini = 0, fin = pot2.size();
	int mid = (fin + ini)/2;
	while(ini <= fin) {
		if(pot2[mid] < target) ini = mid+1;
		else if(pot2[mid] == target) return mid;
		else fin = mid - 1;
		mid = (ini + fin)/2;
	}
	if(fin > ini) return ini -1;
	return ini -1;
}

void printPath(vi const& filas) {
	bool rightSide = false;
	int ini = 0;
	for (int r : filas) {
		for (int i = ini; i <= r; i++) {
			cout << i+1 << " " << (rightSide? r+1 : 1) << '\n';
		}
		for (int i = 1; i <= r; i++) {
			cout << r+1 << " " << (rightSide? r+1-i :  1+i ) << '\n';
		}
		rightSide = !rightSide;
		ini = r+1;
	}
}

void resuelveCaso() {
	int N; cin >> N;
	vi filas;

	int r = binSearch(N);
	int aux = N - pot2[r] - r, newaux;
	bool excess = false;
	while (aux < 0) {
		r--;
		aux = N - pot2[r] - r;
	}
	filas.push_back(r);
	while(aux > 0) {
		int r = binSearch(aux) + 1;
		newaux = aux - pot2[r] + 1;
		while (newaux < 0) {
			r--;
			newaux = aux - pot2[r] + 1;
		}
		aux = newaux;
		if(filas.back() != r) filas.push_back(r);
		else {
			excess = true;
			newaux++;
		}
	}
	sort(filas.begin(), filas.end());
	if(N >= 502) printPath(filas);
	else if(N == 501) {
		printPath(filas);
		/*cout << "1 1\n2 2\n 2 1\n";
		for(int i = 2; i < 500; i++) {
			cout << i+1 << " " << 1 << '\n';
		} */
	}
	else {
		printPath(filas);
		/*for(int i = 0; i < N; i++) {
			cout << i+1 << " " << 1 << '\n';
		}*/
	}
	if(excess) {
		for(int i = 1; i <= newaux; i++) {
			cout << filas.back()+1+i << " " << (filas.size() % 2 == 0? 1 : filas.back() + 1) << '\n';
		}
	}
	cout << " -- " << '\n';
	for(int r : filas) {
		cout << r << " ";
	}
	cout << '\n';
}

int main() {
	int T; cin >> T;
	genPot();
	for (int i = 1; i <= T; i++) {
		//cout << "Case #" << i << ": ";
		resuelveCaso();
	}
	return 0;
}

