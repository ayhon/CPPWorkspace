#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

struct tCoords{
	int x = -1, y = -1;
};

const tCoords dirs[8] = {{0,1}, {0,-1}, {1,0}, {-1,0},{1,1}, {1,-1}, {-1,1}, {-1,-1}};

bool dentro(tCoords pos, vector<vector<char>> const& minas) {
	int n = minas.size(), m = minas[0].size();
	return (
			pos.x >= 0 &&
			pos.y >= 0 &&
			pos.x < n &&
			pos.y < m
		   );
}

int contarBombasAdyacentes(tCoords pos,vector<vector<char>> const& minas) {
	int res = 0;
	for(int i = 0; i < 8; i++) {
		int x = pos.x + dirs[i].x,
			y = pos.y + dirs[i].y;
		if(dentro({x,y}, minas) && minas[x][y] == '*') res++;
	}
	return res;
}

void revelar(tCoords pos, vector<vector<char>> const& minas, vector<vector<int>> & tablero) {
	if(minas[pos.x][pos.y] == '*') return;

	tablero[pos.x][pos.y] = contarBombasAdyacentes(pos, minas);
	if(tablero[pos.x][pos.y] == 0) {
		for(int i = 0; i < 8; i++) {
			tCoords newPos;
			newPos.x = pos.x + dirs[i].x;
			newPos.y = pos.y + dirs[i].y;
			if(dentro(newPos, minas) && minas[newPos.x][newPos.y] == '-' && tablero[newPos.x][newPos.y] == -1) {
				revelar(newPos, minas, tablero);
			}
		}
	}

}

bool resuelveCaso() {
	int F, C; cin >> F >> C;
	if(!cin) return false;
	
	vector<vector<char>> minas(F, vector<char> (C));
	vector<vector<int>> tablero(F, vector<int> (C, -1));
	for(vector<char> & vc : minas) {
		for(char & c : vc) {
			cin >> c;
		}
	}

	int K; cin >> K;
	vector<tCoords > movimientos(K);
	for(auto & mov : movimientos) {
		cin >> mov.x >> mov.y;
		mov.x--; --mov.y;
	}

	bool partidaPerdida = false;
	for(int i = 0; i < movimientos.size() && !partidaPerdida; i++) {
		tCoords mov = movimientos[i];
		if(minas[mov.x][mov.y] == '*') partidaPerdida = true;
		else if(tablero[mov.x][mov.y] == -1) revelar(mov, minas, tablero);
	}

	if(partidaPerdida) cout << "GAME OVER\n";
	else {
		for(auto & filas : tablero) {
			for(int & c : filas) {
				switch(c) {
					case -1:
						cout << 'X';
						break;
					case 0:
						cout << '-';
						break;
					default:
						cout << c;
				}
			}
			cout << '\n';
		}
	}

	return true;
}

int main() {
	while(resuelveCaso());
	return 0;
}
