#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
using namespace std;


bool checkValidString(string s) {
	stack<pair<char, int>> pila;
	deque<int> stars;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '{') pila.push(make_pair(s[i], i));
		else if (s[i] == '}')  {
			if(!pila.empty() && pila.top().first != '}') pila.pop();  
			else pila.push(make_pair('}', i));
		} 
		else if (s[i] == '*') stars.push_back(i);
	}
	if(pila.empty()) {
		return true;
	}
	else {
		bool ok = true;
		while(!pila.empty() && pila.top().first == '{' && ok) {
			if(stars.back() < pila.top().second) ok = false;
			else {
				stars.pop_back();
				pila.pop();
			}
		}
		while(!pila.empty() && ok) {
			if(stars.front() > pila.top().second) ok = false;
			else {
				stars.pop_front();
				pila.pop();
			}
		}

		return ok;
	}
}

int main() {
	string s; cin >> s;
	cout << (checkValidString(s)? "Válido" : "No válido") << '\n';
}
