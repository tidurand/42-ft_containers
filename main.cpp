/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:52:56 by tidurand          #+#    #+#             */
/*   Updated: 2022/08/28 12:03:16 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "TYPE::vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include <utility>
#include <cstdlib>
// #ifndef TYPE
// #define TYPE std
// #endif

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

int main()
{
	stack<float>								other_stack;
	vector<std::string>							lst;

	lst.push_back("salut");
	lst.push_back("tu vas bien?");
	lst.push_back("super");
	lst.push_back("et toi?");

	stack<std::string, vector<std::string> >	my_stack(lst);

	std::cout << std::boolalpha << other_stack.empty() << std::endl;
	other_stack.push(8.5); // 8.5;
	other_stack.push(42.4242); // 8.5; 42.4242;
	std::cout << other_stack.size() << '\n'; // 2
	other_stack.pop(); // 8.5;
	std::cout << other_stack.size() << '\n'; // 1
	other_stack.push(78541.987); // 8.5; 78541.987;
	std::cout << other_stack.size() << '\n'; // 2
	std::cout << other_stack.top() << '\n'; //78541.987
	std::cout << std::boolalpha << other_stack.empty() << std::endl;

	const std::string const_top = my_stack.top();

	std::cout << "const top: " << const_top << '\n';

	while (!my_stack.empty())
	{
		std::cout << my_stack.top() << '\n';
		my_stack.pop();
	}

	return (0);
}