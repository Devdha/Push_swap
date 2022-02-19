# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 13:38:28 by dha               #+#    #+#              #
#    Updated: 2022/02/19 13:36:15 by dha              ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf
NAME = push_swap
BONUS = checker

LIBFT_DIR = ./libft
LIBFT_NAME = ft
LIBFT = $(LIBFT_DIR)/lib$(LIBFT_NAME).a

SRCS = push_swap.c \
		push_swap_utils.c \
		input.c \
		pivot.c \
		sort.c \
		optimization.c \
		lst_utils.c \
		com_pass.c \
		com_swap.c \
		com_rotate.c \
		com_revrotate.c
INCS = push_swap.h \
		command.h
OBJ_DIR = ./obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

BONUS_SRCS = checker.c \
			input.c \
			lst_utils.c \
			com_pass.c \
			com_swap.c \
			com_rotate.c \
			com_revrotate.c
BONUS_INCS = checker.h \
			command.h
BONUS_OBJS = $(addprefix $(OBJ_DIR)/, $(BONUS_SRCS:.c=.o))

all : $(NAME)

bonus : $(BONUS)

$(NAME) : $(LIBFT) $(OBJS) $(INCS)
	@$(CC) $(CFLAGS) -I ./ $(OBJS) -L $(LIBFT_DIR) -l$(LIBFT_NAME) -o $@
	@printf "💡 Make $(NAME) Done\n"

$(BONUS) : $(LIBFT) $(BONUS_OBJS) $(BONUS_INCS)
	@$(CC) $(CFLAGS) -I ./ $(BONUS_OBJS) -L $(LIBFT_DIR) -l$(LIBFT_NAME) -o $@
	@printf "💡 Make $(BONUS) Done\n"
	
clean :
	@$(RM) $(OBJ_DIR)
	@echo "🗑 Remove $(NAME)'s OBJs Done"

fclean : clean
	@$(RM) $(NAME)
	@$(RM) $(BONUS)
	@echo "🗑 Remove $(NAME) Done"

wclean : fclean $(LIBFT_NAME)_fclean

re : fclean all

rr : wclean all

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -g

.PHONY : all clean fclean wclean re rr $(LIBFT_NAME)_clean $(LIBFT_NAME)_fclean

$(LIBFT) :
	@make -C $(LIBFT_DIR)

$(LIBFT_NAME)_clean :
	@make -C $(LIBFT_DIR) clean

$(LIBFT_NAME)_fclean :
	@make -C $(LIBFT_DIR) fclean