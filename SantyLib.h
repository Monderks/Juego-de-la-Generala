#pragma once

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>   
#include "Menu.h"

//barrita de todo.
void barrita() {
    cout << "------------------------------------------------------------------------------------------------------------------------"<<endl;
}
//----------------------------
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
//pedir nombre de solitario.
string pedir_nombre_unjugador() {
    system("cls");
    gotoxy(2, 5); barrita();
    gotoxy(2, 7); barrita();
    pintar_bordes();
    char nombre[100];
    gotoxy(2, 2); cout << "Bienvenido al Juego solitario" << endl;
    gotoxy(2, 4); cout << "Ingresar su nombre" << endl;

    //gotoxy(2, 6); cin.getline(nombre, 100); //con esto se bugeaba y despues de la primera partida no volvia a pedir el nombre
    gotoxy(2, 6); cin >> nombre;
    system("cls");
    return nombre;
}
//pedir nombre de dos jugadores.
string pedir_nombre_primer_jugador() {
    gotoxy(2, 5); barrita();
    gotoxy(2, 7); barrita();
    pintar_bordes();
    string nombre;
    gotoxy(2, 2); cout << "  Bienvenido al Juego de Dos Jugadores" << endl;
    gotoxy(2, 4); cout << "  Ingresar el nombre del primer participante" << endl;
    gotoxy(2, 6); cin >> nombre;
    system("cls");
    return nombre;
    }
string pedir_nombre_segundo_jugador() {
    gotoxy(2, 5); barrita();
    gotoxy(2, 7); barrita();
    pintar_bordes();
    string nombre;
    gotoxy(2, 2); cout << "  Ingresar el nombre del segundo participante" << endl;
    gotoxy(2, 6); cin >> nombre;
    system("cls");
    return nombre;
}
//Contador de rondas.
int verificador_de_rondas(char n){
    int rondas;
    if (n == '1') {
        cout << "Ingresar cantidad de rondas" << endl;
        cin >> rondas;
    }
    else {
        if (n != '1' && n != '0') {
            barrita();
            cout << "Esa opcion no es aceptable." << endl << "por favor, volver a ingresar un digito valido." << endl;
            barrita();
            cout << "Ingresar cantidad de rondas" << endl;
            cin >> rondas;
            cout << endl;
        }
    }
    return rondas;
}
//Todas modificaciones de los dados.
int repetidos_Dado(int dados[], int n) {
    int dado = 0;
    for (int i = 0; i < 5; i ++ ) {
        if (dados[i] == n) {
            dado++;
        }
    }
    return dado;
}
bool full(int dados[]) {
    int bandera = 0;
    int bandera1 = 0;
    for (int i = 1; i <= 6; i++) {
        if (repetidos_Dado(dados, i) == 3) {
            bandera++;
        }
    }
    for (int i = 1; i <= 6; i++) {
        if (repetidos_Dado(dados, i) == 2) {
                bandera1++;
            }

        }
    if (bandera == 1 && bandera1 == 1) {
        return true;
    }
    else {
        return false;
    }
}
bool poker(int dados[]) {
    for (int i = 1; i <= 6; i++) {
        if (repetidos_Dado(dados, i) == 4){
            return true;
        }
    }
    return false;
}
bool generala(int dados[]) {
    for (int i = 1; i <= 6; i++) {
        if (repetidos_Dado(dados, i) == 5) {
            return true;
        }
    }
    return false;
}
bool escalera(int dados[]) {
    int c = 0;
    int n = 0;
    for (int i = 1; i <= 5; i++) {
        if (repetidos_Dado(dados, i)==1) {
            c++;
        }
        
    }
    for (int i = 2; i <= 6; i++) {
        if (repetidos_Dado(dados, i) == 1) {
            n++;
        }

    }
    if (c == 5 || n==5) {
        return true;
    }
    else {
        return false;
    }
}
int trio(int dados[]) {
    for (int i = 1; i <= 6; i++) {
        if (repetidos_Dado(dados, i) == 3) {
            return i;
        }
    }
    return 0;
}
int duo_Doble(int dados[]) {
    bool unduo = false;
    int primerduo;
    for (int i = 1; i <= 6; i++) {
        if (repetidos_Dado(dados, i) == 2) {
            unduo=true;
            primerduo=i;
        }

    }
    if (unduo == true) {
        for (int i = 1; i <= 6; i++) {
            if (repetidos_Dado(dados, i) == 2 && repetidos_Dado(dados, i)!=primerduo) {
                if (primerduo > repetidos_Dado(dados, i)) {
                    return primerduo;
                }
                else repetidos_Dado(dados, i);
            }
            else {
                return primerduo;
            }
        }
    }
    return 0;
}
int mayor(int dados[]){
    int mayor = dados[0];
    for (int i = 0; i < 5; i++) {
        if (mayor<dados[i]) {
            mayor = dados[i];
        }

    }
    return mayor;
}
int trio_duo_mayor(int dados[]) {
    if (trio(dados)*3 > duo_Doble(dados)*2 && trio(dados)*3 > mayor(dados)) {
        return trio(dados)*3;
    }
    else {
        if (duo_Doble(dados)*2 > trio(dados)*3 && duo_Doble(dados)*2 > mayor(dados)) {
            return duo_Doble(dados)*2;
        }
        else {
            return mayor(dados);
        }
    }
}
//Un jugador.
void modoUnJugador(int &mayorPuntuacion,int &rondasMayorPuntuacion,string &mayorNombre,
bool &seguirEjecutandoJuego,bool &ganoConPrimeraGenerala,bool &puntuacionMaximaFueConGeneralaServida){

    system("cls");
        int puntaje;    //PUNTAJE ES LA PUNTUACION POR RONDA
        bool primera_Generala = false;
        bool juegoterminado = false;
        int ronda = 0;
        int cant_rondas=10;
        char n;
        int puntos = 0;  //PUNTOS ES EL PUNTAJE TOTAL
        int dados[5];
        int j;
        string nombre = pedir_nombre_unjugador();
        gotoxy(2, 5); barrita();
        pintar_bordes();
        gotoxy(2, 2); cout << "Para ingresar cantidad de rondas, ingresar 1" << endl;
        gotoxy(2, 4); cout << "Para ingresar rondas predefinidas, ingresar 0 (10 rondas)" << endl;
        gotoxy(2, 6); cin >> n;
        if (n == '1') {
            gotoxy(2, 8); cout << "Ingresar la cantidad de rondas" << endl;
            gotoxy(2, 10); cin >> cant_rondas;
        }
        else {
            while (n != '1' && n != '0') {
                system("cls");
                gotoxy(2, 7); barrita();
                gotoxy(2, 9); barrita();
                pintar_bordes();
                gotoxy(2, 2); cout << "por favor ingresar un digito valido." << endl;
                gotoxy(2, 4); cout << "Para ingresar cantidad de rondas, ingresar 1" << endl;
                gotoxy(2, 6); cout << "Para ingresar rondas predefinidas, ingresar 0 (10 rondas)" << endl;
                gotoxy(2, 8); cin >> n;
                if (n == '1') {
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
                cout << "Turno de: " << nombre << "            |            " << "Ronda Numero:  " << ronda << "           |           " << "Puntaje Total: " << puntos << endl;
                barrita();
                cout << "Lanzamiento Numero: " << turno;
                cout << endl;
                barrita();
                for (int i = 0; i < 5; i++) {
                    cout << "[" << dados[i] << "]";
                }
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

        system("cls");
        int puntaje=0;   //PUNTAJE ES LA PUNTUACION POR RONDA
        int puntaje2=0;
        bool primera_Generala = false;
        bool juegoterminado = false;
        int ronda = 0;
        int cant_rondas = 10;
        char n;
        int puntos = 0;  //PUNTOS ES EL PUNTAJE TOTAL
        int puntos2 = 0;
        int dados[5];
        int dados2[5];
        int j;
        string nombre = pedir_nombre_primer_jugador();
        string nombre2 = pedir_nombre_segundo_jugador();
        gotoxy(2, 5); barrita();
        pintar_bordes();
        gotoxy(2, 2); cout << "Para ingresar cantidad de rondas, ingresar 1" << endl;
        gotoxy(2, 4); cout << "Para ingresar rondas predefinidas, ingresar 0 (10 rondas)" << endl;
        gotoxy(2, 6); cin >> n;
        if (n == '1') {
            gotoxy(2, 8); cout << "Ingresar la cantidad de rondas" << endl;
            gotoxy(2, 10); cin >> cant_rondas;
        }
        else {
            while (n != '1' && n != '0') {
                system("cls");
                gotoxy(2, 7); barrita();
                gotoxy(2, 9); barrita();
                pintar_bordes();
                gotoxy(2, 2); cout << "por favor ingresar un digito valido." << endl;
                gotoxy(2, 4); cout << "Para ingresar cantidad de rondas, ingresar 1" << endl;
                gotoxy(2, 6); cout << "Para ingresar rondas predefinidas, ingresar 0 (10 rondas)" << endl;
                gotoxy(2, 8); cin >> n;
                if (n == '1') {
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
                barrita();
                for (int i = 0; i < 5; i++) {
                    cout << "[" << dados[i] << "]";
                }
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
                barrita();
                for (int i = 0; i < 5; i++) {
                    cout << "[" << dados2[i] << "]";
                }
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
            barrita();
            for (int i = 0; i < 5; i++) {
                cout << "[" << dados2[i] << "]";
            }
            cout << endl;
            barrita();
            if (generala(dados2) == true && primera_Generala == false) {
                puntaje2 = puntaje2 + 50;
                puntos2 = puntos2 + puntaje2;
                primera_Generala = true;
            }
            else {
                if (generala(dados2) == true) {
                    puntaje2 = puntaje2 + 100;
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









