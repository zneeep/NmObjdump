/*
** EPITECH PROJECT, 2023
** B-PSU-400-LYN-4-1-nmobjdump-lucas.siraux
** File description:
** header
*/

#include "../include/my.h"

void exploit_header(Elf64_Shdr *shdr, Elf64_Ehdr *header, char *file, void *map)
{
    char *flags = malloc(sizeof(char) * 8);
    printf("\n%s:     file format elf64-x86-64\n", file);
    get_flags(&flags, header, shdr, map);
    unsigned int flags_value = get_flags_value(flags);
    printf("architecture: i386:x86-64, flags 0x%08x:\n", (flags_value));
    print_flags(flags);
}

void get_header(void *map, char *file)
{
    Elf64_Ehdr *header = (Elf64_Ehdr *)(map);
    Elf64_Shdr *shdr = (Elf64_Shdr *) (map + header->e_shoff);
    exploit_header(shdr, header, file, map);
    print_header_adress(header);
}
