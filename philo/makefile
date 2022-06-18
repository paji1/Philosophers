# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 04:31:34 by tel-mouh          #+#    #+#              #
#    Updated: 2022/06/17 18:50:43 by tel-mouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ################OS#################################
OS = $(shell uname -s)
# ################COMMANDS###########################
RM = rm -rf
CC = gcc -g
# ################SRCS_Objs##########################

SRC = main.c linked_list.c ft_free.c parse.c init.c destroy_mutex.c
OBJ = $(addprefix obj/, $(SRC:.c=.o))
CFLAG = -pthread
# ################LIBRARY############################

LIBRARY = libft/library/libft.a

# ################COLOR##############################

COLOR='\033[0;32m'
NC='\033[0m'
RE= '\033[0;34m'
RED='\033[0;31m'

# ###############executable##########################

NAME = ./philo

# ###################################################

all : $(NAME)

$(NAME): $(LIBRARY) $(OBJ) 
	@ $(CC) $(CFLAG) $(OBJ) $(LIBRARY) -o $(NAME)

obj/%.o : src/%.c
	@ mkdir -p obj
	@ $(CC) $(CFLAG) -c $< -o $@
	@ echo ${RE}"Making the $(notdir $@)"${NC}


$(LIBRARY) :
	@ make -C libft

clean :
	@ make clean -C libft 
	@ $(RM) $(OBJ)
	
fclean : clean
	@ make fclean -C libft 
	@ $(RM) $(NAME)

re : fclean all
	# ./main