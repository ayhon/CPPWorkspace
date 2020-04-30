//Author: Ayhon
#include <iostream>
#include <climits>
#include <string>
#include <vector>
#include <algorithm>
#include "juego.h"
#ifdef _WIN32
#include <conio.h>
#elif __linux__
#include "conio.h"
#endif
#ifdef DOMJUDGE
const bool DEBUG = false;
#else
const bool DEBUG = true;
#endif

using namespace std;

void Log(string const& msg){ 
	if (DEBUG) cout << msg << '\n';
}

void explosion(tJuego& juego, int x, int y) { tPlano& plano = juego.mina.plano;
	for (int i = x-1; i <= x+1; i++) {
		for (int j = y-1; j <= y+1; j++) {
			if(dentroPlano(juego.mina, i, j)){
				if(plano[i][j] == MINERO) juego.estado = EXPLOTADO;
				plano[i][j] = LIBRE;
			} 
		}
	}
	for (size_t j = y-1; j <= y+1; j++) {
		if(dentroPlano(juego.mina, x-2, j)) avalancha(juego, x-2, j);
	}
	
}

void lanzarDinamita(tJuego& juego) {
	juego.dinamitasUsadas++;
	int& x = juego.mina.minero.x,
		y = juego.mina.minero.y;
	tPlano& plano = juego.mina.plano;
	int tx; // target x
	for (tx = x + 1; tx < plano.size() && plano[tx][y] == LIBRE; tx++) {
		tElemento tmp = plano[tx][y];
		plano[tx][y] = DINAMITA;
		dibujar(juego);
		system("sleep .1");
		plano[tx][y] = tmp;
	}
	tx--; // Volvamos a la última posición válida
	explosion(juego, tx, y);
}

void moverMinero(tJuego& juego, int hasta_x, int hasta_y) {
	int& desde_x = juego.mina.minero.x,
		 desde_y = juego.mina.minero.y;
	tPlano& plano = juego.mina.plano;
	plano[hasta_x][hasta_y] = plano[desde_x][desde_y];
	plano[desde_x][desde_y] = LIBRE;
	juego.mina.minero.x = hasta_x;
	juego.mina.minero.y = hasta_y;
}

void queCaiga(tJuego & juego, int x, int y) {
	// !! No se encarga de que (x,y) deba caer
	tPlano& plano = juego.mina.plano;
	if(dentroPlano(juego.mina, x+1, y) && plano[x+1][y] == LIBRE) {
			int nx;
			for(nx = x+1; nx < plano.size() && plano[nx][y] == LIBRE; ++nx) juego.mina.visitados[nx][y] = true;
			swap(plano[x][y], plano[nx-1][y]);
	}
}

void avalancha(tJuego & juego, int x, int y) {
	int tx;
	for(tx = x; tx >= 0 && esElemQueCae(juego.mina.plano[tx][y]); --tx) {
		queCaiga(juego, tx, y);
	}
}

void printStats(tJuego const& juego) {
	cout << "Movimientos: " << juego.numMovimientosMinero << '\n';
	cout << "Gemas: " << juego.gemasRecogidas << '\n';
	cout << "Dinamitas: " << juego.dinamitasUsadas << '\n';
}

istream& operator>>(istream& movimientos, tTecla& tecla) {
	char input;
	movimientos.get(input);
	switch(input){
		case 'A':
			tecla = ARRIBA;
			break;
		case 'Z':
			tecla = ABAJO;
			break;
		case 'M':
			tecla = DCHA;
			break;
		case 'N':
			tecla = IZDA;
			break;
		case 'S':
			tecla = SALIR;
			break;
		case 'D':
			tecla = TNT;
			break;
		case '\n':
			tecla = FIN;
			break;
		default:
			tecla = ERROR_TECLA;
	}
	return movimientos;
}

tTecla leerTeclado() {
	tTecla tecla = ERROR_TECLA;
#ifdef _WIN32
	int dir = _getch();
	if (dir == 0xe0)
		dir = _getch();
	switch (dir) {
	case 27:
		tecla = SALIR;
		break;
	case 72:
		tecla = ARRIBA;
		break;
	case 80:
		tecla = ABAJO;
		break;
	case 77:
		tecla = DCHA;
		break;
	case 75:
		tecla = IZDA;
		break;
	case 32:
	case 64:
	case 44:
		tecla = TNT;
		break;
	}
	return tecla;
#elif __linux__
	bool specialKey = false;
	int dir = _getch();
	Log(to_string(dir) + " ");
	if (dir == 27) {
		dir = _getch();
		Log(to_string(dir) + " ");
		if (dir == 91) {
			specialKey = true;
			dir = _getch();
			Log(to_string(dir) + " ");
		}
		else
			dir = 7;
	}
	Log(to_string(dir) + " ");
	switch (dir) {
	case 65:
		if (specialKey)
			tecla = ARRIBA;
		break;
	case 66:
		if (specialKey)
			tecla = ABAJO;
		break;
	case 67:
		if (specialKey)
			tecla = DCHA;
		break;
	case 68:
		if (specialKey)
			tecla = IZDA;
		else
			tecla = TNT;
		break;
	case 83:
	case 115:
	case 27:
		tecla = SALIR;
		break;
	case 32:
	case 64:
	case 112:
	case 44:
		tecla = TNT;
		break;
	}

	return tecla;
#endif
}

void leerMovimiento(tJuego & juego, tTecla & tecla, istream & movimientos) {
	if(juego.dispositivoDeEntrada == 1)
		tecla = leerTeclado();
	else if(juego.dispositivoDeEntrada == 2)
		movimientos >> tecla;

	if (tecla == SALIR)
		juego.estado = ABANDONO;
}

void dibujar(tJuego const& juego) {
	systemClear();
	printStats(juego);
	switch(juego.resolucion) {
		case 1:
			dibujar1_1(juego.mina);
			break;
		case 2:
			dibujar3_1(juego.mina);
			break;
		default:
			Log("No se acepta la resolución " + to_string(juego.resolucion) + "\n");
	}
	if(juego.estado == EXITO) cout << "Mina recorrida\n";
	else if(juego.estado == EXPLOTADO) cout << "Le alcanzo la dinamita\n";
	else if (juego.estado == ABANDONO) cout << "Pide rescate\n";
	else cout << '\n';
}

void realizarMovimiento(tJuego& juego, tTecla& tecla) {
	juego.numMovimientosMinero++;
	tPlano& plano = juego.mina.plano;
	int x = juego.mina.minero.x,
		y = juego.mina.minero.y;
	int nx = x, ny = y;

	nx += tdirs4[int(tecla)].x;
	ny += tdirs4[int(tecla)].y;
	bool hazMovim = false;
	if(int(tecla) < 4) {
		if(dentroPlano(juego.mina, nx, ny)) {
			switch(plano[nx][ny]) {
				case MURO:
					Log("Te chocaste contra un muro");
					break;
				case PIEDRA:
					if(tecla == DCHA || tecla == IZDA) {
						int x_detras = nx + tdirs4[int(tecla)].x,
							y_detras = ny + tdirs4[int(tecla)].y;
						// Mover la piedra si hay espacio
						if(dentroPlano(juego.mina, x_detras, y_detras) && plano[x_detras][y_detras] == LIBRE) {
							swap(plano[x_detras][y_detras], plano[nx][ny]);
							hazMovim = true;
							// Que caiga la piedra si tiene que caer
							avalancha(juego, x_detras, y_detras);
						}
						else Log("No hay un espacio libre detras de esa piedra");
					}
					break;
				case TIERRA:
				case LIBRE:
					hazMovim = true;
					break;
				case GEMA:
					hazMovim = true;
					++juego.gemasRecogidas;
					break;
				case SALIDA:
					hazMovim = true;
					juego.estado = EXITO;
					break;
				default:
					Log("No se pudo detectar el elemento");
			}
			if (hazMovim) {
				moverMinero(juego, nx, ny); //Actualiza juego.mina.minero pero no x o y
				juego.mina.visitados[nx][ny] = true;
				if (x != 0 && esElemQueCae(plano[x-1][y]))
					avalancha(juego, x-1, y);
			}
			else Log("No te mueves este turno");
		}
	}
	else if (tecla == TNT) {
		lanzarDinamita(juego);
	}
	else Log("Has realizado un movimiento indebido, hacia ("+to_string(nx)+"-"+to_string(ny)+")\n");
	dibujar(juego);
}


void jugar(tJuego & juego, istream & entrada, istream & movimientos) {
	cargar_mina(entrada, juego.mina);
	dibujar(juego);
	tTecla input;
	do{
		leerMovimiento(juego, input, movimientos);
		if(juego.estado != ABANDONO && input != FIN)  {
			realizarMovimiento(juego, input);
		} 
	} while(input != FIN && juego.estado == EXPLORANDO);
	dibujar(juego);
	/*
	if(juego.dispositivoDeEntrada = 2) 
		while(input != FIN) leerMovimiento(juego, input, movimientos); // Agotar movimientos no usados
	*/
}
