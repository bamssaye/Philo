# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 01:58:28 by bamssaye          #+#    #+#              #
#    Updated: 2024/07/31 20:04:46 by bamssaye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -r
OBJDIR = obj
CHECK = -fsanitize=address -g3 #-fsanitize=address
FUN = main.c philo_msg.c\
	philo_time.c philo_parssing.c\
	philo_controls.c philo_routin.c\
	philo.c\

OBG =  $(addprefix $(OBJDIR)/,  $(notdir $(FUN:.c=.o)))
RM = rm -rf

$(OBJDIR)/%.o:%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(CHECK) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBG)
	$(CC) $(CFLAGS) $(CHECK) $(OBG) -o $(NAME) 
clean : 
	$(RM) $(OBJDIR)

fclean : clean
	$(RM) $(NAME) 
	
re : fclean all

.PHONE : all clean fclean re
.SECONDRY : $(OBG)
