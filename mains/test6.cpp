/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test6.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:39:02 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/22 18:32:14 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vector.hpp"
#ifndef TYPE
#define TYPE ft
#endif

//vector capacity

int main()
{
	TYPE::vector<int> v;
	std::cout << v.empty() << std::endl;
	for (int i = 0; i <= 20; i++)
	{
		v.push_back(i);
		std::cout << v.size() << ", " << v.capacity() << ", ";
	}
	std::cout << v.empty() << std::endl;
	v.reserve(1);
	std::cout << v.size() << ", " << v.capacity() << std::endl;
	v.insert(v.begin(), 3);
	std::cout << v.size() << ", " << v.capacity() << std::endl;
	v.reserve(80);
	std::cout << v.size() << ", " << v.capacity() << std::endl;
	v.reserve(85);
	std::cout << v.size() << ", " << v.capacity() << std::endl;
	
	return 0;
}