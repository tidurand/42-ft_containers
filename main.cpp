/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:52:56 by tidurand          #+#    #+#             */
/*   Updated: 2022/06/10 17:16:38 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "TYPE::vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include <stack>
#include <utility>
#include <cstdlib>
#ifndef TYPE
#define TYPE std
#endif

int main ()
{

  TYPE::map<int, std::string> m;
  srand(time(0));
  for (int i = 0; i < 20; i++)
  {
    m.insert(TYPE::pair<int, std::string>(i, "a"));
  }

  TYPE::map<int, std::string>::reverse_iterator it;
  TYPE::map<int, std::string>::reverse_iterator ite;
  it = m.rbegin();
  ite = m.rend();
  it++;
  for (; it != ite; ++it)
  {
    std::cout << it->first << std::endl;
  }
  it = m.rbegin();
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