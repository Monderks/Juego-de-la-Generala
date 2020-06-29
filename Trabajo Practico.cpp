#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

#include "Juego.h"
#include "Menu.h"
#include "Dados.h"

int main() {
    system("mode con: cols=121 lines=31");
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
        mostrarMayorPuntuacion(mayorNombre, mayorPuntuacion, rondasMayorPuntuacion, seguirEjecutandoJuego);
    }
        break;
    case '0': {
        gotoxy(2, 20); cout << "Hasta luego" << endl;
        return 0;
    }
    default:{
        gotoxy(2, 21); cout << "seleccione por favor del 0 al 4, gracias" << endl;
    }
    }
    
    }
    return 0;
    
}
