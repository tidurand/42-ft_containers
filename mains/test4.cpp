/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test4.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:25:00 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/23 14:09:40 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vector.hpp"
#ifndef TYPE
#define TYPE ft
#endif

//vector modifiers 1 (insert + erase)

int main()
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
	TYPE::vector<int>::iterator it2 = v.begin();
	it2 = it2 + 4;
	v.erase(it, it2);
	it = it + 4;
	std::cout << v.front() << std::endl;
	std::cout << *(v.erase(it)) << std::endl;;
	std::cout << v.front() << std::endl;
	for (int i = 0; i < 15; i++)
		std::cout << v[i] << ",";
	std::cout << std::endl;
	v.insert(it, (size_t)4, 68);
	for (int i = 0; i < 20; i++)
		std::cout << v[i] << ",";
	std::cout << std::endl;
	std::cout << v.size() << std::endl;
	std::cout << v.capacity() << std::endl;
	TYPE::vector<int> v2((size_t)3, 400);
	v2.push_back(502);
	v.insert(v.begin(), v2.begin(), v2.end());
	for (int i = 0; i < 20; i++)
		std::cout << v[i] << ",";
	std::cout << std::endl;
	return 0;
}