#pragma once
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <iostream>

using namespace std;

void marco_dado(int x, int y) {
    gotoxy(x, y + 1); printf("%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
    gotoxy(x, y + 2); printf("%c         %c", 186, 186);
    gotoxy(x, y + 3); printf("%c         %c", 186, 186);
    gotoxy(x, y + 4); printf("%c         %c", 186, 186);
    gotoxy(x, y + 5); printf("%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);

}
void dibujar_dados(int dados[]) {
    cout << endl;
    int y;
    int x = 30;
    CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;
    HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!GetConsoleScreenBufferInfo(hStd, &screenBufferInfo))
        printf("GetConsoleScreenBufferInfo (%d)\n", GetLastError());
    y = screenBufferInfo.dwCursorPosition.Y;

    for (int i = 0; i < 5; i++) {
        switch (dados[i]) {
        case 1: {
            marco_dado(x, y);
            gotoxy(x + 5, y + 3); printf("%c", 254);
            break;
        }
        case 2: {
            marco_dado(x, y);

            gotoxy(x + 7, y + 2); printf("%c", 254);
            gotoxy(x + 3, y + 4); printf("%c", 254);
            break;
        }
        case 3: {
            marco_dado(x, y);

            gotoxy(x + 7, y + 2); printf("%c", 254);
            gotoxy(x + 5, y + 3); printf("%c", 254);
            gotoxy(x + 3, y + 4); printf("%c", 254);
            break;
        }
        case 4: {
            marco_dado(x, y);

            gotoxy(x + 7, y + 2); printf("%c", 254);
            gotoxy(x + 7, y + 4); printf("%c", 254);
            gotoxy(x + 3, y + 2); printf("%c", 254);
            gotoxy(x + 3, y + 4); printf("%c", 254);
            break;
        }
        case 5: {
            marco_dado(x, y);

            gotoxy(x + 7, y + 2); printf("%c", 254);
            gotoxy(x + 7, y + 4); printf("%c", 254);
            gotoxy(x + 5, y + 3); printf("%c", 254);
            gotoxy(x + 3, y + 2); printf("%c", 254);
            gotoxy(x + 3, y + 4); printf("%c", 254);
            break;
        }
        case 6: {
            marco_dado(x, y);

            gotoxy(x + 7, y + 2); printf("%c", 254);
            gotoxy(x + 7, y + 4); printf("%c", 254);

            gotoxy(x + 7, y + 3); printf("%c", 254);
            gotoxy(x + 3, y + 3); printf("%c", 254);

            gotoxy(x + 3, y + 2); printf("%c", 254);
            gotoxy(x + 3, y + 4); printf("%c", 254);
            break;
        }

        }
        x += 11;

    }
    cout << endl;
}