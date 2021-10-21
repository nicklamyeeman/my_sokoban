/*
** EPITECH PROJECT, 2018
** menu step
** File description:
** sokoban
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <curses.h>
#include "my.h"

int *menu_nav(char **menu, int *sel, int k)
{
    if (k == KEY_UP) {
        if (menu[sel[0]][sel[1] + 2] != '0' ||
            menu[sel[0]][sel[1] + 3] != '0')
            sel[0] -= 1;
    }
    else if (k == KEY_DOWN) {
        if (menu[sel[0] + 2] != NULL)
            sel[0] += 1;
    }
    return (sel);
}

int *init_select(int *sel)
{
    sel[0] = 9;
    sel[1] = 27;
    return (sel);
}

void print_menu(char **menu)
{
    char *score_board = read_file("./config/player");
    char **score = my_str_to_word_tab(score_board, '\n');

    for (int i = 0; menu[i] != NULL; i++) {
        if (i > 8 && score[i - 9][3] == '1')
            attron(COLOR_PAIR(5));
        else if (i > 8)
            attron(COLOR_PAIR(1));
        else
            attron(COLOR_PAIR(2));
        printw("%s\n", menu[i]);
    }
}

void choose_game(int *sel)
{
    char *num = my_strdup("./maps/00");
    int res = 0;
    int k = sel[0] - 9;

    num[7] = (k / 10) + '0';
    num[8] = (k % 10) + '0';
    clear();
    res = prepare_game(num);
    if (res == 1)
        level_done(k);
}

void charge_menu(char **menu, int *sel)
{
    int k = 0;
    WINDOW *game;

    game = initscr();
    keypad(game, TRUE);
    sokolors();
    while (k != 27) {
        print_menu(menu);
        mvprintw(sel[0], sel[1], ">");
        k = getch();
        if (k == 32)
            choose_game(sel);
        sel = menu_nav(menu, sel, k);
        refresh();
        clear();   
    }
    endwin();
}