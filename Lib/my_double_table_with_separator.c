/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** my_double_table_with_separator.c
*/

#include "lib.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static int number_line(char *buffer, char separator)
{
    int line = 1;

    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == separator)
            line++;
    return (line);
}

static int number_of_char_per_line(char *buffer, char separator)
{
    int nb_character = 1;
    static int i = 0;

    for (; buffer[i] != separator && buffer[i] != '\0'; i++){
            nb_character++;
    }
    if (buffer[i] == '\0')
        i = -1;
    i++;
    return (nb_character);
}

static char **init_table(char *buffer, char **table, char separator)
{
    int n = 0;
    int i = 0;

    for (int a = 0; buffer[a] != '\0'; a++) {
        if (buffer[a] == separator) {
            table[n][i] = '\0';
            n++;
            i = 0;
        } else {
            table[n][i] = buffer[a];
            i++;
        }
    }
    return (table);
}

char **my_double_table_with_separator(char *buffer, char separator)
{
    int line = number_line(buffer, separator);
    int nb_character = 0;
    char **table = NULL;

    table = malloc(sizeof(char *) * (line + 1));
    if (table == NULL)
        return (NULL);
    table[line] = NULL;
    for (int i = 0; i != line; i++) {
        nb_character = number_of_char_per_line(buffer, separator);
        table[i] = malloc(sizeof(char) * (nb_character + 1));
        if (table[i] == NULL)
            return (NULL);
        table[i][nb_character] = '\0';
    }
    table = init_table(buffer, table, separator);
    free(buffer);
    return (table);
}
