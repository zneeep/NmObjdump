/*
** EPITECH PROJECT, 2023
** B-PSU-400-LYN-4-1-nmobjdump-lucas.siraux
** File description:
** sort_symbols
*/

#include "../../include/my.h"

void switch_places(symbol_t *syms, int *idx)
{
    symbol_t tmp = syms[(*idx) + 1];
    syms[(*idx) + 1] = syms[(*idx)];
    syms[(*idx)] = tmp;
    (*idx) = 0;
}

symbol_t *sort_symbols_bis(int *idx, symbol_t *syms)
{
    char *name;
    char *name_next;

    if ((name_next = delete_undescores(syms[(*idx) + 1].name)) == NULL ||
    (name = delete_undescores(syms[*idx].name)) == NULL)
        return (NULL);
    if (sym_compare(name, name_next) == 1 ||
    (strcmp(name_next, name) == 0 && syms[(*idx) + 1].name[0] == '_'))
        switch_places(syms, idx);

    free(name);
    free(name_next);
    return syms;
}

symbol_t *sort_symbols(symbol_t *syms)
{
    int	idx = 0;

    while (idx < array_size(syms)) {
        if (idx + 1 < array_size(syms))
            syms = sort_symbols_bis(&idx, syms);
        idx += 1;
    }
    return (syms);
}
