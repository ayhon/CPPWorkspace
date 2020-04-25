//Author: Ayhon
#include <iostream>
#include <climits>
#include <string>
#include <vector>
#include "mina.h"
#include "sprites.h"
using namespace std;

#ifdef DOMJUDGE
const bool PRETTY_PRINT = false;
#else
const bool PRETTY_PRINT = true;
#endif

string to_string(tElemento const& elem) {
	string c;
	switch(elem) {
		case MURO:
			if(!PRETTY_PRINT) c = "X";
			else c = "▉";
			break;
		case PIEDRA:
			if(!PRETTY_PRINT) c = "@";
			else c = "▓";
			break;
		case TIERRA:
			if(!PRETTY_PRINT) c = ".";
			else c = "░";
			break;
		case GEMA:
			if(!PRETTY_PRINT) c = "G";
			else c = "€";
			break;
		case SALIDA:
			if(!PRETTY_PRINT) c = "S";
			else c = "§";
			break;
		case MINERO:
			if(!PRETTY_PRINT) c = "M";
			else c = "¶";
			break;
		case LIBRE:
			if(!PRETTY_PRINT) c = "-";
			else c = " ";
			break;
		default:
			if(!PRETTY_PRINT) c = "E";
			else c = "©";
	}
	return c;
}

tElemento char2elem (char c) {
	tElemento elem;
	switch(c) {
		case 'M':
			elem = MURO;
			break;
		case 'J':
			elem = MINERO;
			break;
		case 'T':
			elem = TIERRA;
			break;
		case 'P':
			elem = PIEDRA;
			break;
		case 'G':
			elem = GEMA;
			break;
		case 'S':
			elem = SALIDA;
			break;
		case '-':
			elem = LIBRE;
			break;
		default:
			elem = ERROR_ELEM;
	}
	return elem;
}

ostream & operator<< (ostream & out, tElemento const& e) {
	string c;
	switch(e) {
		case MURO:
			if(!PRETTY_PRINT) c = "X";
			else c = "▉";
			break;
		case PIEDRA:
			if(!PRETTY_PRINT) c = "@";
			else c = "▓";
			break;
		case TIERRA:
			if(!PRETTY_PRINT) c = ".";
			else c = "░";
			break;
		case GEMA:
			if(!PRETTY_PRINT) c = "G";
			else c = "€";
			break;
		case SALIDA:
			if(!PRETTY_PRINT) c = "S";
			else c = "§";
			break;
		case MINERO:
			if(!PRETTY_PRINT) c = "M";
			else c = "¶";
			break;
		case LIBRE:
			if(!PRETTY_PRINT) c = "-";
			else c = " ";
			break;
		default:
			if(!PRETTY_PRINT) c = "E";
			else c = "©";
	}
	out << c;
	return out;
}

void cargar_mina(istream & fichero, tMina & mina) {
	// Requiere que mina venga con su propio tamaño.
	int numFilas, numColumnas;
	fichero >> numFilas >> numColumnas;
	fichero.ignore(INT_MAX, '\n');
	mina.plano = tPlano(numFilas, vector<tElemento> (numColumnas));
	mina.visitados = tPlanoVisitados(numFilas, vector<bool> (numColumnas, false));
	string input;
	for (size_t i = 0; i < mina.plano.size(); ++i){
		getline(fichero, input);
		for (size_t j = 0; j < mina.plano[i].size(); ++j){
			mina.plano[i][j] = char2elem(input[j]);
			if(input[j] == 'J') {
				mina.minero.x = i;
				mina.minero.y = j;
			}
		}
	}
}

void dibujar1_1(tMina const& mina) {
	for (size_t i = 0; i < mina.plano.size(); ++i){
		for (size_t j = 0; j < mina.plano[i].size(); ++j){
			cout << mina.plano[i][j];
		}
		cout << '\n';
	}
}

void dibujar3_1(tMina const& mina) {
	size_t ratio = 3;
	for (size_t i = 0; i < mina.plano.size(); ++i){
		for (size_t r1 = 0; r1 < ratio; ++r1){
			for (size_t j = 0; j < mina.plano[i].size(); ++j){
				tColor colorFondo = (mina.plano[i][j]==GEMA && mina.visitados[i][j]? NEGRO : theme('f', mina.plano[i][j])),
					   colorTexto = theme('t', mina.plano[i][j]);
				sprite(mina.plano[i][j], r1, colorFondo, colorTexto);
			}
			cout << '\n';
		}
	}
}

bool dentroPlano(tMina const& mina, int x, int y) {
	return x < mina.plano.size() &&
		y < mina.plano[0].size() &&
		x >= 0 &&
		y >= 0;
}

bool esElemQueCae(tElemento &elem) {
	return (elem == PIEDRA || elem == GEMA);
}
