# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 14:51:59 by tidurand          #+#    #+#              #
#    Updated: 2022/05/18 17:56:37 by tidurand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.cpp

INCS = vector.hpp vector.tpp iterator.hpp

OBJS = $(SRCS:.cpp=.o)

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

NAME = containers

all: $(NAME)

$(NAME):	$(OBJS) $(INCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

test:	$(OBJS) $(INCS)
	@$(CXX) $(CXXFLAGS) $(SRCS) -D TYPE=ft -o ft
	@$(CXX) $(CXXFLAGS) $(SRCS) -D TYPE=std -o std
	@./ft > ft.txt
	@./std > std.txt
	diff ft.txt std.txt
	@rm ft.txt std.txt ft std

re:	fclean $(NAME)

.PHONY:  all clean fclean re