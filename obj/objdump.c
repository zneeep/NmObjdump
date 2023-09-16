/*
** EPITECH PROJECT, 2023
** B-PSU-400-LYN-4-1-nmobjdump-lucas.siraux
** File description:
** objdump
*/

#include "../include/my.h"

void objdump(char *file)
{
    int fd;
    void *map;
    struct stat stat_buf;

    fd = open(file, O_RDONLY);
    if (fd == -1) {
        printf("objdump: \'%s\': No such file\n", file);
        return;
    }
    fstat(fd, &stat_buf);
    map = mmap(NULL, stat_buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    get_header(map, file);
    get_sections(map);
    munmap(map, stat_buf.st_size);
    close(fd);
}

int main(int ac, char **av)
{
    objdump(av[1]);
}
