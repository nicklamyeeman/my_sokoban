/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <curses.h>
#include "my.h"

int usage(int ret)
{
    my_putstr("USAGE\n");
    my_putstr("\t./my_sokoban");
    return (ret);
}

void free_all(char **ref, char **map, int *ori, int *pos)
{
    for (int i = 0; ref[i] != NULL; i++) {
        free(ref[i]);
        free(map[i]);
    }
    free(ref);
    free(map);
    free(ori);
    free(pos);
}

int prepare_game(char *file)
{
    int res = 0;
    char *pre_map = read_file(file);
    char **map = my_str_to_word_tab(pre_map, '\n');
    char **ref = NULL;
    int *ori = NULL;
    int *pos = malloc(sizeof(int) * 2);

    pos = find_position(map, pos);
    map[pos[0]][pos[1]] = ' ';
    ori = intcpy(pos, ori);
    ref = tabcpy(map, ref);
    res = my_sokoban(ref, map, ori, pos);
    free(pre_map);
    free_all(ref, map, ori, pos);
    return (res);
}

int main(int ac, char **av)
{
    int *sel = malloc(sizeof(int) * 2);
    char *menu_file = read_file("./config/menu");
    char **menu = my_str_to_word_tab(menu_file, '\n');

    if (ac == 2 && (my_strcmp("-h", av[1]) == 0 ||
                    my_strcmp("--help", av[1]) == 0))
        return (usage(0));
    if (ac != 1)
        return (usage(84));
    sel = init_select(sel);
    charge_menu(menu, sel);
    free(sel);
    return (0);
}