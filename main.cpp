/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:52:56 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/17 16:54:16 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

int main()
{
	ft::vector<int> v(10);
	// std::vector<int> v2(10);
	std::cout << v.size() << std::endl;
	// std::cout << v2.size() << std::endl;
	v[0] = 50;
	std::cout << v[0] << std::endl;
	return 0;
}