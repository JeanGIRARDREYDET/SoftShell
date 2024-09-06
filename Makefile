#------------MAKEFILE------------#

NAME = minishell

CC = cc
CFLAGS =  -Wall -Werror -Wextra 
READLINE_LIB = -lreadline

SRC = main.c

OBJ = $(SRC:.c=.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compilation..."
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(READLINE_LIB)
	@echo "Minishell is ready !"

clean:
	@echo "CLean..."
	@$(RM) *.o
	@echo "Done !"

fclean: clean
	@echo "Remove all..."
	@$(RM) $(NAME)
	@echo "Done !"

re: fclean all

.PHONY: all re clean fclean
