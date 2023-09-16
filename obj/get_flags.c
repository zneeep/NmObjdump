/*
** EPITECH PROJECT, 2023
** B-PSU-400-LYN-4-1-nmobjdump-lucas.siraux
** File description:
** get_flags
*/

#include "../include/my.h"

unsigned int get_flags_value(char *flags)
{
    unsigned int result = 0;
    unsigned int values[] = {BFD_NO_FLAGS, HAS_RELOC, EXEC_P,
    HAS_DEBUG, HAS_SYMS, HAS_LOCALS, DYNAMIC, D_PAGED};
    for (int i = 0; i < 8; i++) {
        if (flags[i] == 1)
            result += values[i];
    }
    return result;
}

void get_debug_flags(char **flags, Elf64_Ehdr *header,
Elf64_Shdr *shdr, void *map)
{
    for (int i = 0; i < header->e_shnum; i++) {
        if (shdr[i].sh_type == SHT_PROGBITS && (shdr[i].sh_flags & SHF_ALLOC) &&
        (shdr[i].sh_flags & SHF_EXECINSTR) && (shdr[i].sh_flags & SHF_WRITE)) {
            (*flags)[3] = 1;
            (*flags)[0] = 0;
        }
    }
}

void get_flags(char **flags, Elf64_Ehdr *header, Elf64_Shdr *shdr, void *map)
{
    if (header->e_type == ET_EXEC) {
        (*flags)[2] = 1;
        (*flags)[7] = 1;
        (*flags)[0] = 0;
    } if (header->e_type == ET_DYN) {
        (*flags)[6] = 1;
        (*flags)[7] = 1;
        (*flags)[0] = 0;
    } if (header->e_type == ET_REL) {
        (*flags)[1] = 1;
        (*flags)[0] = 0;
    }

    for (int i = 0; i < header->e_shnum; i++) {
        if (shdr[i].sh_type == SHT_SYMTAB)
            (*flags)[4] = 1;
    }
    get_debug_flags(flags, header, shdr, map);
}
