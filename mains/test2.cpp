/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:08:02 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/20 14:16:01 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vector.hpp"
#ifndef TYPE
#define TYPE ft
#endif
int main()
{
	try 
	{
		
	TYPE::vector<int> v;

	for (int i = 1; i <= 20; i++)
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
	// it = it + 1;
	// it + 1;
	// std::cout << *it << ", ";
	// it = it - 5;
	// std::cout << *it << ", ";
	// std::cout << std::endl;
	
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}