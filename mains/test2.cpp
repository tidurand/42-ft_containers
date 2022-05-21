/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:08:02 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/21 13:57:32 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vector.hpp"
#ifndef TYPE
#define TYPE ft
#endif

//vector reverse_iterators

int main()
{	
	TYPE::vector<int> v;

	for (int i = 5; i <= 25; i++)
	{
		v.push_back(i);
	}
	TYPE::vector<int>::reverse_iterator it;
	for (it = v.rbegin(); it < v.rend(); it++)
	{
		std::cout << *it << ", ";
	}
	std::cout << std::endl;
	std::cout << *(v.rbegin()) << std::endl;
	it -= 3;
	std::cout << *it << ", ";
	//it = it + 1;
	// it + 1;
	// std::cout << *it << ", ";
	// it = it - 5;
	// std::cout << *it << ", ";
	std::cout << std::endl;
	
	return 0;
}