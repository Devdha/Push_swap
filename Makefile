# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dha <dha@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 13:38:28 by dha               #+#    #+#              #
#    Updated: 2022/02/10 19:52:03 by dha              ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = gcc
#CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf
NAME = push_swap

LIBFT_DIR = ./libft
LIBFT_NAME = ft
LIBFT = $(LIBFT_DIR)/lib$(LIBFT_NAME).a

SRCS = push_swap.c input.c pass.c swap.c rotate.c revrotate.c
OBJ_DIR = ./obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) -I ./ $(OBJS) -L $(LIBFT_DIR) -l$(LIBFT_NAME) -o $@
	@printf "💡Make $(NAME) Done\n"
	
clean :
	@$(RM) $(OBJ_DIR)
	@echo "🗑 Remove $(NAME)'s OBJs Done"

fclean : clean
	@$(RM) $(NAME)
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