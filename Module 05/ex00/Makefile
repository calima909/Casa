# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fchiocci <fchiocci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/25 16:43:47 by fchiocci          #+#    #+#              #
#    Updated: 2023/10/25 16:43:48 by fchiocci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = burocratio
SRCS = main.cpp Bureaucrat.cpp
OBJS = $(SRCS:.cpp=.o)
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98
%.o: %.cpp
	$(CC) -c $(CFLAGS) $(SRCS)
all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all