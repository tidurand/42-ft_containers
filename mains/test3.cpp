/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:08:02 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/21 10:43:56 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vector.hpp"
#ifndef TYPE
#define TYPE ft
#endif

//vector constructors + assign

int main()
{
	TYPE::vector<int> v;
	for (int i = 12; i <= 31; i++)
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
	std::cout << std::endl;
	
	TYPE::vector<int> v2(5);
	v2 = v;
	std::cout << v2.capacity() << std::endl;
	for (int i = 0; i < 20; i++)
		std::cout << v2[i] << ",";
	std::cout << std::endl;
	v2.assign((size_t)5, 8);
	std::cout << v2.size() << std::endl;
	std::cout << v2.capacity() << std::endl;
	for (int i = 0; i < 20; i++)
		std::cout << v2[i] << ",";
	std::cout << std::endl;
	std::vector<char> characters;
	const std::string extra(6, 'b');
    characters.assign(extra.begin(), extra.end());
	for (int i = 0; i < 6; i++)
		std::cout << characters[i] << ",";
	return 0;
}