#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> items(N);
	int sum = 0;
	for (int & item : items) {
		cin >> item;
		sum += item;
	}
	int minVotes = sum / (4*M);
	sort(items.begin(), items.end(), greater<int>());
	if (items[M-1] >= minVotes)  cout << "Yes\n";
	else cout << "No\n";
	return 0;
}
