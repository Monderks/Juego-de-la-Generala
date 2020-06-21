#pragma once

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>            

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
string pedir_nombre() {
    char nombre[100];
    cout << "  Bienvenido al Juego solitario" << endl;
    cout << "  Ingresar su nombre" << endl;
    cin.getline(nombre,100);
    system("cls");
    return nombre;
    }
void pedir_nombre2() {
    char nombre2[100];
    cout << "  Ingresar su nombre" << endl;
    cin.getline(nombre2, 100);

}
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

void modoUnJugador(int &mayorPuntuacion,
int &rondasMayorPuntuacion,
string &mayorNombre,
bool &seguirEjecutandoJuego,
bool &ganoConPrimeraGenerala,
bool &puntuacionMaximaFueConGeneralaServida){

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
        string nombre = pedir_nombre();
        cout << "Para ingresar cantidad de rondas, ingresar 1" << endl;
        cout << "Para ingresar rondas predefinidas, ingresar 0 (10 rondas)" << endl;
        cin >> n;
        if (n == '1') {
            cout << "Ingresar la cantidad de rondas" << endl;
            cin >> cant_rondas;
        }
        else {
            while (n != '1' && n != '0') {
                    cout << "por favor ingresar un digito valido." << endl;
                    cout << "Para ingresar cantidad de rondas, ingresar 1" << endl;
                    cout << "Para ingresar rondas predefinidas, ingresar 0 (10 rondas)" << endl;
                    cin >> n;
                    if (n == '1') {
                        cout << "Ingresar la cantidad de rondas" << endl;
                        cin >> cant_rondas;
                    }
            }
        }
        system("cls");
        while (ronda != cant_rondas && juegoterminado == false) {
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

        // ACA SE COMPARA LA PUNTUACION CON LA PUNTUACION MAYOR
        //si es la primera ronada, menorRonda deberia tener valor-1
        //en caso de ser la primera ronda, la asigna como la ronda de mayor puntuacion
        //en caso de ser la partida con menor cantidad de rondas, tambien la asigna como partida con mayor puntuacion

        

        if (ganoConPrimeraGenerala==true)
        {
            mayorNombre = nombre;
            mayorPuntuacion = puntos;
            rondasMayorPuntuacion = ronda;
            puntuacionMaximaFueConGeneralaServida = true;
        }
        else {
            if (puntos > mayorPuntuacion || puntuacionMaximaFueConGeneralaServida == false) {
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


void menuJuego() {


}