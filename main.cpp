/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:52:56 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/18 19:02:30 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#ifndef TYPE
#define TYPE std
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
	for (int i = 0; i < 20; i++)
		std::cout << v[i] << ",";
	std::cout << std::endl;
	std::cout << v.size() << std::endl;
	std::cout << v.capacity() << std::endl;
	std::cout << *(v.data()) << std::endl;

	v.resize(25, 6);
	std::cout << v.size() << std::endl;
	std::cout << v.capacity() << std::endl;
	for (int i = 0; i < 25; i++)
		std::cout << v[i] << ",";
	std::cout << std::endl;
	std::cout << *(v.end()) << std::endl;
		
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}