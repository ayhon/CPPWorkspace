#include <iostream>
#include <vector>

using namespace std;

int maxSubarray(vector<int> & nums) {
	int maxi = 0, suma = 0;
	for(int i = 0; i < nums.size(); i++) {
		suma = 0;
		for(int j = i; j < nums.size(); j++) {
			suma += nums[j];
			maxi = max(maxi, suma);
		}
	}
	return maxi;
}

int main() {
	vector<int> nums; int tmp; char aux;
	cin >> aux >> tmp >> aux;
	nums.push_back(tmp);
	while(aux != ']') {
		cin >> tmp >> aux;
		nums.push_back(tmp);
	}
	cout << maxSubarray(nums) << '\n';
}
