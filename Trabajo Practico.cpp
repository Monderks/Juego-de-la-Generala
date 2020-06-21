#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

#include "SantyLib.h"
#include "Menu.h"

int main() {
    srand((unsigned int)time(NULL));
    string cosito[5];
    int mayorPuntuacion = 0;
    int rondasMayorPuntuacion = 0;
    string mayorNombre;
    bool seguirEjecutandoJuego = true;
    bool ganoConPrimeraGenerala = false;
    bool puntuacionMaximaFueConGeneralaServida = false;

    //nuevo main.

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
    case '3':
        cout << "peruano3" << endl; 
        break;
    case '4': {
        system("cls");
        barrita();
        cout << "La persona con el puntaje mas alto de ambos modos de juego es= " << endl;
        barrita();
        cout << "Nombre= " << mayorNombre << endl;
        cout << "Su puntuacion es= " << mayorPuntuacion << endl;
        cout << "En la cantidad de rondas= " << rondasMayorPuntuacion << endl;
        barrita();
        cout << "Para volver al menu principal presione 1, presione 2 para salir" << endl;
        bool teclaPulsada = false;
        while (teclaPulsada == false) {
            if (_kbhit()) {
                char tecla = _getch();
                if (tecla == '1') {
                    system("cls");
                    seguirEjecutandoJuego=false;
                }
                else if (tecla == '2') {
                    system("exit");
                }
                else {
                    cout << "Tecla invalida, hasta luego" << endl;
                    system("pause");
                    seguirEjecutandoJuego=false;
                }
                teclaPulsada = true;
            }
        }
         }
        break;
    case '0':
        cout << "asta la procsima" << endl;
        return 0;
    default:
        cout << "seleccione por favor del 0 al 4, gracias" << endl;
    }

    //termina el while infinito
    }

    return 0;
}
