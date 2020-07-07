#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

struct listNode {
	char val = ' ';
	listNode* next = nullptr;
};

//TODO: Revisar la implementación del algoritmo
//    En el cambio de beg a end, se queda un nodo apuntando al vacío en mitad de la lista, esto puede dar errores

bool resuelveCaso() {
	string input;
	getline(cin, input);
	if(!cin) return false;

	listNode* cursor = new listNode;
	listNode* beg = cursor;
	listNode* end = cursor;

	for(int i = 0; i < input.size(); i++) {
		if(input[i] == ']') {
			cursor = end;
		}
		else if(input[i] == '[') {
			end = cursor;
			cursor = beg;
		}
		else {
			listNode* nextSpace = new listNode;
			nextSpace->next = cursor->next;

			cursor->val = input[i];
			cursor->next = nextSpace;

			// Fallo 1: El cursor tiene que avanzar
			cursor = nextSpace;
		}
	}

	cursor = beg;
	while(cursor->next != nullptr) {
		cout << cursor->val;
		listNode* nextNode = cursor->next;
		/*
		delete cursor;
		*/
		cursor = nextNode;
	}
	cout << cursor->val << '\n';
	// delelte cursor;

	return true;
}

int main() {
	/*
	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		//cout << "Case #" << i << ": ";
		resuelveCaso();
	
	}
	// */

	//*
	while(resuelveCaso());
	// */
	return 0;
}


