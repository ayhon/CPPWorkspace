#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<long long>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using vpi = vector<pi>;

/*
 * Se juega un juego.
 * Cada movimiento consiste en eliminar un 01 o 10 de la cadena
 * Se pierde si no puedes hacer más movimientos
 * Alice empieza primero (%2 == 1)
 * Bob va después (%2 == 0)
 *
 * DP
 * 1001000100011111001101
 * ¿Cual es el movimiento más optimo?
 * No existe tal movimiento.
 * La única diferencia que puede hacer un movimiento u otro es:
 * ...
 * No hay. Ningún movimiento es mejor que otros?
 * 11111 10 000000 no permite nada diferente
 * 11111 10 111111 no cambia tampoco nada
 * 00000 10 111111 no cambia tampoco nada
 * 00000 10 000000 no cambia tampoco nada
 *
 * Consiste tan solo en contar las diferencias?
 * No exactamente, en el caso anterior 11111 10 00000 hay 1 diferencia, pero varios movimientos.
 * Se puede simular (s.length() <= 100)
 * Si de verdad da igual, basta con hacer el primer movimiento?
 * A ver, mejor pensado, realmente el número de movimientos máximo viene dado por
 * el número de 1 o 0 que haya, es decir, la solución final es :
 *  + Una cadena de 1111
 *  + Una cadena de 0000
 *  + Una cadena vacía Ø
 */

void resuelveCaso() {
	bool victoria = false;
	string s; cin >> s;
	
	int unos = 0, ceros = 0;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '1') unos++;
		else if (s[i] == '0') ceros++;
	}
	victoria = min(unos, ceros) % 2;

	cout << (victoria? "DA" : "NET") << '\n';
}

int main() {
	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		//cout << "Case #" << i << ": ";
		resuelveCaso();
	}
	return 0;
}


