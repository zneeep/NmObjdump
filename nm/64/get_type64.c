/*
** EPITECH PROJECT, 2023
** B-PSU-400-LYN-4-1-nmobjdump-lucas.siraux
** File description:
** symbols_type
*/

#include "../../include/my.h"

char get_type_64(Elf64_Sym sym, Elf64_Shdr *shdr,
const char *name, Elf64_Ehdr *header)
{
    char type;
    char *ptr = &type;
    type = (ELF64_ST_BIND(sym.st_info) == STB_GNU_UNIQUE) ? 'u' : 0;
    if (strncmp("wm4.", name, 4) == 0)
        return ('n');
    ft_check_64(sym, shdr, ptr);
    st_check_64(sym, shdr, ptr);
    tt_check_64(sym, shdr, header, ptr);
    if (ELF64_ST_BIND(sym.st_info) == STB_LOCAL && type != 0
    || ((type == 'W' || type == 'V') && sym.st_shndx == SHN_UNDEF))
        type += 32;
    return (type);
}
