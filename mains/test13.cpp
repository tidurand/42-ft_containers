/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test12.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:37:22 by tidurand          #+#    #+#             */
/*   Updated: 2022/07/18 10:02:08 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../map.hpp"
#ifndef TYPE
#define TYPE ft
#endif

//map erase

int main ()
{

  TYPE::map<int, std::string> m;
  srand(time(0));
  for (int i = 1; i < 9; i++)
  {
    m.insert(TYPE::pair<int, std::string>(i, "a"));
  }

  TYPE::map<int, std::string>::iterator it;
  it = m.begin();
  TYPE::map<int, std::string>::iterator it2;
  it2 = m.begin();
  it2++;
  it2++;
  it2++;
  std::cout << it->first << std::endl;
  std::cout << it2->first << std::endl;
  m.erase(it, it2);
  std::cout << "--" << std::endl;
  TYPE::map<int, std::string>::iterator it4;
  it4 = m.begin();
  for (TYPE::map<int, std::string>::iterator ite = m.end(); it4 != ite; it4++)
  {
    std::cout << it4->first << std::endl;
  }
  return 0;
}