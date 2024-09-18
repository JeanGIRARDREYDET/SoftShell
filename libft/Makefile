# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jegirard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 10:14:38 by jegirard          #+#    #+#              #
#    Updated: 2023/11/17 06:00:41 by jegirard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

SOURCES = 	ft_isalnum.c ft_isprint.c ft_memcpy.c ft_putendl_fd.c ft_strchr.c\
			ft_strjoin.c ft_strmapi.c ft_strrchr.c ft_substr.c ft_atoi.c\
			ft_isalpha.c ft_itoa.c ft_memmove.c ft_putnbr_fd.c ft_strdup.c\
			ft_strlcat.c ft_tolower.c ft_bzero.c ft_isascii.c ft_memchr.c\
			ft_memset.c ft_putstr_fd.c ft_striteri.c ft_strlcpy.c ft_strncmp.c\
			ft_strtrim.c ft_toupper.c ft_calloc.c ft_isdigit.c ft_memcmp.c\
			ft_putchar_fd.c ft_split.c ft_strlen.c ft_strnstr.c

BONUS_SOURCES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c\
				ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
				ft_lstclear.c ft_lstiter.c ft_lstmap.c

CFLAGS = -Wall -Wextra -Werror

LIB = ar rc

CC = cc

EXEC=main
OBJ = $(SOURCES:.c=.o)
OBJ_BONUS = $(BONUS_SOURCES:.c=.o)

CMD_RM = rm -f

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

bonus : $(OBJ_BONUS) $(OBJ)
	$(LIB) $(NAME) $(OBJ_BONUS) $(OBJ)

clean: 	
	$(CMD_RM) $(OBJ_BONUS) $(OBJ)

fclean : clean
	$(CMD_RM) $(NAME) $(OBJ_BONUS) $(OBJ)

re: fclean all

.PHONY : clean fcleam re
