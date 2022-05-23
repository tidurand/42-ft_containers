/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test8.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:40:30 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/23 18:08:43 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vector.hpp"
#ifndef TYPE
#define TYPE ft
#endif

//vector compares

int main()
{
	TYPE::vector<int> v((size_t) 5, 6);
	TYPE::vector<int> v2((size_t) 5, 4);
	TYPE::vector<int> v3((size_t) 4, 10);
	TYPE::vector<int> v4((size_t) 1, 1);
	TYPE::vector<int> v5((size_t) 5, 6);

	if (v == v2)
		std::cout << "equal" << std::endl;
	if (v < v2)
		std::cout << "small" << std::endl;
	if (v >= v2)
		std::cout << "big equal" << std::endl;
	if (v != v2)
		std::cout << "different" << std::endl;

	if (v == v5)
		std::cout << "equal" << std::endl;
	if (v < v5)
		std::cout << "small" << std::endl;
	if (v >= v5)
		std::cout << "big equal" << std::endl;
	if (v != v5)
		std::cout << "different" << std::endl;

	if (v2 == v4)
		std::cout << "equal" << std::endl;
	if (v2 < v4)
		std::cout << "small" << std::endl;
	if (v2 >= v4)
		std::cout << "big equal" << std::endl;
	if (v2 > v4)
		std::cout << "different" << std::endl;
}