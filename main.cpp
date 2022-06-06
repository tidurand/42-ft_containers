/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:52:56 by tidurand          #+#    #+#             */
/*   Updated: 2022/06/06 17:36:18 by tidurand         ###   ########.fr       */
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
  // ft::tree<int, std::string> tr;
  // tr.print();
  // tr.insert(5, "7");
  // tr.insert(4, "p");
  // tr.insert(3, "a");
  // tr.insert(2, "b");
  // tr.insert(9, "c");
  // tr.insert(1, "c");
  // tr.insert(6, "d");
  // tr.print();

  TYPE::map<int, std::string> m;
  std::cout << m.empty() << std::endl;
  m.insert(TYPE::pair<int, std::string>(4, "salut"));
  m.insert(TYPE::pair<int, std::string>(12, "abc"));
  m.insert(TYPE::pair<int, std::string>(1, "abc"));
  m.insert(TYPE::pair<int, std::string>(-1, "a"));
  m.insert(TYPE::pair<int, std::string>(5, "a"));
  m.insert(TYPE::pair<int, std::string>(20, "a"));

  std::cout << m.empty() << std::endl;
  // m.print();
  std::cout << m.at(12) << std::endl;

  TYPE::map<int, std::string>::iterator it;
  TYPE::map<int, std::string>::iterator ite;
  it = m.begin();
  ite = m.end();
//  it++;
//   it--;
  for ( ; it != ite; ++it)
   std::cout << it->data.first << std::endl;
  return 0;
}