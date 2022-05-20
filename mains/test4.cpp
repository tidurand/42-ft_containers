/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test4.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:25:00 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/20 19:06:37 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vector.hpp"
#ifndef TYPE
#define TYPE ft
#endif

//vector insert + erase

int main()
{
	try 
	{
		
	TYPE::vector<int> v;
	for (int i = 11; i <= 30; i++)
	{
		v.push_back(i);
	}
	for (int i = 0; i < 20; i++)
		std::cout << v[i] << ",";
	std::cout << std::endl;
	TYPE::vector<int>::iterator it = v.begin();
	it++;
	v.erase(it);
	it = it + 4;
	std::cout << v.front() << std::endl;
	std::cout << *(v.erase(it)) << std::endl;;
	std::cout << v.front() << std::endl;
	for (int i = 0; i < 19; i++)
		std::cout << v[i] << ",";
	std::cout << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}