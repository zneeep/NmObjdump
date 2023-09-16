/*
** EPITECH PROJECT, 2023
** B-PSU-400-LYN-4-1-nmobjdump-lucas.siraux
** File description:
** print_fill
*/

#include "../../include/my.h"

void print_fill(symbol_t symbol, char *str)
{
    for (size_t i = 0; i < (16 - strlen(str)); i++)
        printf("%d", 0);
    if (strcmp(symbol.name, "__abi_tag") == 0) {
        printf("%s r %s\n", str, symbol.name);
        return;
    }
    if (symbol.type == 0) {
        printf("%s ? %s\n", str, symbol.name);
        return;
    }
    printf("%s %c %s\n", str, symbol.type, symbol.name);
}
