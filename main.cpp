/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:52:56 by tidurand          #+#    #+#             */
/*   Updated: 2022/10/04 17:32:38 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"
#include "map.hpp"
#include <utility>
#include <cstdlib>

#ifndef TYPE
#define TYPE ft
#endif

int main()
{
	srand(time(NULL));
	
	/*--------------------------------VECTOR-------------------------------------*/
	
	TYPE::vector<int> v;

	if (v.empty())
		std::cout << "vector is empty"  << std::endl;
	else
		std::cout << "vector is not empty"  << std::endl;
		
	std::cout << "push 100 values between 0 and 99"  << std::endl;
	for (int i = 0; i < 100; i++)
	{
		v.push_back(rand() % 100);
	}

	if (v.empty())
		std::cout << "vector is empty"  << std::endl;
	else
		std::cout << "vector is not empty"  << std::endl;
		
	std::cout << "[0] : " << v[0] << std::endl;
	std::cout << "at 0 : " << v.at(0) << std::endl;
	std::cout << "FRONT : " << v.front() << std::endl;
	std::cout << "BACK : " << v.back() << std::endl;
	std::cout << "SIZE : " << v.size() << std::endl;
	std::cout << "CAPACITY : " << v.capacity() << std::endl;
	
	std::cout << "remove last value"  << std::endl;
	v.pop_back();
	
	std::cout << "BACK : " << v.back() << std::endl;
	std::cout << "SIZE : " << v.size() << std::endl;

	std::cout << "call copy constructor"  << std::endl;
	TYPE::vector<int> v2 = v;

	std::cout << "SIZE V2 : " << v2.size() << std::endl;

	if (v == v2)
		std::cout << "v and v2 are equals" << std::endl;
	else
		std::cout << "v and v2 are differents" << std::endl;

	std::cout << "insert value at begin"  << std::endl;
	v2.insert(v2.begin(), 1000);

	std::cout << "FRONT : " << v.front() << std::endl;

	if (v == v2)
		std::cout << "v and v2 are equals" << std::endl;
	else
		std::cout << "v and v2 are differents" << std::endl;

	std::cout << "call operator equal" << std::endl;
	v2 = v;

	if (v == v2)
		std::cout << "v and v2 are equals" << std::endl << std::endl;
	else
		std::cout << "v and v2 are differents" << std::endl << std::endl;

	/*---------------------------------STACK-------------------------------------*/

	TYPE::stack<int> s;

	if (s.empty())
		std::cout << "stack is empty"  << std::endl;
	else
		std::cout << "stack is not empty"  << std::endl;
		
	std::cout << "push 100 values between 0 and 99"  << std::endl;
	for (int i = 0; i < 100; i++)
	{
		s.push(rand() % 100);
	}

	if (s.empty())
		std::cout << "stack is empty"  << std::endl;
	else
		std::cout << "stack is not empty"  << std::endl;
		
	std::cout << "TOP : " << s.top() << std::endl;
	std::cout << "SIZE : " << s.size() << std::endl;
	
	std::cout << "remove top value"  << std::endl;
	s.pop();
	
	std::cout << "TOP : " << s.top() << std::endl;
	std::cout << "SIZE : " << s.size() << std::endl;

	std::cout << "call copy constructor"  << std::endl;
	TYPE::stack<int> s2 = s;

	std::cout << "TOP S2 : " << s2.top() << std::endl;
	std::cout << "SIZE S2 : " << s2.size() << std::endl;

	if (s == s2)
		std::cout << "s and s2 are equals" << std::endl;
	else
		std::cout << "s and s2 are differents" << std::endl;

	std::cout << "remove top value"  << std::endl;
	s2.pop();

	if (s == s2)
		std::cout << "s and s2 are equals" << std::endl;
	else
		std::cout << "s and s2 are differents" << std::endl;

	std::cout << "call operator equal" << std::endl;
	s2 = s;

	if (s == s2)
		std::cout << "s and s2 are equals" << std::endl << std::endl;
	else
		std::cout << "s and s2 are differents" << std::endl << std::endl;
	

	/*------------------------------------MAP--------------------------------------*/

	TYPE::map<int, std::string> m;

	if (m.empty())
		std::cout << "map is empty"  << std::endl;
	else
		std::cout << "map is not empty"  << std::endl;

	m[0] = "a";
	m[1] = "b";
	m[2] = "c";
	m[3] = "d";

	if (m.empty())
		std::cout << "map is empty"  << std::endl;
	else
		std::cout << "map is not empty"  << std::endl;

	for (TYPE::map<int, std::string>::iterator it = m.begin(); it != m.end(); ++it)
		std::cout << "KEY : " << it->first << " VALUE : " << it->second << std::endl;
	
}
