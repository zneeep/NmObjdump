/*
** EPITECH PROJECT, 2023
** B-PSU-400-LYN-4-1-nmobjdump-lucas.siraux
** File description:
** array_szie
*/

#include "../../include/my.h"

int array_size(symbol_t *symbols)
{
    int res = 0;
    while (symbols[res].name != NULL)
        res++;
    return res;
}
