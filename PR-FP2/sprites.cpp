#include <iostream>
#include <string>
#include "sprites.h"
using namespace std;
const vector<int> ctr = { 30,34,32,36,31,35,33,37,90 };
const tTheme ThemeName = THEME_DEFAULT;

void systemClear() {
#ifdef _WIN32
	system("cls");
#elif __linux__
	system("clear");
#endif
}

tColor theme(char opt, tElemento elem) {
	tColor res;

	switch(ThemeName) {
		case THEME_DEFAULT:
			switch(elem) {
				case TIERRA:
					res = tColor(opt=='t'? AMARILLO : GRIS); 
					break;
				case PIEDRA:
					res = tColor(opt=='t'? GRIS : NEGRO);
					break;
				case MURO:
					res = tColor(opt=='t'? GRIS : GRIS);
					break;
				case GEMA:
					res = tColor(opt=='t'? VERDE : NEGRO);
					break;
				case SALIDA:
					res = tColor(opt=='t'? MORADO : NEGRO);
					break;
				case MINERO:
					res = tColor(opt=='t'? AZUL : NEGRO);
					break;
				case LIBRE:
					res = tColor(opt=='t'? NEGRO : NEGRO);
					break;
				case DINAMITA:
					res = tColor(opt=='t'? ROJO : NEGRO); 
					break;
				default:
					res = tColor(opt=='t'? MORADO : AMARILLO);
			}
			break;
		case THEME_BnW:
		default:
			res = tColor(opt=='t'? BLANCO : NEGRO);
	}

	return res;
}

void printTitleScreen(tColor colorFondo, tColor colorTexto) {
	systemClear();
    colorear(colorFondo, "                                                                                                 \n", colorTexto);
    colorear(colorFondo, " ███╗   ███╗ █████╗ ███████╗████████╗███████╗██████╗     ███╗   ███╗██╗███╗   ██╗███████╗██████╗ \n", colorTexto);
	colorear(colorFondo, " ████╗ ████║██╔══██╗██╔════╝╚══██╔══╝██╔════╝██╔══██╗    ████╗ ████║██║████╗  ██║██╔════╝██╔══██╗\n", colorTexto);
	colorear(colorFondo, " ██╔████╔██║███████║███████╗   ██║   █████╗  ██████╔╝    ██╔████╔██║██║██╔██╗ ██║█████╗  ██████╔╝\n", colorTexto);
	colorear(colorFondo, " ██║╚██╔╝██║██╔══██║╚════██║   ██║   ██╔══╝  ██╔══██╗    ██║╚██╔╝██║██║██║╚██╗██║██╔══╝  ██╔══██╗\n", colorTexto);
	colorear(colorFondo, " ██║ ╚═╝ ██║██║  ██║███████║   ██║   ███████╗██║  ██║    ██║ ╚═╝ ██║██║██║ ╚████║███████╗██║  ██║\n", colorTexto);
	colorear(colorFondo, " ╚═╝     ╚═╝╚═╝  ╚═╝╚══════╝   ╚═╝   ╚══════╝╚═╝  ╚═╝    ╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚══════╝╚═╝  ╚═╝\n", colorTexto);
}

void printGameOver(tColor colorFondo, tColor colorTexto) {
	systemClear();
    colorear(colorFondo, "                                     \n", colorTexto);
	colorear(colorFondo, "   ▄████  ▄▄▄       ███▄ ▄███▓▓█████ \n", colorTexto);
	colorear(colorFondo, "  ██▒ ▀█▒▒████▄    ▓██▒▀█▀ ██▒▓█   ▀ \n", colorTexto);
	colorear(colorFondo, " ▒██░▄▄▄░▒██  ▀█▄  ▓██    ▓██░▒███   \n", colorTexto);
	colorear(colorFondo, " ░▓█  ██▓░██▄▄▄▄██ ▒██    ▒██ ▒▓█  ▄ \n", colorTexto);
	colorear(colorFondo, " ░▒▓███▀▒ ▓█   ▓██▒▒██▒   ░██▒░▒████▒\n", colorTexto);
	colorear(colorFondo, "  ░▒   ▒  ▒▒   ▓▒█░░ ▒░   ░  ░░░ ▒░ ░\n", colorTexto);
	colorear(colorFondo, "   ░   ░   ▒   ▒▒ ░░  ░      ░ ░ ░  ░\n", colorTexto);
	colorear(colorFondo, " ░ ░   ░   ░   ▒   ░      ░      ░   \n", colorTexto);
	colorear(colorFondo, "       ░       ░  ░       ░      ░  ░\n", colorTexto);
	colorear(colorFondo, "                                     \n", colorTexto);
	colorear(colorFondo, "  ▒█████   ██▒   █▓▓█████  ██▀███    \n", colorTexto);
	colorear(colorFondo, " ▒██▒  ██▒▓██░   █▒▓█   ▀ ▓██ ▒ ██▒  \n", colorTexto);
	colorear(colorFondo, " ▒██░  ██▒ ▓██  █▒░▒███   ▓██ ░▄█ ▒  \n", colorTexto);
	colorear(colorFondo, " ▒██   ██░  ▒██ █░░▒▓█  ▄ ▒██▀▀█▄    \n", colorTexto);
	colorear(colorFondo, " ░ ████▓▒░   ▒▀█░  ░▒████▒░██▓ ▒██▒  \n", colorTexto);
	colorear(colorFondo, " ░ ▒░▒░▒░    ░ ▐░  ░░ ▒░ ░░ ▒▓ ░▒▓░  \n", colorTexto);
	colorear(colorFondo, "   ░ ▒ ▒░    ░ ░░   ░ ░  ░  ░▒ ░ ▒░  \n", colorTexto);
	colorear(colorFondo, " ░ ░ ░ ▒       ░░     ░     ░░   ░   \n", colorTexto);
	colorear(colorFondo, "     ░ ░        ░     ░  ░   ░       \n", colorTexto);
	colorear(colorFondo, "               ░                     \n", colorTexto);
}

void printVictory(tColor colorFondo, tColor colorTexto) {
	systemClear();
	colorear(NEGRO, "                                                                                 \n", colorTexto);
	colorear(NEGRO, "  ▄█    █▄   ▄█   ▄████████     ███      ▄██████▄     ▄████████  ▄█     ▄████████\n", colorTexto);
	colorear(NEGRO, " ███    ███ ███  ███    ███ ▀█████████▄ ███    ███   ███    ███ ███    ███    ███\n", colorTexto);
	colorear(NEGRO, " ███    ███ ███▌ ███    █▀     ▀███▀▀██ ███    ███   ███    ███ ███▌   ███    ███\n", colorTexto);
	colorear(NEGRO, " ███    ███ ███▌ ███            ███   ▀ ███    ███  ▄███▄▄▄▄██▀ ███▌   ███    ███\n", colorTexto);
	colorear(NEGRO, " ███    ███ ███▌ ███            ███     ███    ███ ▀▀███▀▀▀▀▀   ███▌ ▀███████████\n", colorTexto);
	colorear(NEGRO, " ███    ███ ███  ███    █▄      ███     ███    ███ ▀███████████ ███    ███    ███\n", colorTexto);
	colorear(NEGRO, " ███    ███ ███  ███    ███     ███     ███    ███   ███    ███ ███    ███    ███\n", colorTexto);
	colorear(NEGRO, "  ▀██████▀  █▀   ████████▀     ▄████▀    ▀██████▀    ███    ███ █▀     ███    █▀ \n", colorTexto);
	colorear(NEGRO, "                                                     ███    ███                  \n", colorTexto);


}

void sprite(tElemento elem, int section, tColor colorFondo, tColor colorTexto) {
    switch(elem) {
        case MINERO:
            if(section == 0) {
				colorear(colorFondo, "┏━┓", colorTexto);
            }
            else if (section == 1) {
				colorear(colorFondo, "┃w┃", colorTexto);
            }
            else if (section == 2) {
				colorear(colorFondo, "┣━┫", colorTexto);
            }
			break;
		case DINAMITA:
            if(section == 0) {
				colorear(colorFondo, "╔═╗", colorTexto);
            }
            else if (section == 1) {
				colorear(colorFondo, "TNT", colorTexto);
			}
            else if (section == 2) {
				colorear(colorFondo, "╚═╝", colorTexto);
            }
			break;
		case GEMA:
            if(section == 0) {
				colorear(colorFondo, "╭─╮", colorTexto);
            }
            else if (section == 1) {
				colorear(colorFondo, "│€│", colorTexto);
			}
            else if (section == 2) {
				colorear(colorFondo, "╰─╯", colorTexto);
            }
			break;
		case SALIDA:
            if(section == 0) {
				colorear(colorFondo, "┎─┐", colorTexto);
            }
            else if (section == 1) {
				colorear(colorFondo, "┠─┘", colorTexto);
			}
            else if (section == 2) {
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
