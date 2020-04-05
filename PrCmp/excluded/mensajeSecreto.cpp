#include <iostream>
using namespace std;


int toInt(string const& msg) {
    int num = 0;
    for (size_t i = 0; i < msg.size(); i++) {
        num += int(msg[i]) - int('0');
        num *= 10;
    }
    return num/10;
    
}
int main() {
    string entrada, msg;
    while(getline(cin, entrada)) {
        msg = "";
        for (size_t i = 0; i < entrada.size(); i++) {
            string charActual = "";
            charActual += entrada[i];
            if(entrada[i] == '1') {
                i++;
                charActual += entrada[i];
            }
            i++;
            charActual += entrada[i];
            msg += char(toInt(charActual));
        }
        cout << msg << '\n';
    }
    return 0;
}