#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include "juego.h"
using namespace std;

const int ULTIMO_NIVEL = 4;
void escogerResolucion(tJuego & juego, ostream& flujoSalida = cout, istream& flujoEntrada = cin) {
    flujoSalida << "Escoge la resolución del juego\n";
    flujoSalida << "1. Jugar partida a escala 1:1\n";
    flujoSalida << "2. Jugar partida a escala 3:1\n";
    flujoSalida << "0. Salir\n";
    flujoSalida << "> "; flujoEntrada >> juego.resolucion;
    while(juego.resolucion > 2 || juego.resolucion < 0)  {
        flujoSalida << "Entrada no valida. Escoge de nuevo\n"; 
        flujoSalida << "> "; flujoEntrada >> juego.resolucion;
    }
}

void escogerDispEntrada(tJuego & juego, ostream& flujoSalida = cout, istream& flujoEntrada = cin) {
    flujoSalida << "Escoge el dispositivo de entrada\n";
    flujoSalida << "1. Usar teclado\n";
    flujoSalida << "2. Usar un fichero\n";
    flujoSalida << "0. Salir\n";
    flujoSalida << "> "; flujoEntrada >> juego.dispositivoDeEntrada;
    while(juego.dispositivoDeEntrada > 2 || juego.dispositivoDeEntrada < 0)  {
        flujoSalida << "Entrada no valida. Escoge de nuevo\n"; 
        flujoSalida << "> "; flujoEntrada >> juego.dispositivoDeEntrada;
    }
    if (juego.dispositivoDeEntrada == 2) {
        string nombreArchivo;
        flujoSalida << "Elige un archivo del que leer los movimientos\n";
        flujoSalida << "> "; flujoEntrada >> nombreArchivo;
        if (nombreArchivo.substr(nombreArchivo.size() - 4) != ".txt")
            nombreArchivo += ".txt";
        juego.archivoDeEntrada = nombreArchivo;
    }
}

void resuelveCaso() {   
    tJuego juego;
    cin >> juego.resolucion >> juego.dispositivoDeEntrada;
    switch(juego.dispositivoDeEntrada) {   
        case 1:
            jugar(juego, cin, cin);
            break;
        case 2:
            jugar(juego, cin, cin);
            break;
        default:
            jugar(juego, cin, cin);
            Log("Error al sacar el dispositivo de entrada\n");
    }
}

int main() {   
#ifdef _WIN32
    system("chcp 65001");
#elif __linux__
    system("pause() { echo \"Presiona Enter para continuar\" ; read; }");
    system("alias cls=clear");
#endif
    tJuego juego;
    printTitleScreen();
    escogerResolucion(juego);
    if(juego.resolucion != 0) {
        escogerDispEntrada(juego);
<<<<<<< HEAD
        cin.ignore(INT_MAX, '\n');
=======
>>>>>>> dbcbe1e0ddd34d2b38d1aba20b547828613cc74f
        if (juego.dispositivoDeEntrada != 0) {
            int nivel = 0;
            bool salir = false;
            while (!salir) {
                ifstream archivoNivel;
			    ifstream archivoEntrada;
                int opcion;
                juego.estado = EXPLORANDO;
                nivel++;
				archivoNivel.open(to_string(nivel) + ".txt");
				if (archivoNivel.is_open()) {
					if (juego.dispositivoDeEntrada == 1) {
						jugar(juego, archivoNivel, cin);
					}
					else {
						archivoEntrada.open(juego.archivoDeEntrada);
						jugar(juego, archivoNivel, archivoEntrada);
					}
				}
				else {
					Log("No se encontró el archivo del nivel " + to_string(nivel) + "\n");
				}
				if (nivel == ULTIMO_NIVEL || (int(juego.estado) >= 2 || salir)) {
					// Se imprime "Game Over" siempre que se salga del juego
					if (juego.estado == EXITO)
						printVictory();
					else
						printGameOver();
					salir = true;
				}
				else {
<<<<<<< HEAD
=======
					cin.ignore(INT_MAX, '\n');
>>>>>>> dbcbe1e0ddd34d2b38d1aba20b547828613cc74f
					cout << "1. Jugar al siguiente nivel\n";
					cout << "0. Salir\n";
					cout << "> "; cin >> opcion;
					if (opcion == 0) salir = true;
<<<<<<< HEAD
                    cin.ignore(INT_MAX, '\n');
=======
>>>>>>> dbcbe1e0ddd34d2b38d1aba20b547828613cc74f
				}
            }
        }
	}

   return 0;
}