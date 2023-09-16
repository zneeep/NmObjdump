/*
** EPITECH PROJECT, 2023
** B-PSU-400-LYN-4-1-nmobjdump-lucas.siraux
** File description:
** print_sections
*/

#include "../include/my.h"

void print_address(Elf64_Shdr shdr, char *buffer, int counter)
{
    printf(" ");
    int adress = shdr.sh_addr + (16 * counter);
    printf("%04x", adress);
}

void print_alpha_section(Elf64_Shdr shdr, char *buffer, int offset, int count)
{
    char tmp;
    for (int i = 0; i < count; i++) {
        tmp = (buffer + shdr.sh_offset)[offset];
        if (tmp < 32 || tmp > 127)
            tmp = '.';
        printf("%c", tmp);
        offset++;
    }
    for (int i = 0; count + i < 16; i++) {
        printf("  ");
        if ((count + i) % 4 == 0)
            printf(" ");
    }
}

void print_hexa_section(Elf64_Shdr shdr, char *buffer, int offset, int count)
{
    unsigned char tmp;
    for (int i = 0; i < count; i++) {
        if (i % 4 == 0)
            printf(" ");
        tmp = (buffer + shdr.sh_offset)[offset];
        printf("%02x", tmp);
        offset++;
    }
    for (int i = 0; count + i < 16; i++) {
        printf("  ");
        if ((count + i) % 4 == 0)
            printf(" ");
    }
    printf("  ");
}

void print_section(Elf64_Shdr shdr, char *buffer)
{
    int addr = shdr.sh_addr;
    char tmp;
    int counter = 0;
    int size = (int) (shdr.sh_size);
    int i = 0;
    int value;
    while (i < size) {
        print_address(shdr, buffer, (i / 16));
        if (size - i >= 16) {
            print_hexa_section(shdr, buffer, i, 16);
            print_alpha_section(shdr, buffer, i, 16);
        } else {
            print_hexa_section(shdr, buffer, i, (size - i) % 16);
            print_alpha_section(shdr, buffer, i, (size - i) % 16);
        }
        printf("\n");
        i += 16;
    }
}
