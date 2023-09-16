/*
** EPITECH PROJECT, 2023
** B-PSU-400-LYN-4-1-nmobjdump-lucas.siraux
** File description:
** adress
*/

#include "../include/my.h"

void print_header_adress(Elf64_Ehdr *header)
{
    if (header->e_entry != 0)
        printf("start address 0x%016lx\n\n", header->e_entry);
    else
        printf("start address 0x0000000000000000\n\n");
}
