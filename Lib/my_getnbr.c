/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** Display first number of a string
*/

#include "lib.h"

int my_getnbr(char const *str)
{
    int sign = 1;
    double result = 0;
    int index = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-')
            sign = sign * -1;
        if (str[i] >= '0' && str[i] <= '9') {
            index = i;
            break;
        }
    }
    for (int i = index; str[i] >= '0' && str[i] <= '9'; i++) {
        result = result * 10 + str[i] - 48;
    }
    if ((result*sign) > 2147483647 || (result*sign) < -2147483648)
        return (0);
    else {
        return (result*sign);
    }
}
