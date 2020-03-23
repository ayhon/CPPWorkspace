#include <iostream>
#include <string>
#include "juego.h"
using namespace std;

int escogerResolucion() {
    int opcion;
    cout << "1. Jugar partida a escala 1:1\n";
    cout << "2. Jugar partida a escala 3:1\n";
    cout << "0. Salir\n";
    cout << "> "; cin >> opcion;
    while(opcion >= 2 || opcion < 0)  {
        cout << "Entrada no valida. Escoge de nuevo\n"; 
        cout << "> "; cin >> opcion;
    }
    return opcion;
}

int escogerDispEntrada() {
    int opcion;
    cout << "Escoge el dispositivo de entrada\n";
    cout << "1. Usar teclado\n";
    cout << "2. Usar un fichero\n";
    cout << "> "; cin >> opcion;
    while(opcion >= 2 || opcion <= 0)  {
        cout << "Entrada no valida. Escoge de nuevo\n"; 
        cout << "> "; cin >> opcion;
    }
    return opcion;
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
            cout << "Error al sacar el dispositivo de entrada\n";
    }
}

int main() {   
#ifdef _WIN32
    system("chcp 65001");
#elif __linxu__
    system("pause() {");
    system("echo "Presiona enter para continuar");
    system("read");
    system("}");
#endif
    tJuego juego;
    printTitleScreen();
    juego.resolucion = escogerResolucion();
    if(juego.resolucion != 0) {
        juego.dispositivoDeEntrada = escogerDispEntrada();
        vector<int> options = {4,32};
        for (int i = 1; i <= 14; i++) {
            colorear(tColor(i), to_string(i));
            cout << '\n';
        }
        system("pause");
        system("cls");
        printGameOver();
        for (size_t i = 0; i <= 3; i++) {
            sprite(MINERO, i);
            sprite(DINAMITA, i);
            sprite(GEMA, i);
            sprite(SALIDA, i);
            sprite(PIEDRA, i);
            cout << '\n';
        }
    }
    /*
    int numMinas; cin >> numMinas;
    for (int i = 0; i < numMinas; i++)
    {
        resuelveCaso();
    }
    */
   return 0;
}