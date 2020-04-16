#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

bool checkAnagram(string m1, string m2) {
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
		for(int j = 0; j < strs.size(); j++) {
			bool found = false;
			for(int i = 0; i < res.size() && !found; i++) {
				map<char, int> mapa1, mapa2; int count;
				for(char c : strs[j]) mapa1[c]++;
				for(char c : res[i][0]) mapa2[c]++;
				if(mapa1 == mapa2) {
					found = true;
					res[i].push_back(strs[j]);
				}
			}
			if(!found) res.push_back({strs[j]});
		}
		return res;
}

string getString() {
	char aux;
	string res = "";
	cin >> aux;
	while(aux != '"') cin >> aux;
	cin >> aux;
	while(aux != '"') {
		res += aux;
		cin >> aux;
	}
	return res;
}

int main() {
	vector<string> strs; char aux;
	strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<vector<string> > res = groupAnagrams(strs);
	for(vector<string> & v : res) {
		for(string s : v) {
			cout << s <<  " ";
		}
		cout << '\n';
	}
	return 0;
} 
// {"eat", "tea", "tan", "ate", "nat", "bat"}
