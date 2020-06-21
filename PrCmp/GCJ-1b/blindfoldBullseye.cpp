#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

enum tVeredicto {CENTER, HIT, MISS};
struct tCoords { int x, y; };
const int Top = 1000000000;
vector<tCoords> ptosIni = { {0,0}, {Top, Top}, {Top, -Top}, {-Top, Top}, {-Top, -Top} };

 tVeredicto askGary(tCoords dardo) {
	cout << dardo.x << " " << dardo.y << '\n';
	string answer; cin >> answer;
	if(answer == "CENTER") return CENTER;
	else if(answer == "HIT") return HIT;
	else return MISS;
}

int dist(tCoords pos1, tCoords pos2) {
	long long op1 = abs(pos1.x - pos2.x);
	long long op2 = abs(pos1.y - pos2.y);
	return abs(int(sqrt(op1 * op1 + op2 * op2)));
}

pair<tCoords, bool> binSearch(tCoords iniArg, tCoords finArg) {
	// ini must be hit
	// fin must be miss
	tCoords mid, ini = iniArg, fin = finArg;
	while(dist(ini, fin) > 1) {
		mid.x = (long long)(ini.x + fin.x) / 2;
		mid.y = (long long)(ini.y + fin.y) / 2;
		tVeredicto midVer = askGary(mid);
		switch(midVer) {
			case CENTER:
				return make_pair(mid, true);
				break;
			case HIT:
				ini = mid;
				break;
			case MISS:
				fin = mid;
				break;

		}
	}
	return make_pair(ini, false);
} 

tCoords spiral(tCoords centro) {
	tCoords actual = centro;
	for(int i = 0; i < Top/2; i+=2) {
		for(int j = 1; j < i; j++) {
			actual.x += j;
			if(askGary(actual)) return actual;
		}
		for(int j = 1; j < i; j++) {
			actual.y += j;
			if(askGary(actual)) return actual;
		}
		for(int j = 1; j < i+1; j++) {
			actual.x -= j;
			if(askGary(actual)) return actual;
		}
		for(int j = 1; j < i+1; j++) {
			actual.y -= j;
			if(askGary(actual)) return actual;
		}
	}
	return actual;
}

tCoords locateRadius(tCoords pos) {
	pair<tCoords, tCoords> ptoCircum;
	tCoords outLeft, outRight;
	outLeft.x = -Top; outRight.x = Top;
	outLeft.y = pos.y; outRight.y = pos.y;
	if(askGary(outLeft) == HIT) ptoCircum.first = outLeft;
	else {
		pair<tCoords, bool> res = binSearch(pos, outLeft);
		if(res.second) return res.first;
		else {
			ptoCircum.first = res.first;
		}
	}

	if(askGary(outRight) == HIT) ptoCircum.second = outRight;
	else {
		pair<tCoords, bool> res = binSearch(pos, outRight);
		if(res.second) return res.first;
		else {
			ptoCircum.second = res.first;
		}
	}
	tCoords auxDiam;
	auxDiam.x = (long long)(ptoCircum.first.x + ptoCircum.second.x)/2;
	auxDiam.y = (long long)(ptoCircum.first.y + ptoCircum.second.y)/2;
	tCoords outUp, outDown;
	outUp.x = auxDiam.x; outDown.x = auxDiam.x;
	outUp.y = Top; outDown.y = -Top;
	pair<tCoords, tCoords> ptosDiam;
	if(askGary(outUp) == HIT) ptosDiam.first = outUp;
	else {
		pair<tCoords, bool> res = binSearch(pos, outUp);
		if(res.second) return res.first;
		else {
			ptosDiam.first = res.first;
		}
	}

	if(askGary(outDown) == HIT) ptosDiam.second = outDown;
	else {
		pair<tCoords, bool> res = binSearch(pos, outDown);
		if(res.second) return res.first;
		else {
			ptosDiam.second = res.first;
		}
	}

	tCoords centro;
	centro.x = (long long)(ptosDiam.first.x + ptosDiam.second.x)/2;
	centro.y = (long long)(ptosDiam.first.y + ptosDiam.second.y)/2;
	if(askGary(centro) == CENTER) return centro;
	else return spiral(centro);
}

void resuelveCaso() {
	int radio_min, radio_max; cin >> radio_min >> radio_max;
	bool exitSwitch = false;
	tCoords res;
	for(tCoords pos : ptosIni) {
		switch(askGary(pos)) {
			case HIT:
				res = locateRadius(pos);
				exitSwitch = true;
				break;
			case CENTER:
				res = pos;
				exitSwitch = true;
				break;
			case MISS:
			default:
				break;
		}
		if(exitSwitch) break;
	}
	cout << res.x << " " << res.y << '\n';
}

int main() {
	int T; cin >> T;
	for(int i = 1; i <= T; i++) 
		resuelveCaso();
	return 0;
}
