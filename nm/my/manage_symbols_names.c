/*
** EPITECH PROJECT, 2023
** B-PSU-400-LYN-4-1-nmobjdump-lucas.siraux
** File description:
** manage_symbols_names
*/

#include "../../include/my.h"

char *str_to_upcase(char *str)
{
    unsigned int idx;
    char *tmp;

    if ((tmp = malloc(strlen(str) + 1)) == NULL)
        return (NULL);
    idx = 0;

    while (str[idx] != '\0') {
        if (str[idx] >= 'a' && str[idx] <= 'z')
            tmp[idx] = str[idx] - 32;
        else
            tmp[idx] = str[idx];
        idx += 1;
    }
    tmp[idx] = '\0';
    return (tmp);
}

char *delete_undescores(char *str)
{
    unsigned int	idx;

    idx = 0;
    while (str[idx] != '\0' && str[idx] == '_')
        idx += 1;
    return (str_to_upcase(str + idx));
}

char symbol_cmp(char sym1, char sym2)
{
    if (sym1 > sym2)
        return (1);
    else if (sym1 < sym2)
        return (0);
    return 2;
}

char sym_compare(char *s1, char *s2)
{
    unsigned int	idx;
    char value;
    idx = 0;
    while (s1[idx] != '\0' && s2[idx] != '\0') {
        if (s1[idx] == '_')
            s1[idx] = ' ';
        if (s2[idx] == '_')
            s2[idx] = ' ';
        value = symbol_cmp(s1[idx], s2[idx]);
        if (value != 2)
            return value;
        idx += 1;
    }
    return (0);
}
