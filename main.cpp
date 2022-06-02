/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:52:56 by tidurand          #+#    #+#             */
/*   Updated: 2022/06/02 14:59:34 by tidurand         ###   ########.fr       */
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
  if (m.empty())
    std::cout << "Empty" << std::endl;
  m.insert ( TYPE::pair<int,std::string>(1,"salut") );
  if (m.empty())
    std::cout << "Empty" << std::endl;
  return 0;
}