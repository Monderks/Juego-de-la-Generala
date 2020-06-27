#pragma once
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>   
#include "Menu.h"
#include "Dados.h"
#include "Jugadas.h"

void barrita() {
    cout << "------------------------------------------------------------------------------------------------------------------------"<<endl;
}
bool seguirLanzando() {
    char j;
    cout << "Desea seguir lanzando? (s / n) ";
    cin >> j;
    cout << endl;
    if (j == 's' || j == 'S') {
        return true;
    }
    else if (j == 'n'||j == 'N') {
        return false;
    }
    else {
        while (j != 's' || j != 'S' || j != 'n' || j != 'N') {
            barrita();
            cout << "Esa opcion no es aceptable." << endl << "por favor, volver a ingresar un digito valido." << endl;
            barrita();
            cout << "Desea seguir lanzando? (s / n) ";
            cin >> j;
            cout << endl;
            if (j == 's' || j == 'S') {
                return true;
            }
            else if (j == 'n' || j == 'N') {
                return false;
            }
            }
    }

}
string pedir_nombre(bool nombre_primer_jugador) {
    string nombre;
     
    if (nombre_primer_jugador == true) {
        gotoxy(2, 4); cout << "Ingresar el nombre del jugador" << endl;
        gotoxy(2, 6); cin >> nombre;
        return nombre;
    }
    if (nombre_primer_jugador == false) {
            gotoxy(2, 4); cout << "Ingresar el nombre del segundo jugador" << endl;
            gotoxy(2, 6); cin >> nombre;
            return nombre;
        }
    }  
//Un jugador.
void modoUnJugador(int &mayorPuntuacion,int &rondasMayorPuntuacion,string &mayorNombre,
bool &seguirEjecutandoJuego,bool &ganoConPrimeraGenerala,bool &puntuacionMaximaFueConGeneralaServida){
    bool modojuego_singular = true;
    system("cls");
        int puntaje;    //PUNTAJE ES LA PUNTUACION POR RONDA
        bool juegoterminado = false;
        int ronda = 0;
        int cant_rondas=10;
        char opcion_dado;
        int puntos = 0;  //PUNTOS ES EL PUNTAJE TOTAL
        int dados[5];
        int j;
        system("cls");
        gotoxy(2, 5); barrita();
        gotoxy(2, 7); barrita();
        pintar_bordes();
        gotoxy(2, 2); cout << "Bienvenido al Juego solitario" << endl;
        string nombre = pedir_nombre(true);
        system("cls");
        gotoxy(2, 5); barrita();
        pintar_bordes();
        gotoxy(2, 2); cout << "Para ingresar cantidad de rondas, ingresar 1" << endl;
        gotoxy(2, 4); cout << "Para ingresar rondas predefinidas, ingresar 0 (10 rondas)" << endl;
        gotoxy(2, 6); cin >> opcion_dado;
        if (opcion_dado == '1') {
            gotoxy(2, 8); cout << "Ingresar la cantidad de rondas" << endl;
            gotoxy(2, 10); cin >> cant_rondas;
        }
        else {
            while (opcion_dado != '1' && opcion_dado != '0') {
                system("cls");
                gotoxy(2, 7); barrita();
                gotoxy(2, 9); barrita();
                pintar_bordes();
                gotoxy(2, 2); cout << "por favor ingresar un digito valido." << endl;
                gotoxy(2, 4); cout << "Para ingresar cantidad de rondas, ingresar 1" << endl;
                gotoxy(2, 6); cout << "Para ingresar rondas predefinidas, ingresar 0 (10 rondas)" << endl;
                gotoxy(2, 8); cin >> opcion_dado;
                if (opcion_dado == '1') {
                    gotoxy(2, 11); barrita();
                    gotoxy(2, 13); barrita();
                    pintar_bordes();
                    gotoxy(2, 10); cout << "Ingresar la cantidad de rondas" << endl;
                    gotoxy(2, 12); cin >> cant_rondas;
                }
            }
        }
        
        system("cls");
        while (ronda != cant_rondas && juegoterminado == false) {
            int turno = 0;
            ronda++;
            turno++;
            bool seguir = true;
            for (int i = 0; i < 5; i++) {
                dados[i] = (rand() % 6) + 1;
            }

            while (turno < 3 && seguir) {
                puntaje = 0;
                turno++;
                gotoxy(2; 1); cout << "Turno de: " << nombre << "|";
                gotoxy(2; 5); cout << "Ronda Numero " << ronda << "|";
                gotoxy(2; 9); cout << "Puntaje Total: " << puntos;
                barrita();
                cout << "Lanzamiento Numero: " << turno;
                cout << endl;
                barrita();
                dibujar_dados(dados);
                cout << endl;
                cout << endl;
                
                if (generala(dados) && turno == 1) {
                    ganoConPrimeraGenerala = true;
                    cout << endl;
                    cout << endl;
                    pintar_bordes();
                    gotoxy(2, 7); barrita();
                    gotoxy(2, 8); cout << "Hiciste la generala servida!!" << endl;
                    gotoxy(2, 9); barrita();
                    gotoxy(2, 10); cout << "GANASTE EL JUEGO!!" << endl;
                    gotoxy(2, 11); cout << "FELICIDADES!!" << endl;
                    juegoterminado = true;
                    gotoxy(2, 12); barrita();
                    system("pause");
                    system("cls");

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
            barrita();/*
            for (int i = 0; i < 5; i++) {
                cout << "[" << dados[i] << "]";
            }*/
            //---------------------------------------------
            dibujar_dados(dados);
            cout << endl;
            //---------------------------------------------
            cout << endl;
            barrita();
            if (generala(dados) == true) {
                puntaje = puntaje + 50;
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

       if (ganoConPrimeraGenerala==true)
        {
            mayorNombre = nombre;
            mayorPuntuacion = puntos;
            rondasMayorPuntuacion = ronda;
            puntuacionMaximaFueConGeneralaServida = true;
        }
        else {
            if (puntos > mayorPuntuacion && puntuacionMaximaFueConGeneralaServida == false) {
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
//dos jugadores.
void modoDosJugadores(int& mayorPuntuacion, int& rondasMayorPuntuacion, string & mayorNombre,
bool& seguirEjecutandoJuego, bool& ganoConPrimeraGenerala, bool& puntuacionMaximaFueConGeneralaServida) {
    bool modojuego_singular = false;
    system("cls");
        int puntaje=0;   //PUNTAJE ES LA PUNTUACION POR RONDA
        int puntaje2=0;
        bool juegoterminado = false;
        int ronda = 0;
        int cant_rondas = 10;
        char opcion_dado;
        int puntos = 0;  //PUNTOS ES EL PUNTAJE TOTAL
        int puntos2 = 0;
        int dados[5];
        int dados2[5];
        int j;
        gotoxy(2, 5); barrita();
        gotoxy(2, 7); barrita();
        pintar_bordes();
        gotoxy(2, 2); cout << "Bienvenido al Juego de dos jugadores" << endl;
        string nombre = pedir_nombre(true);
        system("cls");
        gotoxy(2, 5); barrita();
        gotoxy(2, 7); barrita();
        pintar_bordes();
        string nombre2 = pedir_nombre(false);
        system("cls");
        gotoxy(2, 5); barrita();
        pintar_bordes();
        gotoxy(2, 2); cout << "Para ingresar cantidad de rondas, ingresar 1" << endl;
        gotoxy(2, 4); cout << "Para ingresar rondas predefinidas, ingresar 0 (10 rondas)" << endl;
        gotoxy(2, 6); cin >> opcion_dado;
        if (opcion_dado == '1') {
            gotoxy(2, 8); cout << "Ingresar la cantidad de rondas" << endl;
            gotoxy(2, 10); cin >> cant_rondas;
        }
        else {
            while (opcion_dado != '1' && opcion_dado != '0') {
                system("cls");
                gotoxy(2, 7); barrita();
                gotoxy(2, 9); barrita();
                pintar_bordes();
                gotoxy(2, 2); cout << "por favor ingresar un digito valido." << endl;
                gotoxy(2, 4); cout << "Para ingresar cantidad de rondas, ingresar 1" << endl;
                gotoxy(2, 6); cout << "Para ingresar rondas predefinidas, ingresar 0 (10 rondas)" << endl;
                gotoxy(2, 8); cin >> opcion_dado;
                if (opcion_dado == '1') {
                    gotoxy(2, 11); barrita();
                    gotoxy(2, 13); barrita();
                    pintar_bordes();
                    gotoxy(2, 10); cout << "Ingresar la cantidad de rondas" << endl;
                    gotoxy(2, 12); cin >> cant_rondas;
                }
            }
        }
        system("cls");
        //-------------------------------------------------------------------------------------------
        //-------------------------------------------------------------------------------------------
        //-------------------------------------------------------------------------------------------
        //-------------------------------------------------------------------------------------------
        //-------------------------------------------------------------------------------------------

        while (ronda != cant_rondas && juegoterminado == false) {
            int turno = 0;
            ronda++;
            turno++;
            bool seguir = true;
            //carga los dados del jugador 1
            for (int i = 0; i < 5; i++) {
                dados[i] = (rand() % 6) + 1;
            }
            //dados los dados del jugador 2
            for (int i = 0; i < 5; i++) {
                dados2[i] = (rand() % 6) + 1;
            }
            //-------------------------------------------------------------------------------------------
            //-------------------------------------------------------------------------------------------
            //while  turno 1
            //-------------------------------------------------------------------------------------------
            //-------------------------------------------------------------------------------------------
            while (turno < 3 && seguir) {
                puntaje = 0;
                turno++;
                cout << "Turno de: " << nombre << "            |            " << "Ronda Numero:  " << ronda << "           |           " << "Puntaje Total: " << puntos << endl;
                barrita();
                cout << "Lanzamiento Numero: " << turno;
                cout << endl;
                barrita();/*
                for (int i = 0; i < 5; i++) {
                    cout << "[" << dados[i] << "]";
                }*/
                //---------------------------------------------
                dibujar_dados(dados);
                cout << endl;
                //---------------------------------------------
                if (generala(dados) && turno == 1) {
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
            //-------------------------------------------------------------------------------------------
            //-------------------------------------------------------------------------------------------
            //-------------------------------------------------------------------------------------------
            //termina while por turno1

            cout << endl;
            cout << "los dados quedaron asi" << endl;
            barrita();/*
            for (int i = 0; i < 5; i++) {
                cout << "[" << dados[i] << "]";
            }*/
            //-------------------------------------------------------------------------------------------
            dibujar_dados(dados);
            cout << endl;
            //-------------------------------------------------------------------------------------------
            cout << endl;
            barrita();
            if (generala(dados) == true) {
                puntaje = puntaje + 50;
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
            
            cout << "Ronda Numero= " << ronda << endl;
            barrita();
            cout << "Proximo turno es de= " << nombre2 << endl;
            barrita();
            cout << "Puntaje de= " << nombre << " : " << puntos << endl;
            cout << "Puntaje de= " << nombre2 << " : " << puntos2 << endl;
            barrita();
            system("pause");
            system("cls");
            //-------------------------------------------------------------------------------------------
            //-------------------------------------------------------------------------------------------
            //while  turno 2
            //-------------------------------------------------------------------------------------------
            //-------------------------------------------------------------------------------------------
            seguir = true;
            turno = 1;
            while (turno < 3 && seguir) {
                puntaje2 = 0;
                turno++;
                cout << "Turno de: " << nombre2 << "            |            " << "Ronda Numero:  " << ronda << "           |           " << "Puntaje Total: " << puntos2 << endl;
                barrita();
                cout << "Lanzamiento Numero: " << turno;
                cout << endl;
                barrita();/*
                for (int i = 0; i < 5; i++) {
                    cout << "[" << dados2[i] << "]";
                }*/
                //-------------------------------------------------------------------------------------------
                dibujar_dados(dados);
                cout << endl;
                //-------------------------------------------------------------------------------------------
                if (generala(dados2) && turno == 1) {
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
                            dados2[f - 1] = rand() % 6 + 1;
                        }
                    }
                }
                

                system("cls");
            }
            //-------------------------------------------------------------------------------------------
            //-------------------------------------------------------------------------------------------
            //-------------------------------------------------------------------------------------------
            //termina while por turno2
            //-------------------------------------------------------------------------------------------
            //-------------------------------------------------------------------------------------------
            //-------------------------------------------------------------------------------------------

            cout << endl;
            cout << "los dados quedaron asi" << endl;
            barrita();/*
            for (int i = 0; i < 5; i++) {
                cout << "[" << dados2[i] << "]";
            }*/
            //-------------------------------------------------------------------------------------------
            dibujar_dados(dados);
            cout << endl;
            //-------------------------------------------------------------------------------------------
            cout << endl;
            barrita();
            if (generala(dados2) == true) {
                puntaje2 = puntaje2 + 50;
                puntos2 = puntos2 + puntaje2;
            }
            else {
                if (poker(dados2) == true) {
                        puntaje2 = puntaje2 + 40;
                        puntos2 = puntos2 + puntaje2;
                    }
                    else {
                        if (full(dados2) == true) {
                            puntaje2 = puntaje2 + 30;
                            puntos2 = puntos2 + puntaje2;
                        }
                        else {
                            if (escalera(dados2) == true) {
                                puntaje2 = puntaje2 + 25;
                                puntos2 = puntos2 + puntaje2;
                            }
                            else {
                                puntaje2 = puntaje2 + trio_duo_mayor(dados2);
                                puntos2 = puntos2 + puntaje2;
                            }


                        }
                    }
                }
            
            cout << "Ronda Numero= " << ronda << endl;
            barrita();
            cout << "Proximo turno es de= " << nombre << endl;
            barrita();
            cout << "Puntaje de= " << nombre << " : " << puntos << endl;
            cout << "Puntaje de= " << nombre2 << " : " << puntos2 << endl;
            barrita();
            system("pause");
            system("cls");
            //-------------------------------------------------------------------------------------------
            //-------------------------------------------------------------------------------------------
            //-------------------------------------------------------------------------------------------
            //-------------------------------------------------------------------------------------------

        }//termino de while
        
        barrita();
        cout << "Termino la partida de Generala Dos Jugadores" << endl;
        barrita();
        cout << "Jugador= " << nombre << endl;
        cout << "Puntos totales ganados del primer jugador= " << puntos << endl;
        barrita();
        cout << "Jugador= " << nombre2 << endl;
        cout << "Puntos totales ganados del segundo jugador= " << puntos2 << endl;
        barrita();
        cout << "Rondas totales= " << ronda << endl;
        barrita();
        barrita();

        system("pause");
        system("cls");
        string nombre_ganador2p;
        int puntuacion_ganador2p;

        if (puntos > puntos2) {
            cout << "El ganador es el Jugador: " << nombre << endl;
            cout << "Felicidades" << endl;
            nombre_ganador2p = nombre;
            puntuacion_ganador2p = puntos;
        }
        else if (puntos == puntos2) {
            cout << "Hubo un empate" << endl;
            cout << "Jueguense otra y denme de comer por favor" << endl;
            nombre_ganador2p = nombre+nombre2;
            puntuacion_ganador2p = puntos;
        }
        else {
            cout << "El ganador es el Jugador: " << nombre2 << endl;
            cout << "Felicidades" << endl;
            nombre_ganador2p = nombre2;
            puntuacion_ganador2p = puntos2;
        }

        barrita();

        cout << "Para volver al menu principal presione 1, presione 2 para salir" << endl;

        if (ganoConPrimeraGenerala == true)
        {
            mayorNombre = nombre_ganador2p;
            mayorPuntuacion = puntuacion_ganador2p;
            rondasMayorPuntuacion = ronda;
            puntuacionMaximaFueConGeneralaServida = true;
        }
        else {
            if (puntuacion_ganador2p > mayorPuntuacion && puntuacionMaximaFueConGeneralaServida == false) {
                mayorNombre = nombre_ganador2p;
                mayorPuntuacion = puntuacion_ganador2p;
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
void mostrarMayorPuntuacion(string mayorNombre,int mayorPuntuacion,int rondasMayorPuntuacion,bool &seguirEjecutandoJuego) {
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
                seguirEjecutandoJuego = true;
            }
            else if (tecla == '2') {
                system("cls");
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
void instrucciones() {
    gotoxy(2, 2); cout << "Reglamentos del Juego" << endl;
    gotoxy(2, 3); barrita();
    gotoxy(2, 4); cout << "El objetivo del juego es sacar Generala Servida, u obtener la puntuacion mas alta de un conjunto de rondas" << endl;
    gotoxy(2, 5); cout << "establecidas. Una ronda puede estar compuesta por hasta tres lanzamientos por jugador. Un lanzamiento" << endl;
    gotoxy(2, 6); cout << "consiste en tirar los cinco dados y evaluar sus valores para determinar el puntaje. En caso que el" << endl;
    gotoxy(2, 7); cout << "jugador lo  considere puede volver a tirar todos a algunos de los dados en dos oportunidades mas. El" << endl;
    gotoxy(2, 8); cout << "sistema preguntara si quiere volver a lanzar, y si la respuesta es si, preguntara cuales son los dados" << endl;
    gotoxy(2, 9); cout << "que quiere elegir para volver a tirar. El puntaje de un lanzamiento esta determinado por una serie de" << endl;
    gotoxy(2, 10); cout << "de reglas que figuran en la seccion Combinaciones ganadoras. El puntaje obtenido se suma al puntaje" << endl;
    gotoxy(2, 11); cout << "anterior del jugador. Si un jugador saca Generala en el primer tiro gana la partida." << endl;
    gotoxy(2, 12); barrita();
    gotoxy(2, 13); cout << "|          Combinacion               | Nombre jugada |                Puntaje otorgado             |    " << endl;
    gotoxy(2, 14); barrita();
    gotoxy(2, 15); cout << "|    1 o mas dados con valor 1       |   Juego de 1  | Suma de la cantidad de dados con el valor 1 |" <<endl;
    gotoxy(2, 16); cout << "|    1 o mas dados con valor 2       |   Juego de 2  | Suma de la cantidad de dados con el valor 2 |" << endl;
    gotoxy(2, 17); cout << "|    1 o mas dados con valor 3       |   Juego de 3  | Suma de la cantidad de dados con el valor 3 |" << endl;
    gotoxy(2, 18); cout << "|    1 o mas dados con valor 4       |   Juego de 4  | Suma de la cantidad de dados con el valor 4 |" << endl;
    gotoxy(2, 19); cout << "|    1 o mas dados con valor 5       |   Juego de 5  | Suma de la cantidad de dados con el valor 5 |" << endl;
    gotoxy(2, 20); cout << "|    1 o mas dados con valor 6       |   Juego de 6  | Suma de la cantidad de dados con el valor 6 |" << endl;
    gotoxy(2, 21); barrita();
    gotoxy(2, 22); cout << "|    5 dados en orden creciente      |    Escalera   |                     25                      |" << endl;
    gotoxy(2, 23); cout << "|     (1,2,3,4,5)/(2,3,4,5,6)        |               |                                             |" << endl;
    gotoxy(2, 24); cout << "|3 dados iguales, mas otros 2 iguales|    Full       |                     30                      |" << endl;
    gotoxy(2, 25); cout << "|     (3,3,3,2,2)/(1,1,4,4,4)        |               |                                             |" << endl;
    gotoxy(2, 26); cout << "|      4 dados iguales               |    Poker      |                     40                      |" << endl;
    gotoxy(2, 27); cout << "|     (3,3,3,3,2), (1,4,4,4,4)       |               |                                             |" << endl;
    gotoxy(2, 28); cout << "|      5 dados con el mismo valor    |    Generala   |                     50                      |" << endl;
    gotoxy(2, 29); cout << "|     (1,1,1,1,1) , (6,6,6,6,6)      |               |                                             |" << endl;
    pintar_bordes();
    
}








