# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 14:51:59 by tidurand          #+#    #+#              #
#    Updated: 2022/05/20 18:28:02 by tidurand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.cpp

INCS = vector.hpp vector.tpp iterator.hpp reverse_iterator.hpp

OBJS = $(SRCS:.cpp=.o)

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

NAME = containers

MAX = 4

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

megatest:	$(OBJS) $(INCS)
	@for i in $(shell seq 1 $(MAX)); \
	do \
		echo $$i;\
		$(CXX) $(CXXFLAGS) mains/test$$i.cpp -D TYPE=ft -o ft;\
		$(CXX) $(CXXFLAGS) mains/test$$i.cpp -D TYPE=std -o std;\
		./ft > ft.txt;\
		./std > std.txt;\
		diff ft.txt std.txt;\
		rm ft.txt std.txt ft std;\
	done

megacat:	$(OBJS) $(INCS)
	@for i in $(shell seq 1 $(MAX)); \
	do \
		echo $$i;\
		$(CXX) $(CXXFLAGS) mains/test$$i.cpp -o ft;\
		./ft > ft.txt;\
		cat ft.txt;\
		rm ft.txt ft;\
	done
megarm:
	rm ft std ft.txt std.txt

re:	fclean $(NAME)

.PHONY:  all clean fclean re test