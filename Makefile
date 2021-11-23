/* ************************************************************************** */
/* ************************************************************************** */
/* **                                                                      ** */
/* **     ███    ███  █████  ██   ██ ███████ ███████ ██ ██      ███████    ** */
/* **     ████  ████ ██   ██ ██  ██  ██      ██      ██ ██      ██         ** */
/* **     ██ ████ ██ ███████ █████   █████   █████   ██ ██      █████      ** */
/* **     ██  ██  ██ ██   ██ ██  ██  ██      ██      ██ ██      ██         ** */
/* **     ██      ██ ██   ██ ██   ██ ███████ ██      ██ ███████ ███████    ** */
/* **                                                                      ** */
/* ************************************************************************** */
/* ************************************************************************** */


CC := gcc
FLAGS := -Wall -Wextra -Werror
BUFF_SZ := -D BUFFER_SIZE=100

H_FILE := get_next_line.h
NAME := libgnl.a
SRC := get_next_line.c get_next_line_utils.c
OBJ := $(SRC:%.c=%.o)

.PHONY: all compile clean fclean re

all: $(NAME)

compile: all main.c
	$(CC) $(FLAGS) $(BUFF_SZ) -L. -lgnl

$(NAME): $(OBJ) $(H_FILE)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<

clean:
	@echo "Cleaning Object Files ...\n"
	@rm -f *.o

fclean: clean
	@echo "Cleaning $(NAME) file ...\n"
	@rm -f $(NAME)

re: fclean all
