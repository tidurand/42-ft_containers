/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:52:56 by tidurand          #+#    #+#             */
/*   Updated: 2022/07/18 08:29:03 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "TYPE::vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include <stack>
#include <utility>
#include <cstdlib>
#ifndef TYPE
#define TYPE ft
#endif

int main ()
{

  TYPE::map<int, std::string> m;
  srand(time(0));
  for (int i = 1; i < 9; i++)
  {
    m.insert(TYPE::pair<int, std::string>(i, "a"));
  }

  TYPE::map<int, std::string>::iterator it;
  TYPE::map<int, std::string>::iterator ite;
  it = m.begin();
  ite = m.end();
  for (; it != ite; ++it)
  {
    std::cout << it->first << std::endl;
  }
  it = m.begin();
  --ite;
  std::cout << "--" << std::endl;
  for (; it != ite; --ite)
  {
    std::cout << ite->first << std::endl;
  }
  std::cout << "--" << std::endl;
  ite++;
	ite++;
	std::cout << ite->first << std::endl;
  return 0;
}