/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:52:56 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/24 15:52:14 by tidurand         ###   ########.fr       */
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
	int n = 1;
    int a[5] = {1, 2, 3, 4, 5};
	ft::pair<int, int> p1;
 	p1 = ft::make_pair(n, a[1]);
    std::cout << "The value of p1 is " << "(" << p1.first << ", " << p1.second << ")\n";
}
