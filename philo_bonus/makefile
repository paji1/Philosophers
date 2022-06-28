# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 04:31:34 by tel-mouh          #+#    #+#              #
#    Updated: 2022/06/28 15:33:24 by tel-mouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL := /bin/bash # Use bash syntax


# #################Headers###########################

HEADERS = philo.h types.h utils.h 
HEADERS := $(addprefix include/, $(HEADERS))

# ################COMMANDS###########################
RM = rm -rf
CC = gcc -g
CFLAG = -pthread 

# ################SRCS_Objs##########################

SRC = main.c  parse.c init.c \
	print_state.c get_time.c behaviors.c check_die.c ft_usleep.c  \
	forks.c create_process.c send_kill.c
OBJ = $(addprefix obj/, $(SRC:.c=.o))

# ################SRCS_Objs_Utils####################

SRC_UTILS = ft_isdigit.c ft_putstr_fd.c ft_strcmp.c ft_itoa.c ft_atoi.c
OBJ_UTILS = $(addprefix obj/utils/, $(SRC_UTILS:.c=.o))

# ################COLOR##############################

COLOR='\033[0;32m'
NC='\033[0m'
RE= '\033[0;34m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'

lines=$(shell tput lines)
CODE_SAVE_CURSOR='\033[s'
CODE_RESTORE_CURSOR='\033[u'
CODE_CURSOR_IN_SCROLL_AREA="\033[1A"

# ###############executable##########################

NAME = ./philo_bonus
x  = -1
r := $(shell ls -l src | wc -l)
o := 1

# ###################################################

all : $(NAME)

$(NAME): $(OBJ) $(OBJ_UTILS)
	@printf  ${CODE_RESTORE_CURSOR}""
	@tput el
	@ printf ${GREEN}"\rMaking is done ✅\n"${NC}
	@ tput cvvis
	@ $(CC) $(CFLAG) $(OBJ) $(OBJ_UTILS) -o $(NAME)


obj/%.o : src/%.c $(HEADERS)
	@ mkdir -p obj
	@ mkdir -p obj/utils
	@ $(CC) $(CFLAG) -c $< -o $@
	@tput civis
	$(eval x=$(x)+1)
	@ printf $(notdir $@)"\n"
	@ printf  ${CODE_SAVE_CURSOR}""
	@ printf "\033[$(lines);0f"
	@ sleep 0.05
	@number=$x ; while [[ $$number -ge 0 ]] ; do \
        printf ${YELLOW}"🟩"${NC}  ;\
        ((number = number - 1)) ; \
    done
	@printf  ${CODE_RESTORE_CURSOR}""
	@printf  ${CODE_CURSOR_IN_SCROLL_AREA}""
	@printf  ${CODE_SAVE_CURSOR}""
	@printf ${RE}"🔷 Making the  --> "${NC} 
	@tput el

clean :
	@ $(RM) $(OBJ)
	@ $(RM) $(OBJ_UTILS)

fclean : clean
	@ $(RM) $(NAME)

re : fclean all