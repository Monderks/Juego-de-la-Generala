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
    printf;
}

void dados(){
for (int i = 1; i < 120; i++) {
    gotoxy(i, 1); printf("%c", 254);
    gotoxy(i, 30); printf("%c", 254);
};
for (int i = 1; i < 30; i++) {
    gotoxy(1, i); printf("%c", 221);
    gotoxy(119, i); printf("%c", 221);
};
gotoxy(1, 1); printf("%c", 201);
gotoxy(1, 30); printf("%c", 200);
gotoxy(119, 1); printf("%c", 187);
gotoxy(119, 30); printf("%c", 188);
}