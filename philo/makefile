# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 04:31:34 by tel-mouh          #+#    #+#              #
#    Updated: 2022/06/24 16:52:50 by tel-mouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ################OS#################################
OS = $(shell uname -s)

# ################COMMANDS###########################

RM = rm -rf
CC = gcc -g
CFLAG = -pthread -Wall -Werror -Wextra

# ################SRCS_Objs##########################

SRC = main.c linked_list.c ft_free.c parse.c init.c destroy_mutex.c\
	print_state.c get_time.c behaviors.c check_die.c ft_usleep.c threads.c \
	forks.c
OBJ = $(addprefix obj/, $(SRC:.c=.o))

# ################SRCS_Objs_Utils####################

SRC_UTILS = ft_isdigit.c ft_putstr_fd.c ft_strcmp.c ft_itoa.c ft_atoi.c
OBJ_UTILS = $(addprefix obj/utils/, $(SRC_UTILS:.c=.o))

# ################COLOR##############################

COLOR='\033[0;32m'
NC='\033[0m'
RE= '\033[0;34m'
RED='\033[0;31m'
YELLOW='\033[0;33m'

# ###############executable##########################

NAME = ./philo

# ###################################################

all : $(NAME)

$(NAME): $(OBJ) $(OBJ_UTILS)
	@ $(CC) $(CFLAG) $(OBJ) $(OBJ_UTILS) -o $(NAME)

obj/%.o : src/%.c 
	@ mkdir -p obj
	@ $(CC) $(CFLAG) -c $< -o $@
	@ echo ${RE}"Making the"${NC}" $(notdir $@)"

obj/utils/%.o : src/utils/%.c 
	@ mkdir -p obj/utils
	@ $(CC) $(CFLAG) -c $< -o $@
	@ echo ${YELLOW}"Making the util" ${NC} " $(notdir $@)"

clean :
	@ $(RM) $(OBJ)
	@ $(RM) $(OBJ_UTILS)
	
fclean : clean
	@ $(RM) $(NAME)

re : fclean all