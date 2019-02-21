# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlantonn <mlantonn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/21 22:00:00 by mlantonn          #+#    #+#              #
#    Updated: 2019/02/21 23:49:15 by mlantonn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[31m
GRE = \033[32m
YEL = \033[33m
BLU = \033[34m
MAG = \033[35m
CYA = \033[36m
EOC = \033[37m

NAME = libftprintf.a
DIR_NAME = ft_printf

CFLAGS = -Wall -Wextra -Werror

INC = -I $(INC_DIR)
INC_DIR = includes

OBJS = $(SRCS:.c=.o)
OBJS_DIR = objs
OBJS_PRE = $(addprefix $(OBJS_DIR)/, $(OBJS))

SRCS_DIR = srcs
SRCS = ft_printf.c

.PHONY = all $(OBJS_DIR) $(NAME) del_objs del_exe clean fclean re exe

all: $(NAME) test

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@echo "gcc $(CFLAGS) $(INC) -c $^ -o $(CYA)$@$(EOC)"
	@gcc $(CFLAGS) $(INC) -c $^ -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS_DIR) $(OBJS_PRE)
	@echo "ar rc $(YEL)$(NAME)$(EOC) $(OBJS_PRE)"
	@ar rc $(NAME) $(OBJS_PRE)
	@echo "ranlib $(YEL)$(NAME)$(EOC)"
	@ranlib $(NAME)

del_objs:
	@echo "$(RED)rm -rf$(EOC) $(OBJS_DIR) from $(DIR_NAME)"
	@rm -rf $(OBJS_DIR)

del_exe:
	@echo "$(RED)rm -rf$(EOC) $(NAME)"
	@rm -rf $(NAME)

clean: del_objs

fclean: clean del_exe

re: fclean all

exe: del_objs del_exe all

### TO DELETE BEFORE CORRECTION ###
test:
	@echo "$(GRE)gcc main.c -L . -lftprintf$(EOC)"
	@gcc main.c -L. -lftprintf
