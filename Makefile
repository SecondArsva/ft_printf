# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davidga2 <davidga2@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/14 12:45:14 by davidga2          #+#    #+#              #
#    Updated: 2023/05/18 00:24:19 by davidga2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- VARIABLES ---

# Name of the final program.
NAME = libftprintf.a

# Source files
SRC = ft_printf.c \
	  ft_printf_utils.c

# Headers like you see. For more protection.
HEADERS = ft_printf.h

# This means that OBJS are the files of SRC but changing the ".c" for ".o".
# So when they are generated, they will be part of OBJS.
OBJS = $(SRC:%.c=%.o)

# C Compiler variable. Need a main to compile, but not with "-c", bcuz unlink.
CC = cc

# Compiler for the final program variable. Library compiler.
AR = ar

# C Compiler flags variable.
CFLAGS = -Wall -Wextra -Werror

# Compiler flags for the final program variable.
ARFLAGS = -crs

# Remove variable.
RM = rm -f

# For remove this shit.
DS = .DS_Store

# For remove the VIM weird files.
SWP = .*.swp

#---RULES---

# Main rule.
all: $(NAME)

# Rule that compiles the final programs if the ".o" exists.
$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $?

# This rule compile the fist dependence with an output named equals to objetive
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

# PHONY rule to remove all ".o".
clean:
	$(RM) $(OBJS)

# PHONY rule to remove the final program and all the object files.
fclean: clean
	$(RM) $(NAME)

#re-make re-instal fclean delete the final program, and all call the main rule.
re: fclean all

# Extra clean.
xclean:
	$(RM) $(DS) $(SWP)

# In fclean and re, we need to write the dependece on that site because isn't
# a terminal command. Because they are a rule.
# List of PHONY rules.
.PHONY: all clean fclean re xclean
