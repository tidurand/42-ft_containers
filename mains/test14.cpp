/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test14.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:02:04 by tidurand          #+#    #+#             */
/*   Updated: 2022/10/04 13:59:14 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../map.hpp"
#ifndef TYPE
#define TYPE ft
#endif

//map insert

int main ()
{

  TYPE::map<int, std::string> m;
  TYPE::map<int, std::string> m2;
  srand(time(0));
  for (int i = 1; i < 9; i++)
  {
    m.insert(TYPE::pair<int, std::string>(i, "a"));
  }
  m2.insert(m.begin(), m.end());
  
  TYPE::map<int, std::string>::iterator it;
  it = m.begin();

  TYPE::map<int, std::string>::iterator it2;
  it2 = m2.begin();

  for (; it != m.end() ; it++)
  {
    std::cout << it->first << std::endl;
  }
  for (; it2 != m2.end() ; it2++)
  {
    std::cout << it2->first << std::endl;
  }

  return 0;
}