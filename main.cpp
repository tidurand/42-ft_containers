/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:52:56 by tidurand          #+#    #+#             */
/*   Updated: 2022/08/30 15:39:38 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "TYPE::vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include <utility>
#include <cstdlib>

// #ifndef TYPE
// #define TYPE ft
// #endif

// #include "containers_test/srcs/map/common.hpp"

// #define T1 char
// #define T2 foo<float>
// typedef TESTED_NAMESPACE::map<T1, T2> _map;
// typedef _map::const_iterator const_it;

// static unsigned int i = 0;

// void	ft_comp(const _map &mp, const const_it &it1, const const_it &it2)
// {
// 	bool res[2];

// 	std::cout << "\t-- [" << ++i << "] --" << std::endl;
// 	res[0] = mp.key_comp()(it1->first, it2->first);
// 	res[1] = mp.value_comp()(*it1, *it2);
// 	std::cout << "with [" << it1->first << " and " << it2->first << "]: ";
// 	std::cout << "key_comp: " << res[0] << " | " << "value_comp: " << res[1] << std::endl;
// }

// int		main(void)
// {
// 	_map	mp;

// 	mp['a'] = 2.3;
// 	mp['b'] = 1.4;
// 	mp['c'] = 0.3;
// 	mp['d'] = 4.2;
// 	printSize(mp);

// 	for (const_it it1 = mp.begin(); it1 != mp.end(); ++it1)
// 		for (const_it it2 = mp.begin(); it2 != mp.end(); ++it2)
// 			ft_comp(mp, it1, it2);

// 	printSize(mp);
// 	return (0);
// }

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

template <class Key, class T>
void	print(map<Key, T>& lst)
{
	for (typename map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << it->first << " => " << it->second << '\n';
}

int main ()
{
  map<char,int> foo,bar;
  foo['a']=100;
  foo['b']=200;
  bar['a']=10;
  bar['z']=1000;

  // foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
  if (foo==bar) std::cout << "foo and bar are equal\n";
  if (foo!=bar) std::cout << "foo and bar are not equal\n";
  if (foo< bar) std::cout << "foo is less than bar\n";
  if (foo> bar) std::cout << "foo is greater than bar\n";
  if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
  if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

  return 0;
}