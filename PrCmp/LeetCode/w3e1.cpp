#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
	vector<int> prod(nums.size());
	int pi = 1; 
	pair<int, int> numZeroes = make_pair(0, 0);
	for(int i = 0; i < nums.size(); i++) {
		if(nums[i] == 0){
			numZeroes.first++;  
			numZeroes.second = i;  
		} 
		else pi *= nums[i];
	}
	if(numZeroes.first >= 2) {
		for(int & p : prod) p = 0;
	}
	else if(numZeroes.first == 1) {
		for(int i = 0; i < numZeroes.second; i++) 
			prod[i] = 0;
		prod[numZeroes.second] = pi;
		for(int i = numZeroes.second+1; i < nums.size(); i++)
			prod[i] = 0;
	}
	else {
		for(int i = 0;  i < nums.size(); i++) {
			prod[i] = pi;
			if(nums[i]) prod[i] /= nums[i];
		}
	}
	return prod;
}

int main() {
	vector<int> nums = {1,0};
	vector<int> res = productExceptSelf(nums);
	for(int num : res) cout << num << " ";
	cout << '\n';
	return 0;
}
