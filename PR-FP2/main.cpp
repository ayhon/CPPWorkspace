#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include "juego.h"
#include "puntuacion.h"
using namespace std;

const int ULTIMO_NIVEL = 5;
const string ARCHIVO_MARCADOR = "puntuaciones.txt";

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
	/*
//Intenté que no hubieran demasiados #ifdef _WIN32 en la práctica, pero falló
#elif __linux__
    system("pause() { echo \"Presiona Enter para continuar\" ; read; }");
    system("alias cls=clear");
	*/
#endif
    tJuego juego;
    printTitleScreen();
    escogerResolucion(juego);
    if(juego.resolucion != 0) {
        escogerDispEntrada(juego);
		cin.ignore(INT_MAX, '\n');
        if (juego.dispositivoDeEntrada != 0) {
			// Se ha elegido la resolución del juego, y el dispositivo de entrada.
            int nivel = 0;
            bool salir = false;
			tPuntuaciones marcador; inicializar_marcador(marcador);
			ifstream archivoMarcador; archivoMarcador.open(ARCHIVO_MARCADOR);
			if(archivoMarcador.is_open()) {
				cargar_marcador(archivoMarcador, marcador);
			}
			else {
				colorear(ROJO, "[ERROR]: ");
				Log("No se encontró el archivo "+ARCHIVO_MARCADOR+" para cargar el marcador");
			}
			mostrar_datos_usuario(marcador);
			mostrar_puntuaciones_alfabetico(marcador);

			// Se carga el marcador con los datos del fichero

			/*  Se introduce el nombre del jugador.
			 *  Si existe el nombre, se le muestra su puntuación
			 *  Si no existe el nombre, se le pide que ponga uno (Y se muestra)
			 *  Se le pide elegir que nivel quiere explorar
			 *
			 *   Ahora ya no es importante el nivel en el que estamos para ver cuando se termina el juego,
			 *   sino si el usuario ha decidido salir o no.
			 *   Al salir del juego, se debe además guardar el marcador
			 */

            while (!salir) {
                ifstream archivoNivel, archivoEntrada;
                int opcion;

                juego.estado = EXPLORANDO; // Si no hemos salido, es que estamos explorando aún
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

				if (nivel == ULTIMO_NIVEL || (int(juego.estado) >= 2 || salir)) { // TODO: Ese salir no debería de hacer nada
					// Se imprime "Game Over" siempre que se salga del juego
					if (juego.estado == EXITO)
						printVictory();
					else
						printGameOver();
					salir = true;
				}
				else {
					cout << "1. Jugar al siguiente nivel\n";
					cout << "0. Salir\n";
					cout << "> "; cin >> opcion;
					if (opcion == 0) salir = true;
					cin.ignore(INT_MAX, '\n');
				}
            }
        }
	}

   return 0;
}
