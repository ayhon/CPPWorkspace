#include <iostream>
#include <string>
#include "sprites.h"
using namespace std;
const vector<int> ctr = { 30,34,32,36,31,35,33,37,90 };

void printTitleScreen() {
    colorear(NEGRO, "                                                                                                 \n", AMARILLO);
    colorear(NEGRO, " ███╗   ███╗ █████╗ ███████╗████████╗███████╗██████╗     ███╗   ███╗██╗███╗   ██╗███████╗██████╗ \n", AMARILLO);
	colorear(NEGRO, " ████╗ ████║██╔══██╗██╔════╝╚══██╔══╝██╔════╝██╔══██╗    ████╗ ████║██║████╗  ██║██╔════╝██╔══██╗\n", AMARILLO);
	colorear(NEGRO, " ██╔████╔██║███████║███████╗   ██║   █████╗  ██████╔╝    ██╔████╔██║██║██╔██╗ ██║█████╗  ██████╔╝\n", AMARILLO);
	colorear(NEGRO, " ██║╚██╔╝██║██╔══██║╚════██║   ██║   ██╔══╝  ██╔══██╗    ██║╚██╔╝██║██║██║╚██╗██║██╔══╝  ██╔══██╗\n", AMARILLO);
	colorear(NEGRO, " ██║ ╚═╝ ██║██║  ██║███████║   ██║   ███████╗██║  ██║    ██║ ╚═╝ ██║██║██║ ╚████║███████╗██║  ██║\n", AMARILLO);
	colorear(NEGRO, " ╚═╝     ╚═╝╚═╝  ╚═╝╚══════╝   ╚═╝   ╚══════╝╚═╝  ╚═╝    ╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝\n", AMARILLO);
}

void printGameOver() {
    colorear(NEGRO, "                                     \n", ROJO);
	colorear(NEGRO, "   ▄████  ▄▄▄       ███▄ ▄███▓▓█████ \n", ROJO);
	colorear(NEGRO, "  ██▒ ▀█▒▒████▄    ▓██▒▀█▀ ██▒▓█   ▀ \n", ROJO);
	colorear(NEGRO, " ▒██░▄▄▄░▒██  ▀█▄  ▓██    ▓██░▒███   \n", ROJO);
	colorear(NEGRO, " ░▓█  ██▓░██▄▄▄▄██ ▒██    ▒██ ▒▓█  ▄ \n", ROJO);
	colorear(NEGRO, " ░▒▓███▀▒ ▓█   ▓██▒▒██▒   ░██▒░▒████▒\n", ROJO);
	colorear(NEGRO, "  ░▒   ▒  ▒▒   ▓▒█░░ ▒░   ░  ░░░ ▒░ ░\n", ROJO);
	colorear(NEGRO, "   ░   ░   ▒   ▒▒ ░░  ░      ░ ░ ░  ░\n", ROJO);
	colorear(NEGRO, " ░ ░   ░   ░   ▒   ░      ░      ░   \n", ROJO);
	colorear(NEGRO, "       ░       ░  ░       ░      ░  ░\n", ROJO);
	colorear(NEGRO, "                                     \n", ROJO);
	colorear(NEGRO, "  ▒█████   ██▒   █▓▓█████  ██▀███    \n", ROJO);
	colorear(NEGRO, " ▒██▒  ██▒▓██░   █▒▓█   ▀ ▓██ ▒ ██▒  \n", ROJO);
	colorear(NEGRO, " ▒██░  ██▒ ▓██  █▒░▒███   ▓██ ░▄█ ▒  \n", ROJO);
	colorear(NEGRO, " ▒██   ██░  ▒██ █░░▒▓█  ▄ ▒██▀▀█▄    \n", ROJO);
	colorear(NEGRO, " ░ ████▓▒░   ▒▀█░  ░▒████▒░██▓ ▒██▒  \n", ROJO);
	colorear(NEGRO, " ░ ▒░▒░▒░    ░ ▐░  ░░ ▒░ ░░ ▒▓ ░▒▓░  \n", ROJO);
	colorear(NEGRO, "   ░ ▒ ▒░    ░ ░░   ░ ░  ░  ░▒ ░ ▒░  \n", ROJO);
	colorear(NEGRO, " ░ ░ ░ ▒       ░░     ░     ░░   ░   \n", ROJO);
	colorear(NEGRO, "     ░ ░        ░     ░  ░   ░       \n", ROJO);
	colorear(NEGRO, "               ░                     \n", ROJO);
}

void sprite(tElemento elem, int section, tColor colorFondo, tColor colorTexto) {
    switch(elem) {
        case MINERO:
            if(section == 1) {
				colorear(colorFondo, "┏━┓", colorTexto);
            }
            else if (section == 2) {
				colorear(colorFondo, "┃w┃", colorTexto);
            }
            else if (section == 3) {
				colorear(colorFondo, "┣━┫", colorTexto);
            }
			break;
		case DINAMITA:
            if(section == 1) {
				colorear(colorFondo, "╔═╗", colorTexto);
            }
            else if (section == 2) {
				colorear(colorFondo, "TNT", colorTexto);
			}
            else if (section == 3) {
				colorear(colorFondo, "╚═╝", colorTexto);
            }
			break;
		case GEMA:
            if(section == 1) {
				colorear(colorFondo, "╭─╮", colorTexto);
            }
            else if (section == 2) {
				colorear(colorFondo, "│€│", colorTexto);
			}
            else if (section == 3) {
				colorear(colorFondo, "╰─╯", colorTexto);
            }
			break;
		case SALIDA:
            if(section == 1) {
				colorear(colorFondo, "┎─┐", colorTexto);
            }
            else if (section == 2) {
				colorear(colorFondo, "┠─┘", colorTexto);
			}
            else if (section == 3) {
				colorear(colorFondo, "┃  ", colorTexto);
            }
			break;
		default:
			string msg = "";
			for (size_t i = 0; i < 3; i++) {
				msg += to_string(elem);
			}
			colorear(colorFondo, msg, colorTexto);
    }
}

void colorear(tColor colorFondo, string msg, tColor colorTexto) {
    #ifdef _WIN32
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(handle, int(colorTexto) | (int(colorFondo) << 4));
        cout << msg;
        SetConsoleTextAttribute(handle, 15 | (0 << 4));
    #elif __linux__
        cout << "\e[1;" << ctr[int(colorTexto)] << ";" << ctr[int(colorFondo)] + 10 << "m" + msg + "\e[m";
    #endif
}