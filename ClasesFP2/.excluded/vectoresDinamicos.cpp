#include<iostream>
#include<string>
using namespace std;

const int TAM_INI = 2;

struct tUnidad {
    string nombre;
    int cantidad;
};

struct tLista {
    tUnidad* uds;
    int cont = 0;
    int tam = 0;
};

void inicializarLista(tLista & l) {
    if(l.tam == 0)  {
        l.uds = new tUnidad[TAM_INI];
        l.tam = TAM_INI;
    }
    else {
        cout << "Lista ya inicializada\n";
    }
}

void aumentarLista(tLista & l, int cant) {
    tUnidad* nuevo = new tUnidad[l.tam + cant];
    for (size_t i = 0; i < l.cont; i++) {
        nuevo[i] = l.uds[i];
    }
    delete[] l.uds;
    l.uds = nuevo;
    l.tam += cant;
}

void addObjetos(tLista & l, tUnidad obj){
    bool encontrado = false;
    size_t i;
    for (i = 0; i < l.cont && !encontrado; i++) {
        if(l.uds[i].nombre == obj.nombre) {
            l.uds[i].cantidad += obj.cantidad;
            encontrado = true;
        }
    }
    if(!encontrado) {
        if (l.tam == l.cont)
            aumentarLista(l, TAM_INI);
        l.uds[l.cont] = obj;
        l.cont++;
    }
}

void restarObjetos(tLista & l, tUnidad obj){
    bool encontrado = false;
    for (size_t i = 0; i < l.cont && !encontrado; i++) {
        if(l.uds[i].nombre == obj.nombre) {
            l.uds[i].cantidad -= obj.cantidad;
            if(l.uds[i].cantidad < 0) l.uds[i].cantidad = 0;
            encontrado = true;
        }
    }
}

void listarObjetos(tLista const& l) {
    for (size_t i = 0; i < l.cont; i++) {
        cout << l.uds[i].nombre << " " << l.uds[i].cantidad << '\n';
    }
    cout << "---\n";
}

void resuelveCaso() {
    char op; cin >> op;
    tLista almacen;
    inicializarLista(almacen);
    tUnidad aux;
    while(op != 'F'){
        switch (op) {
        case 'A':
            cin >> aux.nombre >> aux.cantidad;
            addObjetos(almacen, aux);
            break;
        case 'R':
            cin >> aux.nombre >> aux.cantidad;
            restarObjetos(almacen, aux);
            break;
        case 'L':
            listarObjetos(almacen);
            break;
        default:
            cout << "No tiene sentido esta operación\n";
        }
        cin >> op;
    }
    delete[] almacen.uds;
}

int main() {
    resuelveCaso();
    return 0;
}