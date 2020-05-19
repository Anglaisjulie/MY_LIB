/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** open_file.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "lib.h"

char *save_file_in_buffer(int fd)
{
    char count[1];
    int size = 0;
    char stock[10000];
    char *file = NULL;

    while ((read(fd, count, 1)) != 0) {
        stock[size] = count[0];
        size++;
    }
    file = malloc(sizeof(char *) * (size + 1));
    if (file == NULL)
        return (NULL);
    for (int i = 0; i != size; i++)
        file[i] = stock[i];
    return (file);
}