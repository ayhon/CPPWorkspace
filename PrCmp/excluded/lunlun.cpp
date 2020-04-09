#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm> 
using namespace std;
using vi = vector<long>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;

const int limit = 100050;
vvvi strLunlun(10, vvi (2));
int numLunlun = 0;
vi lunlun;

void appendTo(int num, int len) {
	strLunlun[num].push_back(vi (0));
	for (int j = num-1; j <= num+1; j++) {
		if(j >= 0 && j <= 9){
			for (int i = 0; i < strLunlun[j][len-1].size(); i++) {
				strLunlun[num][len].push_back(num*pow(10,len-1) + strLunlun[j][len-1][i]);
				if(j != 0) numLunlun++;
			}
		}
	}
}

void genRound(int len) {
	for (int i = 0; i <= 9; i++) {
		appendTo(i, len);
	}
}

void genLunlun() {
	int i = 2;
	// Initialize structured lunluns
	for (int i = 0; i <= 9; i++) strLunlun[i][1].push_back(i); 
	numLunlun = 10;
	while(numLunlun < limit) {
		genRound(i);
		i++;
	}
	for (int i = 1; i < strLunlun.size(); i++) {
		for (int j = 0; j < strLunlun[i].size(); j++) {
			for (int k = 0; k < strLunlun[i][j].size(); k++) {
				lunlun.push_back(strLunlun[i][j][k]);
			}
		}
	}
	sort(lunlun.begin(), lunlun.end());
}

int main() {
	int K; cin >> K;
	genLunlun();
	cout << lunlun[K-1] << '\n';
	return 0;
}
