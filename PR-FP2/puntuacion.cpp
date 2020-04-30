#include <iostream>
#include <algorithm>
#include <iomanip>
#include "puntuacion.h"
using namespace std;

void inicializar_pj(tPuntuacionJugador& pj) {
	// ^Inicializa `pj`
	pj.nombre = ""; 
	pj.puntTotal = 0;
	pj.minasRecorridas = 0;
	for(int i = 0; i < NUM_TOTAL_MINAS; i++) {
		tDatosMina & datos = pj.vMinasRecorridas[i];
		datos.IdMina = i+1;
		datos.numMovimientos = 0;
		datos.numGemas = 0;
		datos.numDinamitas =0;
		datos.puntosMina = 0;
	}
}

void cargar_marcador(istream & entrada, tPuntuaciones & marcador) {
	// ^Carga los datos de `entrada` en `marcador`
	string nombreAux; entrada >> nombreAux;
	/// int i = 0;
	while(nombreAux != "000") {
		int pos; /// pos = i;
		if(!buscar(nombreAux, marcador, pos)){
			// Si no está nombreAux en marcador, inserta
			insertar(marcador, nombreAux, pos);
		}

		tPuntuacionJugador & jugador = marcador.arrayClasificacion[pos];
		entrada >> jugador.puntTotal;
		entrada >> jugador.minasRecorridas;
		for(int i = 0; i < jugador.minasRecorridas; i++) {
			tDatosMina & dato = jugador.vMinasRecorridas[i];
			entrada >> dato.IdMina >> dato.numMovimientos >> dato.numGemas;
			entrada >> dato.numDinamitas >> dato.puntosMina;
		}

		/// i++;
		entrada >> nombreAux; 
	}
}

void guardar_marcador(ostream & salida, tPuntuaciones & marcador) {
	// ^Guarda los datos de `marcador` en el fichero `salida`
	for(int i = 0; i < marcador.numJugadores; i++) {
		tPuntuacionJugador & jugador = marcador.arrayClasificacion[i];
		salida << jugador.nombre << '\n' << jugador.minasRecorridas << '\n';
		for(int j = 0; j < jugador.minasRecorridas; j++) {
			tDatosMina & dato = jugador.vMinasRecorridas[j];
			salida << dato.IdMina << " " << dato.numDinamitas << " ";
			salida << dato.numGemas << " " << dato.numMovimientos << " ";
			salida << dato.puntosMina << "\n";
		}
	}
	cout << "000\n";
}

void mostrar_minas_usuario(const tPuntuaciones & marcador, int pos, int tabSize = -1) {
	// ^Muestra los datos de `marcador.arrayClasificacion[pos]`
	int tab;
	tPuntuacionJugador & jugador = marcador.arrayClasificacion[pos];
	if(tabSize < 0) tab = max((int)jugador.nombre.size() + 2, 8);
	else tab = tabSize;

	cout << left << setw(tab) << jugador.nombre 
		<< right << setw(tab) << "Movimientos"
		<< right << setw(tab) << "Gemas"
		<< right << setw(tab) << "Dinamitas"
		<< right << setw(tab) << "Puntos"
		<< right << setw(tab) << "Puntos en total";
	// TODO: Terminar esta función (De aquí hasta })
	for(int i = 0; i < jugador.minasRecorridas; i++)
	cout << left << setw(tab) << jugador.nombre 
		<< right << setw(tab) << "Movimientos"
		<< right << setw(tab) << "Gemas"
		<< right << setw(tab) << "Dinamitas"
		<< right << setw(tab) << "Puntos"
		<< right << setw(tab) << "Puntos en total";
	
}
void mostrar_puntuaciones_alfabetico(const tPuntuaciones & marcador);
// ^Muestra las puntuaciones de todos los usuarios (orden αβ)
void mostrar_datos_usuario(const tPuntuaciones & marcador);
// ^Muestra todos los datos de todos los usuarios (orden αβ)

void inicializar_marcador(tPuntuaciones & marcador) {
	// ^Inicializa el array dinámico
	marcador.numJugadores = 0; 
	marcador.capacidad = 2; 
	marcador.arrayClasificacion = new tPuntuacionJugador[marcador.capacidad];
}
void aumentar_capacidad(tPuntuaciones & marcador) {
	// ^Duplica el tamaño del array
	marcador.capacidad *= 2;
	tPuntuacionJugador * nuevoMarcador = new tPuntuacionJugador[marcador.capacidad];

	for(int i = 0; i < marcador.numJugadores; i++)
		nuevoMarcador[i] = marcador.arrayClasificacion[i];

	marcador.arrayClasificacion = nuevoMarcador;
}
void destruir(tPuntuaciones & marcador) {
	// ^Libera la memoria dinámica de marcador
	int capacidad = 0, numJugadores = 0;
	delete marcador.arrayClasificacion;
}

bool binarySearch(const string& nombre, const tPuntuaciones & marcador, int&pos, int ini, int fin) {
	// Devuelve la posición donde estaría `nombre` en el array
	bool res = false;
	if(ini <= fin) {
		int mid = ini + (fin-ini)/2;
		string & nombreMid = marcador.arrayClasificacion[mid].nombre;
		if(nombreMid == nombre){
			pos = mid;
			res = true;
		} 
		else if(nombreMid < nombre)
			res = binarySearch(nombre, marcador, pos, mid+1, fin);
		else if(nombreMid > nombre) {
			pos = mid; // Si debe estar a la izquierda, podría estar en mid (Mejor que lo anterior)
			res = binarySearch(nombre, marcador, pos, ini, mid-1);
		}
	}
	return res;
}

bool buscar(const string& nombre, const tPuntuaciones& marcador, int& pos) {
	// ^Busqueda binaria de`nombre` en `marcador`. `pos` es la posición donde iría
	return binarySearch(nombre, marcador, pos, 0, marcador.numJugadores-1);
}

void insertar(tPuntuaciones& marcador, string const& nombre, int pos) {
	// ^Inserta ordenadamente en la posición pos. Si no hay espacio, se amplía
	marcador.numJugadores++;
	if(marcador.numJugadores >= marcador.capacidad) {
		aumentar_capacidad(marcador);
	}

	// -2 pues empezamos por el ahora penúltimo
	for(int i = marcador.numJugadores-2; i >= pos; i--) 
		marcador.arrayClasificacion[i+1] = marcador.arrayClasificacion[i];

	inicializar_pj(marcador.arrayClasificacion[pos]);
	marcador.arrayClasificacion[pos].nombre = nombre;
}
