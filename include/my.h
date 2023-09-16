/*
** EPITECH PROJECT, 2023
** B-PSU-400-LYN-4-1-nmobjdump-lucas.siraux
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdio.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <sys/mman.h>
    #include <elf.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include <string.h>
    #include <stdbool.h>

/* No flags.  */
    #define BFD_NO_FLAGS    0x00

/* BFD contains relocation entries.  */
    #define HAS_RELOC       0x01

    /* BFD is directly executable.  */
    #define EXEC_P          0x02

    /* BFD has line number information (basically used for F_LNNO in a
       COFF header).  */
    #define HAS_LINENO      0x04

    /* BFD has debugging information.  */
    #define HAS_DEBUG       0x08

    /* BFD has symbols.  */
    #define HAS_SYMS        0x10

    /* BFD has local symbols (basically used for F_LSYMS in a COFF
       header).  */
    #define HAS_LOCALS      0x20

    /* BFD is a dynamic object.  */
    #define DYNAMIC         0x40

    /* Text section is write protected (if D_PAGED is not set, this is
       like an a.out NMAGIC file) (the linker sets this by default, but
       clears it for -r or -N).  */
    #define WP_TEXT         0x80

    /* BFD is dynamically paged (this is like an a.out ZMAGIC file) (the
       linker sets this by default, but clears it for -r or -n or -N).  */
    #define D_PAGED         0x100

typedef struct symbol_s {
        char *name;
    char type;
    Elf64_Addr value;
} symbol_t;

symbol_t *search_symbols_sections_32(void *map);
symbol_t *sort_symbols(symbol_t *symbols);
int array_size(symbol_t *symbols);
char get_type_32(Elf32_Sym sym, Elf32_Shdr *shdr,
    const char *name, Elf32_Ehdr *header);
void print_nm_32(symbol_t *symbols, int argc, char *file);
symbol_t *search_symbols_sections_64(void *map);
char get_type_64(Elf64_Sym sym, Elf64_Shdr *shdr,
    const char *name, Elf64_Ehdr *header);
void print_nm_64(symbol_t *symbols, int argc, char *file);
int array_size(symbol_t *symbols);
void get_header(void *map, char *file);
void get_sections(void *map);
void print_fill(symbol_t symbol, char *str);
int nm_command(char *file, int argc);
char *delete_undescores(char *str);
char sym_compare(char *s1, char *s2);
void print_header_adress(Elf64_Ehdr *header);
void get_flags(char **flags, Elf64_Ehdr *header, Elf64_Shdr *shdr, void *map);
unsigned int get_flags_value(char *flags);
void print_flags(char *flags);
void print_section(Elf64_Shdr shdr, char *buffer);
void ft_check_32(const Elf32_Sym sym, const Elf32_Shdr *shdr, char *ptr);
void ft_check_64(const Elf64_Sym sym, const Elf64_Shdr *shdr, char *ptr);
void st_check_32(const Elf32_Sym sym, const Elf32_Shdr *shdr, char *ptr);
void st_check_64(const Elf64_Sym sym, const Elf64_Shdr *shdr, char *ptr);
void tt_check_32(const Elf32_Sym sym, const Elf32_Shdr *shdr,
Elf32_Ehdr *header, char *ptr);
void tt_check_64(const Elf64_Sym sym, const Elf64_Shdr *shdr,
Elf64_Ehdr *header, char *ptr);



#endif /* !MY_H_ */
