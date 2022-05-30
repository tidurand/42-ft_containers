/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:52:56 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/30 10:30:00 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "vector.hpp"
#include "stack.hpp"
#include <stack>
#include <utility>
#ifndef TYPE
#define TYPE ft
#endif

# define RED "\033[0;31m"
# define CRED std::cout << "\033[0;31m"
# define GREEN "\033[0;92m"
# define CGREEN std::cout << "\033[0;92m"
# define MAG "\033[0;95m"
# define CMAG std::cout << "\033[0;95m"
# define CYAN "\033[0;96m"
# define CCYAN std::cout << "\033[0;96m"
# define BLUE "\033[0;94m"
# define CBLUE std::cout << "\033[0;94m"
# define YELLOW "\033[0;93m"
# define CYELLOW std::cout << "\033[0;93m"
# define GREY "\033[0;90m"
# define CGREY std::cout << "\033[0;90m"
# define END "\033[0m"
# define ENDL "\033[0m" << std::endl

void print_vector(TYPE::vector<int> v)
{
	TYPE::vector<int>::iterator it1;
	TYPE::vector<int>::iterator it2;

	it1 = v.begin();
	it2 = v.end();

	CCYAN << "Vector=[";
	while (it1 < it2)
	{
		CYELLOW << *it1;
		CBLUE << ", ";
		it1++;
	}
	CCYAN << "]" << ENDL;
}

int main()
{
	CGREEN << "INITIALIZATION" << ENDL;
	CMAG << "operations..." << ENDL;
	TYPE::vector<int> fill(10, 42);
	TYPE::vector<int> tmp;
	TYPE::vector<int>::iterator it1;
	TYPE::vector<int>::iterator it2;
	CMAG << "print..." << ENDL;
	print_vector(fill);

	CGREEN << "ERASE" << ENDL;
	CMAG << "operations..." << ENDL;
	it1 = fill.begin();
	it1 += 5;
	it2 = fill.end();
	it2 -=2;

  std::cout << *it1 << " " << *it2 << std::endl;

	fill.erase(it1, it2);
	CMAG << "print..." << ENDL;
	print_vector(fill);

	CGREEN << "POP_BACK/PUSH_BACK" << ENDL;
	CMAG << "operations..." << ENDL;
	fill.pop_back();
	fill.push_back(13);
	fill.push_back(69);
	CMAG << "print..." << ENDL;
	print_vector(fill);

	CGREEN << "OPERATOR[]" << ENDL;
	CMAG << "operations..." << ENDL;
	fill[3] = -13;
	fill[5] = 123456789;
	CMAG << "print..." << ENDL;
	print_vector(fill);
	
	CGREEN << "SWAP" << ENDL;
	CMAG << "operations..." << ENDL;
	fill.swap(tmp);
	fill.swap(tmp);
	CMAG << "print..." << ENDL;
	print_vector(fill);

	CGREEN << "FRONT/BACK/AT" << ENDL;
	CMAG << "operations..." << ENDL;
	fill.front() = -42;
	fill.back() /= -2;
	fill.at(1) = 0;
	CMAG << "print..." << ENDL;
	print_vector(fill);

	CGREEN << "INSERT" << ENDL;
	CMAG << "operations..." << ENDL;
	it1 = fill.begin();
	it1 += 2;

	fill.insert(it1, 3, 987654321);
	CMAG << "print..." << ENDL;
	print_vector(fill);


	CGREEN << "RESIZE" << ENDL;
	CMAG << "operations..." << ENDL;
	fill.resize(20);
	fill.resize(13);
	CMAG << "print..." << ENDL;
	print_vector(fill);

	// try
	// {
	// 	CGREEN << "AT(error)" << ENDL;
	// 	CMAG << "operations..." << ENDL;
	// 	fill.at(-1) = -1;
	// }
	// catch (std::out_of_range& oor)
	// {
	// 	(void)oor;
	// 	std::cout << "OOR error caught\n";
	// }
	// try
	// {
	// 	fill.at(15) = -1;
	// }
	// catch (std::out_of_range& oor)
	// {
	// 	(void)oor;
	// 	std::cout << "OOR error caught\n";
	// }
	CMAG << "print..." << ENDL;
	print_vector(fill);

	return (0);
}
