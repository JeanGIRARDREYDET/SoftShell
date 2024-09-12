#------------MAKEFILE------------#
##	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(READLINE_LIB)


NAME = minishell

CC = cc

C_FLAGS 		= -g3 -Wall -Wextra -Werror
READLINE_LIB	= -lreadline

SRCS = 			main.c \
				builtins/cd.c \
				builtins/echo.c \
				builtins/env.c \
				builtins/export.c \
				builtins/pwd.c \
				builtins/unset.c \
				common/initialization.c \
				libft/ft_strdup.c \
				libft/ft_strlen.c \
				libft/ft_strnstr.c \


SRC_PATH		=	
BIN_PATH		=	
SOURCES			=	$(addprefix $(SRC_PATH)/, $(SRCS))
DESTS			= 	$(addprefix $(BIN_PATH)/, $(SRCS))
EXEC = main

OBJ = $(SRCS:%.c=%.o)

CMD_RM = rm -f

%.o: %.c
	$(CC) $(C_FLAGS) -c $< -o $@
	@echo  "$(GREEN) $@  created!$(DEFAULT)"

$(NAME): $(OBJ) 
	$(CC) $(C_FLAGS) $(OBJ) -o  ${NAME} $(READLINE_LIB)
	@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

all : $(NAME)

clean: 
	$(CMD_RM) $(OBJ) 
	@echo -e "$(YELLOW)object files deleted!$(DEFAULT)"

fclean : clean
	$(CMD_RM) $(NAME)
	@echo -e "$(RED)all deleted!$(DEFAULT)"

re : fclean all

.PHONY : clean fcleam re


#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m