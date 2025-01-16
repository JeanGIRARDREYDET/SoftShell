#------------MAKEFILE------------#
##	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(READLINE_LIB)


NAME = minishell

CC = cc

#C_FLAGS 		= -g3 -Wall -Wextra -Werror -fsanitize=address,leak,undefined  #-fsanitize-ignorelist=readline.supp
C_FLAGS 		= -g3 -Wall -Wextra -Werror 

#-Wundef
READLINE_LIB	= -lreadline 

SRCS = 			main.c \
				builtins/builtin_cd.c \
				builtins/cd.c \
				builtins/echo.c \
				builtins/env.c \
				builtins/exit.c \
				builtins/export.c \
				builtins/pwd.c \
				builtins/unset.c \
				check/mi_checkbuiltin.c \
				check/mi_checkpathaccess.c \
				io/mi_set_io_files.c \
				io/mi_heredoc.c \
				io/signal.c \
				io/mi_lastred.c \
				libft/ft_arrclose.c \
				libft/ft_atoi.c \
				libft/ft_bzero.c \
				libft/ft_calloc.c \
				libft/ft_chrrepeat.c \
				libft/ft_cnt_arg.c \
				libft/ft_findword.c \
				libft/ft_get_confpos.c \
				libft/ft_isalnum.c \
				libft/ft_isascii.c \
				libft/ft_isdigit.c \
				libft/ft_isalpha.c \
				libft/ft_isprint.c \
				libft/ft_itoa.c \
				libft/ft_lstadd_front.c \
				libft/ft_post_left_sep.c \
				libft/ft_posnospace.c \
				libft/ft_posnostring.c \
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
				libft/ft_subchar.c \
				libft/ft_left_sub_char.c \
				libft/ft_pos_left_chars.c \
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
				libft/ft_strtrimparam.c \
				libft/ft_setintarrayzero.c \
				common/mi_getenv.c \
				common/mi_logerror.c \
				common/mi_logerrorsys.c \
				common/mi_setenv.c \
				common/mi_sysinitialization.c \
				common/mi_envcreateupdate.c \
				parsing/mi_cmdsplitcmd.c \
				parsing/mi_cntarg.c \
				parsing/mi_unbordercote.c \
				parsing/mi_expand.c \
				parsing/mi_lexing.c \
				parsing/mi_cmd_parsse.c \
				parsing/mi_parseredirtocken.c \
				parsing/mi_posdif.c \
				parsing/mi_pospasscote.c \
				parsing/mi_cmditer.c \
				parsing/mi_redis.c \
				parsing/mi_expand_interface.c \
				parsing/mi_cmdherdoc.c \
				pipe/mi_closepipe.c \
				pipe/mi_createcmd.c \
				pipe/mi_exec.c \
				pipe/mi_execbuiltin.c \
				pipe/mi_execcmd.c \
				pipe/mi_execone.c \
				pipe/mi_exefind.c \
				pipe/mi_exepermis.c \
				common/mi_freecmd.c \
				common/mi_freesys.c \
				pipe/mi_waitingpipe.c \
				parsing/mi_syscmditer.c \

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

tart : 
	valgrind --leak-check=full -s --track-fds=yes --trace-children=yes --track-origins=yes --suppressions=readline.supp ./minishell

re : fclean all

.PHONY : clean fcleam re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m