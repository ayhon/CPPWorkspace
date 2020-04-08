#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Q;

struct mquery {
	bool operator() (char c1, char c2) {
		char sol;
		cout << "? " << c1 << " " << c2 << '\n';
		fflush(stdout);
		cin >> sol;
		if(sol == '<') return true;
		else if (sol == '>') return false;
		return false;
	}

};

bool query(char c1, char c2) {
	if(Q--){
		char sol;
		cout << "? " << c1 << " " << c2 << '\n';
		fflush(stdout);
		cin >> sol;
		if(sol == '<') return true;
		else if (sol == '>') return false;
	}
	return false;
}

void merge (vector<char> & v, int ini, int mid, int fin) {
	int i = ini, j = mid;
	vector<char> merged;
	while (i < mid && j < fin) {
		if(query(v[i],v[j])) {
			merged.push_back(v[i]);
			i++;
		} 
		else {
			merged.push_back(v[j]);
			j++;
		}
	}
	while(i < mid)  { merged.push_back(v[i]); i++; }
	while(j < fin) { merged.push_back(v[j]); j++; }

	for (int i = 0; i < merged.size(); i++)
		v[ini+i] = merged[i];
}


void mergeSort(vector<char>  & balls, int beg, int end) {
	if (end - 1 <= beg);
	else if(end - beg == 2) {
		if(query(balls[end-1], balls[beg])) 
			swap(balls[end-1], balls[beg]);
	}
	else {
		int mid = (beg + end) / 2;
		mergeSort(balls, beg, mid);
		mergeSort(balls, mid, end);
		merge(balls, beg, mid, end); }
}

int main () {
	int N; cin >> N >> Q;
	vector<char> balls(N);
	for (int i = 0; i < N; i++) {
		balls[i] = char(i + int('A'));
	}
	//mergeSort(balls, 0, balls.size());
	sort(balls.begin(), balls.end(), mquery());
	string msg = "";
	for (char elem : balls) {
		msg += elem;
	}
	cout << "! " << msg << '\n';
	fflush(stdout);
	return 0;
}
