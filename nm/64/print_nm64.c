/*
** EPITECH PROJECT, 2023
** B-PSU-400-LYN-4-1-nmobjdump-lucas.siraux
** File description:
** print_nm
*/

#include "../../include/my.h"

void print_nm_64(symbol_t *symbols, int argc, char *file)
{
    char *str = malloc(sizeof(char) * 16);

    if (argc > 2)
        printf("\n%s:\n", file);

    for (int i = 0; i < array_size(symbols); i++) {
        if (symbols[i].type == 'a')
            continue;
        sprintf(str, "%lx", symbols[i].value);
        if (symbols[i].type == 'U' || symbols[i].type == 'w') {
            printf("                 ");
            printf("%c %s\n", symbols[i].type, symbols[i].name);
        } else
            print_fill(symbols[i], str);
    }
    free(str);
}
