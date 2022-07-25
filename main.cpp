/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:52:56 by tidurand          #+#    #+#             */
/*   Updated: 2022/07/25 18:49:07 by tidurand         ###   ########.fr       */
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
  for (int i = 1; i < 9; i++)
  {
    m.insert(TYPE::pair<int, std::string>(i, "a"));
  }
  TYPE::map<int, std::string>::iterator it;
  it = m.find(5);
  std::cout << it->first << std::endl;
  return 0;
}
