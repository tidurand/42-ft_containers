/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:52:56 by tidurand          #+#    #+#             */
/*   Updated: 2022/06/07 15:25:32 by tidurand         ###   ########.fr       */
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
  m.insert(TYPE::pair<int, std::string>(4, "salut"));
  m.insert(TYPE::pair<int, std::string>(12, "abc"));
  m.insert(TYPE::pair<int, std::string>(1, "d"));
  m.insert(TYPE::pair<int, std::string>(-1, "a"));
  m.insert(TYPE::pair<int, std::string>(5, "b"));
  m.insert(TYPE::pair<int, std::string>(20, "c"));

  std::cout << m.empty() << std::endl;
  std::cout << m.at(12) << std::endl;

  TYPE::map<int, std::string>::iterator it;
  TYPE::map<int, std::string>::iterator ite;
  it = m.begin();
  ite = m.end();
  it++;
  it++;
  it++;
  std::cout << it->data.first << std::endl;
  --it;
  --it;
  std::cout << it->data.first << std::endl;
  return 0;
}