/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:52:56 by tidurand          #+#    #+#             */
/*   Updated: 2022/08/08 09:28:40 by tidurand         ###   ########.fr       */
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
  TYPE::map<int, std::string> cpy;
  srand(time(0));
  // m.insert(TYPE::pair<int, std::string>(-5, "a"));
  for (int i = 1; i < 9; i++)
  {
    m.insert(TYPE::pair<int, std::string>(i, "a"));
  }
  m.insert(TYPE::pair<int, std::string>(4, "a"));
  // cpy = m;
  TYPE::map<int, std::string>::iterator it;
  it = m.begin();
  for (; it != m.end(); ++it)
    std::cout << it->first << std::endl;
  return 0;
}
