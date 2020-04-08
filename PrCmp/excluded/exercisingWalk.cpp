#include <iostream>
#include <vector>
using namespace std;

bool between(int x, int mini, int maxi) {
	return mini <= x && x <= maxi;
}

void resuelveCaso() {
	int left, right, up, down;
	cin >> left >> right >> down >> up;
	int horiz = right - left, vert = up - down, x, y;
	cin >> x >> y;
	int finalX = x + horiz, finalY = y + vert;
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	bool yes = true;
	if(between(finalX, x1, x2) && between(finalY, y1, y2)) {
		if(x==x1 && x==x2 && right + left != 0) yes = false;
		else if(y==y1 && y==y2 && up + down != 0) yes = false;
	}
	else yes = false;

	if(yes) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		resuelveCaso();
	}
	return 0;
}
