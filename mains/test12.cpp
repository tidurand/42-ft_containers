/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test12.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:37:22 by tidurand          #+#    #+#             */
/*   Updated: 2022/06/10 13:37:58 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../map.hpp"
#ifndef TYPE
#define TYPE ft
#endif

//map reverse iterators

int main ()
{

  TYPE::map<int, std::string> m;
  for (int i = 0; i < 20; i++)
  {
    m.insert(TYPE::pair<int, std::string>(i, "a"));
  }

  TYPE::map<int, std::string>::reverse_iterator it;
  TYPE::map<int, std::string>::reverse_iterator ite;
  it = m.rbegin();
  ite = m.rend();
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
	it++;
	it++;
	std::cout << ite->first << std::endl;
  
  return 0;
}