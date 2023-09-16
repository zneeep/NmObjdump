/*
** EPITECH PROJECT, 2023
** B-PSU-400-LYN-4-1-nmobjdump-lucas.siraux
** File description:
** nm
*/

#include "../include/my.h"

void nm_32(void *map, int argc, char *file)
{
    symbol_t *symbols = search_symbols_sections_32(map);
    symbols = sort_symbols(symbols);
    print_nm_32(symbols, argc, file);
}

void nm_64(void *map, int argc, char *file)
{
    symbol_t *symbols = search_symbols_sections_64(map);
    symbols = sort_symbols(symbols);
    print_nm_64(symbols, argc, file);
}

void not_elf(char *file, void *map, struct stat stat_buf, int fd)
{
    printf("nm: %s: file format not recognized\n", file);
    munmap(map, stat_buf.st_size);
    close(fd);
    return;
}

int open_file(char *file)
{
    int fd = open(file, O_RDONLY);

    if (fd == -1) {
        printf("nm: \'%s\': No such file\n", file);
        return -1 ;
    }
    return fd;
}

int nm_command(char *file, int argc)
{
    void *map;
    struct stat stat_buf;
    Elf64_Ehdr *header;
    int fd = open_file(file);
    fstat(fd, &stat_buf);
    map = mmap(NULL, stat_buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    header = (Elf64_Ehdr *)(map);

    if (header->e_ident[EI_CLASS] == ELFCLASS32)
        nm_32(map, argc, file);
    else if (header->e_ident[EI_CLASS] == ELFCLASS64)
        nm_64(map, argc, file);
    else
        not_elf(file, map, stat_buf, fd);
    munmap(map, stat_buf.st_size);
    close(fd);
    return 0;
}
