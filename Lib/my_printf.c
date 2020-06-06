/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** my_printf.c
*/

#include <stdarg.h>
#include "lib.h"

static int flags_b_p(va_list ap, int i, char *str)
{
    switch (str[i + 1])
    {
        case 'o':
            my_putnbr_base(va_arg(ap, unsigned int), "01234567");
            break;
        case 'x':
            my_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
            break;
        case 'X':
            my_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
            break;
        case 'b':
            my_putnbr_base(va_arg(ap, unsigned int), "01");
            break;
        default:
            return (0);
    }
    return (0);
}

static int flags_int(va_list ap, int i, char *str)
{
    switch (str[i + 1])
    {
        case 'd':
            my_put_nbr(va_arg(ap, int));
            break;
        case 'i':
            my_put_nbr(va_arg(ap, int));
            break;
        case 'u':
            my_put_unsigned_nbr(va_arg(ap, unsigned int));
            break;
        default:
            return (0);
    }
    return (0);
}

static int flags_char(va_list ap, int i, char *str)
{
    switch (str[i + 1])
    {
        case 'c':
            my_putchar(va_arg(ap, int));
            break;
        case 's':
            my_putstr(va_arg(ap, char *));
            break;
        case 'C':
            my_putchar(va_arg(ap, int) - 32);
            break;
        case '%':
            my_putchar('%');
            break;
        default:
            return (0);
    }
    return (0);
}

static void flags(va_list ap, char *str, int i)
{
    flags_b_p(ap, i, str);
    flags_int(ap, i, str);
    flags_char(ap, i, str);
}

int my_printf(char *str, ...)
{
    va_list ap;
    va_start(ap, str);
    int a = 0;

    if (str == 0)
        return (0);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%') {
            flags(ap, str, i);
            a += 2;
            i++;
        } else {
            my_putchar(str[a]);
            a++;
        }
    }
    va_end(ap);
    return (0);
}