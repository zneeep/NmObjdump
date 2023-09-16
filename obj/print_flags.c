/*
** EPITECH PROJECT, 2023
** B-PSU-400-LYN-4-1-nmobjdump-lucas.siraux
** File description:
** printf_flags
*/

#include "../include/my.h"

bool check_flags(char *flags, int index)
{
    for (; index < 8; index++) {
        if (flags[index] == 1)
            return true;
    }
    return false;
}

int print_flag(char *flag, char *flags, int index)
{
    printf("%s", flag);
    if (check_flags(flags, index)) {
        printf(", ");
        return 1;
    } else {
        printf("\n");
        return 2;
    }
}

void print_flags(char *flags)
{
    char *flags_names[8] = {"NO_FLAGS", "HAS_RELOC", "EXEC_P",
    "HAS_DEBUG", "HAS_SYMS", "HAS_LOCALS", "DYNAMIC", "D_PAGED"};
    int stop = 0;
    for (int i = 0; i < 8; i++) {
        if (flags[i] == 1)
            stop = print_flag(flags_names[i], flags, i + 1);
        if (stop == 2)
            return;
    }
}
