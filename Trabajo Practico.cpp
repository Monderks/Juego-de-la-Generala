#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

#include "SantyLib.h"
#include "Menu.h"

int main() {
    string cosito[5];
    int mayorPuntuacion = 0;
    int rondasMayorPuntuacion = 0;
    string mayorNombre;
    bool seguirEjecutandoJuego = true;
    bool ganoConPrimeraGenerala = false;

    //nuevo main.

    while (seguirEjecutandoJuego) {

    cosito[0] = "presione 1 para iniciar el juego en modo 1 jugador";
    cosito[1] = "presione 2 para iniciar el juego en modo 2 jugadores";
    cosito[2] = "presione 3 para ver las instrucciones";
    cosito[3] = "presione 4 para ver la puntuacion mas alta";
    cosito[4] = "presione 0 para salir";
    switch (menu(cosito, 5)) {
    case '1': {

        /*modoUnJugador( mayorPuntuacion,
             rondasMayorPuntuacion,
             menorRondas,
             mayorNombre);*/
        
        system("cls");
        int puntaje;    //PUNTAJE ES LA PUNTUACION POR RONDA
        bool primera_Generala = false;
        bool juegoterminado = false;
        int ronda = 0;
        int puntos = 0;  //PUNTOS ES EL PUNTAJE TOTAL
        int dados[5];
        int j;
        string nombre = pedir_nombre();
        while (ronda != 10 && juegoterminado == false) {
            int turno = 0;
            ronda++;
            turno++;
            bool seguir = true;
            srand(time(NULL));
            for (int i = 0; i < 5; i++) {
                dados[i] = (rand() % 6) + 1;
            }

            while (turno < 3 && seguir) {
                puntaje = 0;
                turno++;
                cout << "Turno de: " << nombre << "            |            " << "Ronda Numero:  " << ronda << "           |           " << "Puntaje Total: " << puntos << endl;
                barrita();
                cout << "Lanzamiento Numero: " << turno;
                cout << endl;
                barrita();
                for (int i = 0; i < 5; i++) {
                    cout << "[" << dados[i] << "]";
                }
                if (todosIguales(dados) && turno == 1) {
                    ganoConPrimeraGenerala = true;
                    cout << endl;
                    cout << endl;
                    barrita();
                    cout << "Hiciste la generala servida!!" << endl;
                    barrita();
                    cout << "GANASTE EL JUEGO!!" << endl;
                    cout << "FELICIDADES!!" << endl;
                    juegoterminado = true;
                    barrita();
                    system("pause");
                    system("cls");
                    main();
                }
                else
                {
                    cout << endl;
                    barrita();
                    cout << endl;
                    if (!seguirLanzando())
                    {
                        seguir = false;
                    }
                    else
                    {
                        cout << "cuantos dados? ";
                        cin >> j;
                        cout << endl;
                        for (int i = 0; i < j; i++) {
                            int f;
                            cout << "cual dado desea tirar? ";
                            cin >> f;
                            dados[f - 1] = rand() % 6 + 1;
                        }
                    }
                }
                

                system("cls");
            }
            //termina el while por turno

            cout << endl;
            cout << "los dados quedaron asi" << endl;
            barrita();
            for (int i = 0; i < 5; i++) {
                cout << "[" << dados[i] << "]";
            }
            cout << endl;
            barrita();
            if (generala(dados) == true && primera_Generala == false) {
                puntaje = puntaje + 50;
                puntos = puntos + puntaje;
                primera_Generala = true;
            }
            else {
                if (generala(dados) == true) {
                    puntaje = puntaje + 100;
                    puntos = puntos + puntaje;
                }
                else {
                    if (poker(dados) == true) {
                        puntaje = puntaje + 40;
                        puntos = puntos + puntaje;
                    }
                    else {
                        if (full(dados) == true) {
                            puntaje = puntaje + 30;
                            puntos = puntos + puntaje;
                        }
                        else {
                            if (escalera(dados) == true) {
                                puntaje = puntaje + 25;
                                puntos = puntos + puntaje;
                            }
                            else {
                                puntaje = puntaje + trio_duo_mayor(dados);
                                puntos = puntos + puntaje;
                            }


                        }
                    }
                }
            }
            cout << "Ronda Numero= " << ronda << endl;
            barrita();
            cout << "Nombre= " << nombre << endl;
            barrita();
            cout << "Tu puntaje de la ronda es= " << puntaje << endl;
            barrita();
            system("pause");
            system("cls");

        }//termino de while

        barrita();
        cout << "Terminaste tu partida de Generala solitario" << endl;
        barrita();
        cout << "Puntos totales ganados= " << puntos << endl;
        cout << "Rondas totales= " << ronda << endl;
        barrita();
        barrita();
        cout << "Para volver al menu principal presione 1, presione 2 para salir" << endl;

        // ACA SE COMPARA LA PUNTUACION CON LA PUNTUACION MAYOR
        //si es la primera ronada, menorRonda deberia tener valor-1
        //en caso de ser la primera ronda, la asigna como la ronda de mayor puntuacion
        //en caso de ser la partida con menor cantidad de rondas, tambien la asigna como partida con mayor puntuacion
        if (ganoConPrimeraGenerala==true)
        {
            mayorNombre = nombre;
            mayorPuntuacion = puntos;
            rondasMayorPuntuacion = ronda;
        }
        else {
        if (puntos > mayorPuntuacion) {
            mayorNombre = nombre;
            mayorPuntuacion = puntos;
            rondasMayorPuntuacion = ronda;
        }
}

        bool teclaPulsada = false;
        while (teclaPulsada == false) {
            if (_kbhit()) {
                char tecla = _getch();
                if (tecla == '1') {
                    system("cls");
                }
                else if (tecla == '2') {
                    seguirEjecutandoJuego = false;
                }
                else {
                    cout << "Tecla invalida, hasta luego" << endl;
                    system("pause");
                    seguirEjecutandoJuego = false;
                }
                teclaPulsada = true;
            }
        }

        
    }
        break;
    case '2':
        cout << "peruano2" << endl; 
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
