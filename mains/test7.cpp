/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test7.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:04:19 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/24 17:15:46 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vector.hpp"
#ifndef TYPE
#define TYPE ft
#endif

//vector modifiers 2

int main()
{
	TYPE::vector<int> v;
	for (int i = 1; i <= 20; i++)
		v.push_back(i);
	TYPE::vector<int>::iterator it;
	it = v.begin();
	v.clear();
	std::cout << v.empty() << std::endl;
	std::cout << v.size() << ", " << v.capacity() << std::endl;
	for (int i = 1; i <= 20; i++)
		v.insert(it,i);
	for (int i = 0; i < 20; i++)
		std::cout << v[i] << ",";
	std::cout << std::endl;
	std::cout << v.size() << ", " << v.capacity() << std::endl;
	v.erase(it + 3);
	v.pop_back();
	for (int i = 0; i < 15; i++)
		std::cout << v[i] << ",";
	std::cout << std::endl;
	v.resize(5);
	for (int i = 0; i < 5; i++)
		std::cout << v[i] << ",";
	std::cout << std::endl;
	std::cout << v.size() << ", " << v.capacity() << std::endl;
	TYPE::vector<int> v2(20, 8);
	v.swap(v2);
	for (int i = 0; i < 5; i++)
		std::cout << v[i] << ",";
	std::cout << std::endl;
	std::cout << v.size() << ", " << v.capacity() << std::endl;
	return 0;
}