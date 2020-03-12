# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 17:47:07 by abaisago          #+#    #+#              #
#    Updated: 2019/03/18 16:19:32 by abaisago         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= gcc
NAME 	= libft.a
CFLAGS 	= -Wall -Wextra -Werror -O3 -g
SRC_PATH = .
SRC_NAME = \
	  ft_isalnum.c        ft_atoi.c          ft_lstadd.c       ft_abs.c        \
      ft_isalpha.c        ft_atoi_base.c     ft_lstclr.c       ft_power.c      \
	  ft_isascii.c        ft_count_digits.c  ft_lstdel.c       ft_sqrt.c       \
      ft_isblank.c        ft_count_udigits.c ft_lstdelone.c    ft_sqrt_floor.c \
      ft_iscntrl.c        ft_getnbr_base.c   ft_lstiter.c                      \
      ft_isdigit.c        ft_itoa.c          *ft_lstmap.c                      \
      ft_isgraph.c        ft_itoa_base.c     *ft_lstnew.c                      \
      ft_islower.c        ft_llitoa.c                                          \
      ft_isprint.c        ft_llitoa_base.c                                     \
      ft_isspace.c        ft_llitosa_base.c                                    \
      ft_isupper.c        ft_lluitoa.c                                         \
      ft_iswhitespace.c   ft_lluitoa_base.c                                    \
      ft_isxdigit.c       ft_lluitosa_base.c                                   \
      ft_toupper.c                                                             \
      ft_tolower.c                                                             \
      \
      ft_bzero.c          ft_putchar.c       *ft_strdup.c                      \
      *ft_memalloc.c      ft_putchar_fd.c    *ft_strcapitalize.c               \
      *ft_memccpy.c       ft_putendl.c       *ft_strcat.c                      \
      *ft_memchr.c        ft_putendl_fd.c    *ft_strchr.c                      \
      ft_memcmp.c         ft_puterr.c        ft_strclen.c                      \
      *ft_memcpy.c        ft_putnbr.c        ft_strclr.c                       \
      ft_memdel.c         ft_putnbr_base.c   ft_strcmp.c                       \
      *ft_memmove.c       ft_putnbr_fd.c     *ft_strcpy.c                      \
      *ft_memset.c        ft_putstr.c        ft_strdel.c                       \
      ft_mem_skip.c       ft_putstr_fd.c     ft_striter.c                      \
                          ft_putunbr_base.c  ft_striteri.c                     \
                                             *ft_strjoin.c                     \
                                             *ft_strjoin_free.c                \
                                             ft_strlcat.c                      \
                                             ft_strlcpy.c                      \
                                             ft_strlen.c                       \
                                             *ft_strmap.c                      \
                                             *ft_strmapi.c                     \
                                             ft_strncmp.c                      \
                                             *ft_strncat.c                     \
                                             *ft_strncpy.c                     \
                                             *ft_strnew.c                      \
                                             *ft_strnstr.c                     \
                                             *ft_strrchr.c                     \
                                             **ft_strsplit.c                   \
                                             *ft_strstr.c                      \
                                             *ft_strsub.c                      \
                                             *ft_strtrim.c                     \
                                             ft_str_is_lowercase.c             \
                                             ft_str_is_uppercase.c             \
                                             ft_str_is_alpha.c                 \
                                             ft_str_is_numeric.c               \
                                             ft_str_is_printable.c             \
                                             ft_str_skip.c                     \
											 ft_utfecut.c                      \
											 ft_utfecut_index.c                \
											 ft_wchar_utfe.c                   \
											 ft_wchar_utfelen.c                \
											 ft_wstr_utfe.c                    \
											 ft_wstr_utfelen.c                 \
											 ft_wputchar.c                     \
											 ft_wputstr.c                      \
											 ft_wstrlen.c                      \
											 ft_make_printable.c               \
      \
	  \
	  get_next_line.c

SRC        = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH   = .
OBJ_NAME   = $(SRC_NAME:.c=.o)
OBJ        = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

.PHONY: $(NAME) all

all: $(NAME)

$(NAME): $(OBJ)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -fv $(OBJ)

fclean: clean
	@rm -fv $(NAME)
ifneq '$(OBJ_PATH)' '.'
	@rm -rv $(OBJ_PATH) 
endif

re: fclean all

pure: re clean

norme:
	norminette $(SRC) libft.h
