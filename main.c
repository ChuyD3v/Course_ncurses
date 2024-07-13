#include <stdio.h>
#include <ncurses.h>
#include "Components/Window/Widget.h"

#ifndef VALUE
#define VALUE 10
#endif

void print_menu(WINDOW *win, int highlight, char *choices[], int n_choices);

int main() {
    initscr(); // Inicializa ncurses
    noecho(); // No muestra las teclas que el usuario presiona
    cbreak(); // Deshabilita el buffering en línea
    curs_set(0); // Oculta el cursor

    int start_y = (LINES - 10) / 2; // Centramos la ventana en la pantalla
    int start_x = (COLS - 40) / 2;

    WINDOW *win = createWin(10, 40, start_y, start_x); // Usa la función createWin
    mvwprintw(win, 1, 1, "VALUE is %d", VALUE); // Imprime el valor en la ventana

    char *choices[] = {
        "Option 1",
        "Option 2",
        "Option 3",
        "Exit"
    };
    int n_choices = sizeof(choices) / sizeof(char *);
    int highlight = 1;
    int choice = 0;
    int c;

    keypad(win, TRUE); // Permite el uso de teclas especiales como F1, F2, flechas, etc.

    print_menu(win, highlight, choices, n_choices);
    while(1) {
        c = wgetch(win);
        switch(c) {
            case KEY_UP:
                if(highlight == 1)
                    highlight = n_choices;
                else
                    --highlight;
                break;
            case KEY_DOWN:
                if(highlight == n_choices)
                    highlight = 1;
                else 
                    ++highlight;
                break;
            case 10: // Enter key
                choice = highlight;
                break;
        }
        print_menu(win, highlight, choices, n_choices);
        if(choice == n_choices) // Si el usuario selecciona "Exit", salir del bucle
            break;
    }
    
    mvwprintw(win, 8, 1, "You chose option %d", choice);
    wrefresh(win);
    getch(); // Espera una entrada del usuario
    endwin(); // Finaliza ncurses

    return 0;
}

void print_menu(WINDOW *win, int highlight, char *choices[], int n_choices) {
    int x = 2, y = 3;
    for(int i = 0; i < n_choices; ++i) {    
        if(highlight == i + 1) { // Resalta la opción seleccionada
            wattron(win, A_REVERSE); 
            mvwprintw(win, y, x, "%s", choices[i]);
            wattroff(win, A_REVERSE);
        }
        else
            mvwprintw(win, y, x, "%s", choices[i]);
        ++y;
    }
    wrefresh(win);
}
