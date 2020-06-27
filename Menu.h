#pragma once
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <iostream>

using namespace std;
void gotoxy(int x, int y) {
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
    
}
void pintar_bordes() {
    for (int i = 1; i < 120; i++) {
        gotoxy(i, 1); printf("%c", 205);
        gotoxy(i, 30); printf("%c", 205);
    };
    for (int i = 1; i < 30; i++) {
        gotoxy(1, i); printf("%c", 186);
        gotoxy(119, i); printf("%c", 186);
    };
    gotoxy(1, 1); printf("%c", 201);
    gotoxy(1, 30); printf("%c", 200);
    gotoxy(119, 1); printf("%c", 187);
    gotoxy(119, 30); printf("%c", 188);
};
// retorna el valor de la tecla pulsada
int Y;
char menu(string asd[], int opciones) {
    pintar_bordes();
    int _Y = (opciones * 2) + 2;
    for (int i = 0; i < opciones; i++)
    {
        Y = (i * 2) + 2;
        gotoxy(2, (i * 2) + 2); cout << asd[i];
    }
    bool teclaPulsada = false;
    while (teclaPulsada == false) {
        if (_kbhit()) {
            char tecla = _getch();


            gotoxy(2, Y + 2);


            return tecla;
            teclaPulsada = true;
        }
    }

}
