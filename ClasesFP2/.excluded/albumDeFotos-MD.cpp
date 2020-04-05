#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct tFoto {
    string titulo;
    string tema;
    vector<vector<int> > imagen;
};

struct ordenTitulo {
    bool operator()(tFoto* f1, tFoto* f2) {
        return f1->titulo < f2->titulo;
    }
};
struct ordenTema {
    bool operator()(tFoto* f1, tFoto* f2) {
        return (f1->tema < f2->tema) || (f1->tema == f2->tema && f1-> titulo < f2->titulo);
    }
};

bool resuelveCaso() {
    int numFotos; cin >> numFotos;
    string aux; getline(cin, aux);
    if(numFotos == 0) return false;

    vector<tFoto*> album(numFotos);
    for (size_t i = 0; i < numFotos; i++) {
        album[i] = new tFoto;
        getline(cin, album[i]->titulo);
    }
    for (size_t i = 0; i < numFotos; i++) {
        getline(cin, album[i]->tema);
    }
    sort(album.begin(), album.end(), ordenTitulo());
    for (size_t i = 0; i < numFotos; i++) {
        cout << album[i]->titulo << '\n';
    }
    cout << '\n';
    sort(album.begin(), album.end(), ordenTema());
    for (size_t i = 0; i < numFotos; i++) {
        cout << album[i]->tema << " - " << album[i]->titulo << '\n';
    }
    cout << '\n';

    // Borrar las variables usadas
    for (size_t i = 0; i < numFotos; i++) {
        delete album[i];
    }
    return true;
}

int main() {
    while(resuelveCaso());
    return 0;
}