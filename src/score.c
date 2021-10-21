/*
** EPITECH PROJECT, 2018
** score managing
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

void level_done(int k)
{
    char *score = read_file("./config/player");
	FILE *file = fopen("./config/player", "w");

    score[k * 5 + 3] = '1';
    fprintf(file, "%s", score);
    fclose(file);
}