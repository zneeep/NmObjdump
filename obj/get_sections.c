/*
** EPITECH PROJECT, 2023
** B-PSU-400-LYN-4-1-nmobjdump-lucas.siraux
** File description:
** print_sections
*/

#include "../include/my.h"

bool check_section(Elf64_Shdr shdr, char *section_name)
{
    if (strcmp(section_name, ".bss") == 0 ||
    strcmp(section_name, ".shstrtab") == 0 ||
    strcmp(section_name, ".symtab") == 0 ||
    strcmp(section_name, ".strtab") == 0 ||
    strcmp(section_name, "") == 0 ||
    strcmp(section_name, ".rela.text") == 0 ||
    strcmp(section_name, ".rela.debug_info") == 0 ||
    strcmp(section_name, ".rela.debug_aranges") == 0 ||
    strcmp(section_name, ".rela.debug_line") == 0 ||
    strcmp(section_name, ".rela.eh_frame") == 0 ||
    strcmp(section_name, ".tbss") == 0 ||
    strcmp(section_name, "__libc_freeres_ptrs") == 0)
        return false;
    if (shdr.sh_size == 0)
        return false;
    return true;
}

void get_sections(void *map)
{
    Elf64_Ehdr *header = (Elf64_Ehdr *)(map);
    Elf64_Shdr *shdr = (Elf64_Shdr *) (map + header->e_shoff);
    char *section_names = (char *) (map + shdr[header->e_shstrndx].sh_offset);
    char *buffer = map;

    for (int i = 0; i < header->e_shnum; i++) {
        if (check_section(shdr[i], section_names + shdr[i].sh_name)) {
            printf("Contents of section %s:\n",
            section_names + shdr[i].sh_name);
            print_section(shdr[i], buffer);
        }
    }
}
