/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test11.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:31:19 by tidurand          #+#    #+#             */
/*   Updated: 2022/06/10 13:36:38 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../map.hpp"
#ifndef TYPE
#define TYPE ft
#endif

//map iterators

int main ()
{

  TYPE::map<int, std::string> m;
  for (int i = 0; i < 20; i++)
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
	it++;
	it++;
	std::cout << ite->first << std::endl;
  
  return 0;
}