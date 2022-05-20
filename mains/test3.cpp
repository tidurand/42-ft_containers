/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:08:02 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/20 14:39:06 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vector.hpp"
#ifndef TYPE
#define TYPE ft
#endif

//vector constructors + assign

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

	TYPE::vector<int> cpy(v);
	for (int i = 0; i < 20; i++)
		std::cout << cpy[i] << ",";
	std::cout << std::endl;

	TYPE::vector<int> it(v.begin(), v.end());
	for (int i = 0; i < 20; i++)
		std::cout << it[i] << ",";
	
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}