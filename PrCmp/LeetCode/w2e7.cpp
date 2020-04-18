#include <iostream>
#include <string>
#include <vector>
using namespace std;

string stringShift(string s, vector<vector<int>>& shift) {
	string res = s;
	int displ = 0;
	for(auto v : shift) displ += (v[0]? v[1] : -v[1]);
	int j = 0;
	for(int i = 0; i < s.size(); i++) {
		j = (i + displ) % int(s.size());
		if(j < 0) j += s.size();
		res[j] = s[i];
	}
	return res;
}


int main() {
	vector<vector<int> > shift = {{1,4},{0,7},{0,8},{0,7},{0,6},{1,3},{0,1},{1,7},{0,5},{0,6}};
	string s ="xqgwkiqpif";

	cout << stringShift(s, shift) << '\n';
	return 0;
}
