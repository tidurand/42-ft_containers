/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:52:56 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/31 11:16:11 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "vector.hpp"
#include "stack.hpp"
#include <stack>
#include <utility>
#ifndef TYPE
#define TYPE ft
#endif

int main()
{
	TYPE::vector<int> v;

	for (int i = 1; i <= 20; i++)
	{
		v.push_back(i);
	}
	TYPE::vector<int>::iterator it;
	for (it = v.begin(); it < v.end(); it++)
	{
		std::cout << *it << ", ";
	}
	std::cout << std::endl;
	it -= 3;
	std::cout << *it << ", ";
	it = it + 1;
	it + 1;
	std::cout << *it << ", ";
	it = it - 5;
	std::cout << it[2] << ", ";
	std::cout << std::endl;
	std::cout << res << std::endl;
	return 0;
}