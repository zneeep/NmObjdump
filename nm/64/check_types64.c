/*
** EPITECH PROJECT, 2023
** B-PSU-400-LYN-4-1-nmobjdump-lucas.siraux
** File description:
** check_types
*/

#include "../../include/my.h"

void ft_check_64(const Elf64_Sym sym, const Elf64_Shdr *shdr, char *ptr)
{
    if (ELF64_ST_BIND(sym.st_info) == STB_WEAK) {
        if (ELF64_ST_TYPE(sym.st_info) == STT_OBJECT)
            *ptr = 'V';
        *ptr = 'W';
    }
}

void st_check_64(const Elf64_Sym sym, const Elf64_Shdr *shdr, char *ptr)
{
    if (sym.st_shndx == SHN_UNDEF)
        *ptr = ('U');
    if (sym.st_shndx == SHN_ABS)
        *ptr = ('A');
    if (sym.st_shndx == SHN_COMMON)
        *ptr = ('C');
}

void tt_check_64_bis(const Elf64_Sym sym, const Elf64_Shdr *shdr,
Elf64_Ehdr *header, char *ptr)
{

    if (shdr[sym.st_shndx].sh_flags == SHF_ALLOC ||
    shdr[sym.st_shndx].sh_flags == (SHF_MERGE | SHF_ALLOC))
        *ptr = ('R');
    if ((shdr[sym.st_shndx].sh_type == SHT_PROGBITS &&
    shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE)) ||
    shdr[sym.st_shndx].sh_type == SHT_DYNAMIC)
        *ptr = ('D');
    if ((shdr[sym.st_shndx].sh_type == SHT_PROGBITS &&
    shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_EXECINSTR)) ||
    shdr[sym.st_shndx].sh_type == SHT_INIT_ARRAY ||
    shdr[sym.st_shndx].sh_type == SHT_FINI_ARRAY)
        *ptr = ('T');
}

void tt_check_64_intermediate(const Elf64_Sym sym, const Elf64_Shdr *shdr,
Elf64_Ehdr *header, char *ptr)
{
    if (shdr[sym.st_shndx].sh_type == SHT_NOBITS &&
    shdr[sym.st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE)) {
        *ptr = ('B');
    } else if (shdr[sym.st_shndx].sh_type == SHT_PROGBITS)
        tt_check_64_bis(sym, shdr, header, ptr);
}

void tt_check_64(const Elf64_Sym sym, const Elf64_Shdr *shdr,
Elf64_Ehdr *header, char *ptr)
{
    if (sym.st_shndx != SHN_UNDEF && sym.st_shndx < header->e_shnum)
        tt_check_64_intermediate(sym, shdr, header, ptr);
}
