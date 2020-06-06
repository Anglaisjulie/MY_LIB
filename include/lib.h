/*
** EPITECH PROJECT, 2019
** CPE_lemin_2019
** File description:
** lib.h
*/

#ifndef LIB_H_
#define LIB_H_

//PRINT
void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int n);
int my_put_unsigned_nbr(unsigned int nbr);
int my_putnbr_base(int nbr, char const *base);
int my_printf(char *str, ...);

//CONVERT
int my_getnbr(char const *str);
int	my_atoi(char *str);

//COMPARE
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);

//COPY
char *my_strcpy(char *dest, char const *src);

//LEN
int my_strlen(char const *str);

//FILES
char *save_file_in_buffer(int fd);

//TABLE
char **my_double_table_with_separator(char *buffer, char separator);

#endif /* !LIB_H_ */