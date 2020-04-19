#ifndef _MINA_H
#define _MINA_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum tElemento {TIERRA, PIEDRA, MURO, GEMA, SALIDA, LIBRE, MINERO, DINAMITA, ERROR_ELEM};
using tPlano = vector<vector<tElemento>>;

struct tCoords { int x = -1, y = -1; }; // Para detectar errores
struct tMina {
	tCoords minero;
	tPlano plano;
};

tElemento char2elem (char c);
ostream & operator<<(ostream & out, tElemento const& e);
void cargar_mina(istream & fichero, tMina & mina);
void dibujar1_1(tMina const& mina);
void dibujar3_1(tMina const& mina);
bool dentroPlano(tMina const& mina, int x, int y);
bool esElemQueCae(tElemento &elem);
string to_string(tElemento const& elem);

#endif