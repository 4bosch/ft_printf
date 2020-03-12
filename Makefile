# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/13 11:54:38 by abaisago          #+#    #+#              #
#    Updated: 2019/03/19 15:16:20 by abaisago         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################################
#                     VARIABLES                      #
######################################################

NAME       := libftprintf.a

CC         := gcc
CFLAGS     := -Wall -Wextra -Werror
CPPFLAGS   := -Iinclude -Ilibft

#------------------------------------------------#
#                   LIBRARIES                    |
#------------------------------------------------#
LIB_PATH   := .
LIB_NAME   := ft
LIB_PREFIX := lib
LIB_DIR    := $(addprefix $(LIB_PREFIX),$(addsuffix /,$(LIB_NAME)))
LIB        := $(addprefix $(LIB_PATH)/$(LIB_DIR)lib,$(addsuffix .a,$(LIB_NAME)))

LDFLAGS    := $(addprefix -L,$(LIB_DIR))
LDLIBS     := $(addprefix -l,$(LIB_NAME))

#------------------------------------------------#
#                    SOURCES                     |
#------------------------------------------------#
INC_PATH   := include

SRC_PATH   := src
SRC_NAME   := ft_printf.c args.c floats.c integers.c output.c parsing.c        \
			  type_utils.c type_utils_2.c type_base.c type_char.c type_date.c  \
			  type_floats.c type_int.c type_wchar.c specifier.c

SRC        := $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH   := obj
OBJ_NAME   := $(SRC_NAME:.c=.o)
OBJ        := $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

#------------------------------------------------#
#                    RELEASE                     |
#------------------------------------------------#
REL_PATH   := .
REL        := $(REL_PATH)/$(NAME)
REL_OBJ    = $(addprefix $(REL_PATH)/,$(OBJ))
REL_CFLAGS := $(CFLAGS)

#------------------------------------------------#
#                     DEBUG                      |
#------------------------------------------------#
DBG_PATH   := debug
DBG  	   := $(DBG_PATH)/$(NAME)
DBG_OBJ	   = $(addprefix $(DBG_PATH)/,$(OBJ))
DBG_CFLAGS := $(CFLAGS) -g

NAME = $(REL)
######################################################
####                    RULES                     ####
######################################################
.PHONY: all clean fclean re debug libs

#------------------------------------------------#
#                    RELEASE                     |
#------------------------------------------------#

all: $(NAME) 

$(NAME): $(LIB) $(REL_OBJ)
	@ar rc $(NAME) libft/*.o $(REL_OBJ)
	@ranlib $(NAME)

$(REL_PATH)/$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(REL_PATH)/$(OBJ_PATH) 2>/dev/null || true
	$(CC) $(REL_CFLAGS) $(CPPFLAGS) -c $< -o $@

#------------------------------------------------#
#                     DEBUG                      |
#------------------------------------------------#
debug: $(LIB) $(DBG_OBJ)
	@ar rc $(DBG) $(DBG_OBJ) libft/*.o
	@ranlib $(DBG)

$(DBG_PATH)/$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(DBG_PATH)/$(OBJ_PATH) 2> /dev/null || true
	$(CC) $(DBG_CFLAGS) $(CPPFLAGS) -c $< -o $@

#------------------------------------------------#
#                   LIBRARIES                    |
#------------------------------------------------#
libs: $(LIB)

$(LIB_PATH)/$(LIB_DIR)%.a: FORCE
	@make -C $(dir $@)

#------------------------------------------------#
#                     ClEAN                      |
#------------------------------------------------#
lclean: $(LIB_DIR)

$(LIB_PATH)/$(LIB_PREFIX)%/: FORCE
	@make -C $@ fclean

clean: lclean
	@/bin/rm -fv $(REL_OBJ)

dclean:
	@/bin/rm -fv $(DBG_OBJ)

bclean: clean dclean

fclean: bclean 
	@/bin/rm -fv $(NAME)
	@/bin/rm -fv $(DBG)
ifneq '$(REL_PATH)' '.'
	@/bin/rm -rfv $(REL_PATH)
else
	@/bin/rm -rfv $(OBJ_PATH)
endif	
ifneq '$(DBG_PATH)' '.'
	@/bin/rm -rfv $(DBG_PATH)
else
	@/bin/rm -rfv $(OBJ_PATH)
endif	
	@/bin/rm -fv printf

#------------------------------------------------#
#                     OTHER                      |
#------------------------------------------------#
pure: all clean

FORCE:

norme:
	norminette $(SRC) $(INC_PATH)/*.h

re: fclean all

printf: $(NAME)
	$(CC) -Wall -Wextra main.c $(NAME) -Ilibft -o printf

printf_dbg: $(NAME)
	$(CC) -Wall -Wextra main.c $(DBG) -Ilibft -o printf
