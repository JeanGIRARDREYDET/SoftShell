#------------MAKEFILE------------#
##	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(READLINE_LIB)


NAME = minishell

CC = cc

C_FLAGS 		= -g3 -Wall -Wextra -Werror 
#-Wundef
READLINE_LIB	= -lreadline

SRCS = 			main.c \
				builtins/cd.c \
				builtins/echo.c \
				builtins/env.c \
				builtins/export.c \
				builtins/pwd.c \
				builtins/unset.c \
				libft/ft_arrclose.c \
				libft/ft_atoi.c \
				libft/ft_bzero.c \
				libft/ft_calloc.c \
				libft/ft_cnt_arg.c \
				libft/ft_get_confpos.c \
				libft/ft_isalnum.c \
				libft/ft_isascii.c \
				libft/ft_isdigit.c \
				libft/ft_isalpha.c \
				libft/ft_isprint.c \
				libft/ft_itoa.c \
				libft/ft_lstadd_front.c \
				libft/ft_post_left_sep.c \
				libft/ft_pos_passspace.c \
				libft/ft_pos_passstring.c \
				libft/ft_strlcat.c \
				libft/ft_lstclear.c \
				libft/ft_putchar_fd.c \
				libft/ft_strlcpy.c \
				libft/ft_lstdelone.c \
				libft/ft_putendl_fd.c \
				libft/ft_strlen.c \
				libft/ft_lstiter.c \
				libft/ft_putnbr_fd.c \
				libft/ft_strmapi.c \
				libft/ft_lstlast.c \
				libft/ft_putstr_fd.c \
				libft/ft_strncmp.c \
				libft/ft_lstmap.c \
				libft/ft_split.c \
				libft/ft_strnstr.c \
				libft/ft_lstnew.c \
				libft/ft_strchr.c \
				libft/ft_strsubreplace.c \
				libft/ft_strrchr.c \
				libft/ft_lstsize.c \
				libft/ft_strchr_pos.c \
				libft/ft_strtrim.c \
				libft/ft_memchr.c \
				libft/ft_strcnt.c \
				libft/ft_substr.c \
				libft/ft_memcmp.c \
				libft/ft_tablen.c \
				libft/ft_left_sep.c \
				libft/ft_memcpy.c \
				libft/ft_strin.c \
				libft/ft_left_sub_char.c \
				libft/ft_pos_left_char.c \
				libft/ft_memmove.c \
				libft/ft_striteri.c \
				libft/ft_toupper.c \
				libft/ft_lstadd_back.c \
				libft/ft_memset.c \
				libft/ft_strjoin.c \
				libft/ft_strjoin3.c \
				libft/ft_strdup.c \
				libft/ft_sys_get_pwd.c \
				libft/ft_tolower.c \
				libft/ft_strtrim_param.c \
				common/mi_getenv.c \
				common/mi_logpipeerror.c \
				common/mi_setenv.c \
				common/mi_sysinitialization.c \
				common/mi_unsetenv.c \
				common/mi_utils.c \
				parsing/mi_expand.c \
				parsing/mi_lexing.c \
				parsing/mi_pipe_parsse.c \
				parsing/mi_pospasscote.c \
				parsing/mi_pipeiter.c \
				pipe/mi_create_pipe.c \
				pipe/mi_exec.c \
				pipe/mi_execone.c \



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