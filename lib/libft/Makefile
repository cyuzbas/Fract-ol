# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cyuzbas <cyuzbas@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/11 12:51:21 by cyuzbas       #+#    #+#                  #
#    Updated: 2022/04/12 14:04:18 by cyuzbas       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME    	= 	libft.a
CC			= 	gcc
CFLAGS		= 	-Wall -Wextra -Werror

SRCS    	=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
				ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
				ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
				ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
				ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
				ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
				ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
				ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
				ft_tolower.c ft_toupper.c ft_atof.c ft_strcmp.c\
				ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
				ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
				ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJS = $(SRCS:.c=.o)

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}

all: ${NAME}

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f ${NAME}
	
re: fclean all

.PHONY: all, clean, fclean, re 