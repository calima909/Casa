# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fchiocci <fchiocci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/25 16:44:45 by fchiocci          #+#    #+#              #
#    Updated: 2023/10/25 16:44:46 by fchiocci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = form
SRCS = main.cpp Bureaucrat.cpp Form.cpp
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