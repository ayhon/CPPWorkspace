#include <iostream>
#include <string>
#include "juego.h"
using namespace std;

int escogerResolucion() {
    int opcion;
    cout << "1. Jugar partida a escala 1:1\n";
    cout << "2. Jugar partida a escala 3:1\n";
    cout << "0. Salir\n";
    cout << ">"; cin >> opcion;
    while(opcion >= 3 || opcion < 0)  {
        cout << "Entrada no valida. Escoge de nuevo\n"; 
        cout << ">"; cin >> opcion;
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
    tJuego juego;
    printTitleScreen();
    juego.resolucion = escogerResolucion();
    if(juego.resolucion != 0) {
        vector<int> options = {4,32};
        colorFondo(40, "Un mensaje por aquí, please", options); cout << '\n';
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