/*
** EPITECH PROJECT, 2023
** B-PSU-400-LYN-4-1-nmobjdump-lucas.siraux
** File description:
** symbols
*/

#include "../../include/my.h"

symbol_t *get_symbols_64(Elf64_Ehdr* header, Elf64_Shdr *shdr,
Elf64_Shdr *symtab, void *map)
{
    int i = 0;
    Elf64_Shdr *symtab_str = &shdr[symtab->sh_link];
    Elf64_Sym *symtab_symbols = (Elf64_Sym *) (map + symtab->sh_offset);
    int symtab_size = symtab->sh_size / sizeof(Elf64_Sym);
    symbol_t *symbols = malloc(sizeof(symbol_t) * (symtab_size));
    char *str = (char *) (map + symtab_str->sh_offset);
    int index = 0;

    for (; i < symtab_size; i++) {
        if (strlen(str + symtab_symbols[i].st_name) != 0) {
            symbols[index].name = str + symtab_symbols[i].st_name;
            symbols[index].type = get_type_64(symtab_symbols[i], shdr,
            symbols[index].name, header);
            symbols[index].value = symtab_symbols[i].st_value;
            index++;
        }
    }
    return symbols;
}

symbol_t *search_symbols_sections_64(void *map)
{
    Elf64_Ehdr *header;
    Elf64_Shdr *shdr;
    Elf64_Shdr *symtab_hdr;

    header = (Elf64_Ehdr *) map;
    shdr = (Elf64_Shdr *) (map + header->e_shoff);

    for (int i = 0; i < header->e_shnum; i++) {
        if (shdr[i].sh_type == SHT_SYMTAB)
            symtab_hdr = &shdr[i];
    }

    if (!symtab_hdr)
        return NULL;
    return (get_symbols_64(header, shdr, symtab_hdr, map));
}
