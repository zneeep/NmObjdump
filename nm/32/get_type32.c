/*
** EPITECH PROJECT, 2023
** B-PSU-400-LYN-4-1-nmobjdump-lucas.siraux
** File description:
** symbols_type
*/

#include "../../include/my.h"

char get_type_32(Elf32_Sym sym, Elf32_Shdr *shdr,
const char *name, Elf32_Ehdr *header)
{
    char type;
    char *ptr = &type;
    type = (ELF32_ST_BIND(sym.st_info) == STB_GNU_UNIQUE) ? 'u' : 0;
    if (strncmp("wm4.", name, 4) == 0)
        return ('n');
    ft_check_32(sym, shdr, ptr);
    st_check_32(sym, shdr, ptr);
    tt_check_32(sym, shdr, header, ptr);
    if (ELF32_ST_BIND(sym.st_info) == STB_LOCAL && type != 0
    || ((type == 'W' || type == 'V') && sym.st_shndx == SHN_UNDEF))
        type += 32;
    return (type);
}
