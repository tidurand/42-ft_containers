/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:52:56 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/18 13:46:37 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#define TYPE ft
int main()
{
	try 
	{
	TYPE::vector<int> v;

	for (int i = 1; i <= 20; i++)
	{
		v.push_back(i);
	}
	for (int i = 0; i < 20; i++)
		std::cout << v[i] << ",";
	std::cout << std::endl;
	std::cout << v.size() << std::endl;
	std::cout << v.capacity() << std::endl;
	std::cout << v.max_size() << std::endl;
	std::cout << *(v.data()) << std::endl;
	
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}