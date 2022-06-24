# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 04:31:34 by tel-mouh          #+#    #+#              #
#    Updated: 2022/06/24 22:33:22 by tel-mouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL := /bin/bash # Use bash syntax

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
lines=$(shell tput lines)
CODE_SAVE_CURSOR='\033[s'
CODE_RESTORE_CURSOR='\033[u'
CODE_CURSOR_IN_SCROLL_AREA="\033[1A"
PATH := $(PATH)
# ###############executable##########################

NAME = ./philo_bonus
x  = -1
r := $(shell ls -l src | wc -l)
o := 1

# ###################################################

all : $(NAME)

$(NAME): $(OBJ) $(OBJ_UTILS)
	@ $(CC) $(CFLAG) $(OBJ) $(OBJ_UTILS) -o $(NAME)


obj/%.o : src/%.c 
    # let lines=$(lines)
	$(eval x=$(x)+1)
	@ mkdir -p obj
	@ $(CC) $(CFLAG) -c $< -o $@
	@ printf ${RE}"Making the"${NC}" $(notdir $@)\n"
	printf  ${CODE_SAVE_CURSOR}""
	@ printf "\033[$(lines);0f"
	printf "["
	number=$x ; while [[ $$number -ge 0 ]] ; do \
        printf ${YELLOW}"#"${NC}  ;\
        ((number = number - 1)) ; \
    done
	printf  ${CODE_RESTORE_CURSOR}""
	

obj/utils/%.o : src/utils/%.c 
	@ mkdir -p obj/utils
	@ $(CC) $(CFLAG) -c $< -o $@
	@ printf ${YELLOW}"Making the"${NC}" $(notdir $@)\n"
	@ $(eval r=$(r)+1)
	@ printf "\033[$(lines);0f"
	number=$r ; while [[ $$number -ge 0 ]] ; do \
        printf ${YELLOW}"#"${NC}  ;\
        ((number = number - 1)) ; \
    done
	printf  ${CODE_RESTORE_CURSOR}""
	

clean :
	@ $(RM) $(OBJ)
	@ $(RM) $(OBJ_UTILS)

fclean : clean
	@ $(RM) $(NAME)

re : fclean all