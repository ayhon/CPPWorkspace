#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct tProducto{
    string nombre;
    int precio;
};

struct ordenPrecioMayor {    
    bool operator() (tProducto* p1, tProducto* p2) {
        return p1->precio > p2->precio;
    }
};

int redondeoRaro(int precio) {
    return (precio/10) * 10 - 1;
}

bool resuelveCaso() {
    size_t n, k; cin >> n >> k;
    if(!cin) return false;

    vector<tProducto> almacen(n);
    for (size_t i = 0; i < n; i++) {
        cin >> almacen[i].nombre;
        cin >> almacen[i].precio;
    }

    vector<tProducto*> almacenOrdenados(n);
    for (size_t i = 0; i < n; i++) {
        almacenOrdenados[i] = &almacen[i];
    }
    
    sort(almacenOrdenados.begin(), almacenOrdenados.end(), ordenPrecioMayor());
    
    if(k != 0) {
        size_t i = 0;
        int precioPrevio;
        for (size_t j = 0; j < k && i < n; j++) {
            precioPrevio = almacenOrdenados[i]->precio;
            almacenOrdenados[i]->precio = redondeoRaro(almacenOrdenados[i]->precio);
            i++;
            while ( i < n && precioPrevio == almacenOrdenados[i]->precio) {
                precioPrevio = almacenOrdenados[i]->precio;
                almacenOrdenados[i]->precio = redondeoRaro(almacenOrdenados[i]->precio);
                i++;
            }
        }
    }
    
    for (size_t i = 0; i < n; i++)
    {
        cout << almacen[i].nombre << " " << almacen[i].precio << '\n';
    }
    

    return true;
}

int main() {
    while(resuelveCaso());
    return 0;
}