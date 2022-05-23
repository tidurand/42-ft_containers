/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test8.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:13:07 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/23 14:15:22 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.hpp"
#ifndef TYPE
#define TYPE ft
#endif

//stack

int main()
{
	TYPE::stack<int> s;
	std::cout << s.size() << " " << s.empty() << std::endl;
    for (int i = 0; i < 7; i++)
        s.push(10);
    std::cout << s.size() << " " << s.empty() << std::endl;
	std::cout << s.top() << std::endl;
	s.pop();
	std::cout << s.top() << std::endl;
}