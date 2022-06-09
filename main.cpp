/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:52:56 by tidurand          #+#    #+#             */
/*   Updated: 2022/06/09 11:43:26 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "TYPE::vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include <stack>
#include <utility>
#ifndef TYPE
#define TYPE ft
#endif

int main ()
{

  TYPE::map<int, std::string> m;
  std::cout << m.empty() << std::endl;
  // m.insert(TYPE::pair<int, std::string>(1, "salut"));
  // m.insert(TYPE::pair<int, std::string>(2, "abc"));
  // m.insert(TYPE::pair<int, std::string>(3, "d"));
  // m.insert(TYPE::pair<int, std::string>(4, "a"));
  // m.insert(TYPE::pair<int, std::string>(5, "b"));
  // m.insert(TYPE::pair<int, std::string>(6, "c"));
  for (int i = 1; i <= 9; i++)
  {
    m.insert(TYPE::pair<int, std::string>(i, "a"));
  }

  std::cout << m.empty() << std::endl;
  std::cout << m.size() << std::endl;
  TYPE::map<int, std::string>::iterator it;
  TYPE::map<int, std::string>::iterator ite;
  it = m.begin();
  ite = m.end();
  for (; it != ite; ++it)
  {
    std::cout << it->data.first << std::endl;
  }
  m.print();
  
  return 0;
}