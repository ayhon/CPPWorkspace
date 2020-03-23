#include <iostream>
#include "sprites.h"

void printTitleScreen() {
    cout << " ███▄ ▄███▓ ▄▄▄        ██████ ▄▄▄█████▓▓█████  ██▀███      ███▄ ▄███▓ ██▓ ███▄    █ ▓█████  ██▀███  \n";
    cout << "▓██▒▀█▀ ██▒▒████▄    ▒██    ▒ ▓  ██▒ ▓▒▓█   ▀ ▓██ ▒ ██▒   ▓██▒▀█▀ ██▒▓██▒ ██ ▀█   █ ▓█   ▀ ▓██ ▒ ██▒\n";
    cout << "▓██    ▓██░▒██  ▀█▄  ░ ▓██▄   ▒ ▓██░ ▒░▒███   ▓██ ░▄█ ▒   ▓██    ▓██░▒██▒▓██  ▀█ ██▒▒███   ▓██ ░▄█ ▒\n";
    cout << "▒██    ▒██ ░██▄▄▄▄██   ▒   ██▒░ ▓██▓ ░ ▒▓█  ▄ ▒██▀▀█▄     ▒██    ▒██ ░██░▓██▒  ▐▌██▒▒▓█  ▄ ▒██▀▀█▄  \n";
    cout << "▒██▒   ░██▒ ▓█   ▓██▒▒██████▒▒  ▒██▒ ░ ░▒████▒░██▓ ▒██▒   ▒██▒   ░██▒░██░▒██░   ▓██░░▒████▒░██▓ ▒██▒\n";
    cout << "░ ▒░   ░  ░ ▒▒   ▓▒█░▒ ▒▓▒ ▒ ░  ▒ ░░   ░░ ▒░ ░░ ▒▓ ░▒▓░   ░ ▒░   ░  ░░▓  ░ ▒░   ▒ ▒ ░░ ▒░ ░░ ▒▓ ░▒▓░\n";
    cout << "░  ░      ░  ▒   ▒▒ ░░ ░▒  ░ ░    ░     ░ ░  ░  ░▒ ░ ▒░   ░  ░      ░ ▒ ░░ ░░   ░ ▒░ ░ ░  ░  ░▒ ░ ▒░\n";
    cout << "░      ░     ░   ▒   ░  ░  ░    ░         ░     ░░   ░    ░      ░    ▒ ░   ░   ░ ░    ░     ░░   ░ \n";
    cout << "░         ░  ░      ░              ░  ░   ░               ░    ░           ░    ░  ░   ░     \n";
                                                                                                   
}

void sprite(tElemento elem, int section) {
    switch(elem) {
        case MINERO:
            if(section == 1) {

            }
            else if (section == 2) {

            }
            else if (section == 3) {
                
            }
    }
}

void colorFondo(int color, string msg, vector<int> extra) {
    if(extra.empty()) extra.push_back(1); // Valores por defecto, pero pudiendo pasar por referencia
    #ifdef _WIN32
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAtribute(handle, 15 | (color << 4));
        cout << msg;
        SetConsoleTextAtribute(handle, 0 | (color << 4));
    #elif __linux__
        cout << "\e[" << extra.at(0);
        for (int i = 1; i < extra.size(); ++i)
            cout << ";" << extra[i];
        cout << ";" << color << "m" + msg + "\e[m";
    #endif
}