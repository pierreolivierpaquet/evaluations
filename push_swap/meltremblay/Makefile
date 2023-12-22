# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 10:07:01 by meltremb          #+#    #+#              #
#    Updated: 2023/04/20 12:54:10 by meltremb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#

# Special variables
DEFAULT_GOAL: all
.DELETE_ON_ERROR: $(NAME)
.PHONY: all bonus clean fclean re

# Hide calls
export VERBOSE	=	TRUE
ifeq ($(VERBOSE),TRUE)
	HIDE =
else
	HIDE = @
endif


#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -rf

# Libraries
LDIR	=	reworked-libft/
LIBFT	=	libft.a
DBLDIR	=	dbl_push_swap/
DBL		=	dbl_extension_libft.a

# Dir and file names
NAME	=	push_swap
SRCDIR	=	src/
OBJDIR	=	bin/
SRCS	=	src/push_swap.c \
			src/make_pile.c \
			src/moves.c \
			src/utils.c \
			src/more_utils.c \

OBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: submodule $(NAME)

# Generates output file
$(NAME): $(OBJS) $(LDIR)$(LIBFT) $(DBLDIR)$(DBL)
	-@ $(HIDE)$(CC) $(CFLAGS) $(LDIR)$(LIBFT) $(DBLDIR)$(DBL) -o $@ $^

$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c
		-@ $(HIDE)mkdir -p $(OBJDIR)
		-@ $(HIDE)$(CC) $(CFLAGS) -c $< -o $@

# Generates libft
$(LDIR)$(LIBFT):
	-@ $(MAKE) -C $(LDIR)

# Generates DBL
$(DBLDIR)$(DBL):
	-@ $(MAKE) -C $(DBLDIR)

submodule:
	-@ git submodule update --init

# Removes objects
clean:
	-@ $(HIDE)$(RM) $(OBJS)
	-@ $(MAKE) -C $(LDIR) clean
	-@ $(MAKE) -C $(DBLDIR) clean

# Removes objects and executables
fclean: clean
	-@ $(RM) $(NAME)
	-@ $(RM) $(LDIR)/$(LIBFT)
	-@ $(RM) $(DBLDIR)$(DBL)
	
# Removes objects and executables and remakes
re: fclean all
