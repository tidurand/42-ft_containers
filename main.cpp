/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:52:56 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/31 14:19:20 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "vector.hpp"
#include "stack.hpp"
#include <stack>
#include <utility>
#ifndef TYPE
#define TYPE ft
#endif
#define T_SIZE_TYPE typename TYPE::vector<T>::size_type

template <typename T>
void	printSize(TYPE::vector<T> const &vct, bool print_content = true)
{
	const T_SIZE_TYPE size = vct.size();
	const T_SIZE_TYPE capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename TYPE::vector<T>::const_iterator it = vct.begin();
		typename TYPE::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

int main()
{	
	TYPE::vector<int> v;

	for (int i = 5; i <= 25; i++)
	{
		v.push_back(i);
	}
	TYPE::vector<int>::reverse_iterator it(v.begin());
	for (it = v.rbegin(); it < v.rend(); it++)
	{
		 std::cout << *it << ", ";
	}
	std::cout << std::endl;
	// std::cout << *(v.rbegin()) << std::endl;
	// it -= 3;
	// std::cout << *(it.base()) << ", ";
	it = it + 1;
	it + 1;
	// std::cout << *it << ", ";
	// it = it - 5;
	// std::cout << it[1] << ", ";
	// std::cout << std::endl;
	
	return 0;
}

