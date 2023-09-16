/*
** EPITECH PROJECT, 2023
** B-PSU-400-LYN-4-1-nmobjdump-lucas.siraux
** File description:
** main
*/

#include "../include/my.h"

int main(int argc, char **argv)
{
    if (argc < 2)
        return (nm_command("a.out", argc));
    for (int i = 1; i < argc; i++)
        nm_command(argv[i], argc);
    return 0;
}
