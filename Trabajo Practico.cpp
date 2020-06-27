#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

#include "Juego.h"
#include "Menu.h"
#include "Dados.h"



int main() {
    srand((unsigned int)time(NULL));
    string cosito[5];
    int mayorPuntuacion = 0;
    int rondasMayorPuntuacion = 0;
    string mayorNombre;
    bool seguirEjecutandoJuego = true;
    bool ganoConPrimeraGenerala = false;
    bool puntuacionMaximaFueConGeneralaServida = false;
    while (seguirEjecutandoJuego) {
    cosito[0] = "presione 1 para iniciar el juego en modo 1 jugador";
    cosito[1] = "presione 2 para iniciar el juego en modo 2 jugadores";
    cosito[2] = "presione 3 para ver las instrucciones";
    cosito[3] = "presione 4 para ver la puntuacion mas alta";
    cosito[4] = "presione 0 para salir";
    switch (menu(cosito, 5)) {
    case '1': {
        
       modoUnJugador(mayorPuntuacion,
        rondasMayorPuntuacion,
        mayorNombre,
        seguirEjecutandoJuego,
        ganoConPrimeraGenerala,
        puntuacionMaximaFueConGeneralaServida);
        
    }
        break;
    case '2': {
        modoDosJugadores(mayorPuntuacion,
            rondasMayorPuntuacion,
            mayorNombre,
            seguirEjecutandoJuego,
            ganoConPrimeraGenerala,
            puntuacionMaximaFueConGeneralaServida);
    }
        break;
    case '3': {
        system("cls");
        instrucciones();
        system("pause");
        system("cls");
    }
        break;
    case '4': {

        //mostrarMayorPuntuacion(mayorNombre, mayorPuntuacion, rondasMayorPuntuacion, seguirEjecutandoJuego);
        
        system("cls");
        pintar_bordes();
        gotoxy(2, 2); barrita();
        gotoxy(30, 3); cout << "La persona con el puntaje mas alto de ambos modos de juego es= " << endl;
        gotoxy(2, 4); barrita();
        gotoxy(48, 5); cout << "Nombre= " << mayorNombre << endl;
        gotoxy(48, 6); cout << "Su puntuacion es= " << mayorPuntuacion << endl;
        gotoxy(48, 7); cout << "En la cantidad de rondas= " << rondasMayorPuntuacion << endl;
        gotoxy(2, 8); barrita();
        gotoxy(2, 20); cout << "Para volver al menu principal presione 1, presione 2 para salir" << endl;
        bool teclaPulsada = false;
        while (teclaPulsada == false) {
            if (_kbhit()) {
                char tecla = _getch();
                if (tecla == '1') {
                    system("cls");
                    seguirEjecutandoJuego=true;
                }
                else if (tecla == '2') {
                    system("cls");
                    seguirEjecutandoJuego = false;
                }
                else {
                    gotoxy(2, 22); cout << "Tecla invalida, hasta luego" << endl;
                    gotoxy(2, 23); system("pause");
                    seguirEjecutandoJuego=false;
                }
                teclaPulsada = true;
            }
        }
         }
        break;
    case '0':
        gotoxy(2, 20); cout << "asta la procsima" << endl;
        return 0;
    default:
        gotoxy(2, 21); cout << "seleccione por favor del 0 al 4, gracias" << endl;
    }
    
    }
    return 0;
}
