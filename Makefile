##
## EPITECH PROJECT, 2023
## B-PSU-400-LYN-4-1-nmobjdump-lucas.siraux
## File description:
## Makefile
##


CC	= gcc

RM	= rm -f

NAMENM	= my_nm

NAMEOD	= my_objdump

CFLAGS	= -g -W -Wextra -I./include

SRCSNM	=	nm/main.c	\
	nm/nm.c	\
	nm/my/array_size.c	\
	nm/my/manage_symbols_names.c	\
	nm/my/print_fill.c	\
	nm/my/sort_symbols.c	\
	nm/32/check_types32.c	\
	nm/32/get_symbols32.c	\
	nm/32/get_type32.c	\
	nm/32/print_nm32.c	\
	nm/64/check_types64.c	\
	nm/64/get_symbols64.c	\
	nm/64/get_type64.c	\
	nm/64/print_nm64.c

SRCSOD	=	obj/objdump.c	\
	obj/header.c	\
	obj/adress.c	\
	obj/get_flags.c	\
	obj/get_sections.c	\
	obj/print_flags.c	\
	obj/print_sections.c

OBJSNM	= $(SRCSNM:.c=.o)

OBJSOD	= $(SRCSOD:.c=.o)

all:		$(NAMENM) $(NAMEOD)

nm:		$(NAMENM)

objdump:	$(NAMEOD)

$(NAMENM):	$(OBJSNM)
		$(CC) -o $(NAMENM) $(SRCSMY) $(OBJSNM) $(CFLAGS)

$(NAMEOD):	$(OBJSOD)
		$(CC) -o $(NAMEOD) $(SRCSMY) $(OBJSOD) $(CFLAGS)

clean:
		$(RM) $(OBJSNM) $(OBJSOD)

fclean:		clean
		$(RM) $(NAMENM) $(NAMEOD)

re: fclean all

.PHONY: all clean fclean re
