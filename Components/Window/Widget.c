#include <ncurses.h>
#include "Widget.h"

WINDOW *createWin(int height, int width, int start_y, int start_x) {
    WINDOW *win = newwin(height, width, start_y, start_x);
    box(win, 0, 0); // Dibuja un borde alrededor de la ventana
    wrefresh(win); // Refresca la ventana para mostrar la salida
    return win;
}
