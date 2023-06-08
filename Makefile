##
## SBML_PARSER PROJECT, 2022
## makefile
## File description:
## makefile
##

SRC	=	src/main.c 										\
		src/copy_content_file.c							\
		src/remove.c									\
		src/lib/is_delim_separator.c					\
		src/lib/my_word_array_delim.c					\

CC ?= gcc

OBJ	=	$(SRC:.c=.o)

RM = rm -f

CPPFLAGS += -iquote./includes

CFLAGS += -Wall -Wextra -g3

NAME	=	SBMLparser

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CPPLAGS) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	 fclean all

.PHONY = all clean fclean re
