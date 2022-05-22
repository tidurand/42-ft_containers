/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test5.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:33:14 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/22 16:37:46 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vector.hpp"
#ifndef TYPE
#define TYPE ft
#endif

//vector accessors

int main()
{
	TYPE::vector<int> v;
	for (int i = 0; i <= 20; i++)
	{
		v.push_back(i);
		std::cout << v.at(0) << ", ";
	}
	std::cout << std::endl;
	std::cout << v[10] << std::endl;
	std::cout << v.at(5) << std::endl;
	std::cout << v.front() << std::endl;
	std::cout << v.back() << std::endl;
	std::cout << *(v.data()) << std::endl;
	
	return 0;
}