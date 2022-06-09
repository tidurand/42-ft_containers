/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:52:56 by tidurand          #+#    #+#             */
/*   Updated: 2022/06/09 14:51:34 by tidurand         ###   ########.fr       */
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
  for (int i = 0; i < 20; i++)
  {
    m.insert(TYPE::pair<int, std::string>(rand()%1000, "a"));
  }

  TYPE::map<int, std::string>::iterator it;
  TYPE::map<int, std::string>::iterator ite;
  it = m.begin();
  ite = m.end();
  for (; it != ite; ++it)
  {
    std::cout << it->data.first << std::endl;
  }
  it = m.begin();
  --ite;
  std::cout << "--" << std::endl;
  for (; it != ite; --ite)
  {
    std::cout << ite->data.first << std::endl;
  }
  m.print();
  
  return 0;
}