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

  foo['x']=100;
  foo['y']=200;

  bar['a']=11;
  bar['b']=22;
  bar['c']=33;


  map<char, int>::const_iterator tmp = foo.begin(); //tmp iterates through foo
  map<char, int>::const_iterator tmp2 = bar.begin(); //tmp2 iterates through bar

  foo.swap(bar); //tmp iterates through bar
				//tmp2 iterates through foo


  map<char, int>	other;

  other['1'] = 73;
  other['2'] = 173;
  other['3'] = 763;
  other['4'] = 73854;
  other['5'] = 74683;
  other['6'] = 753;

  map<char, int>::const_iterator tmp3 = other.begin(); // tmp3 iterates through other

  std::cout << "foo contains:\n";
  for (map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "bar contains:\n";
  for (map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

	while(tmp != bar.end())
	{
		std::cout << tmp->first << " => " << tmp->second << '\n';
		tmp++;
	}
	tmp--;

	while(tmp2 != foo.end())
	{
		std::cout << tmp2->first << " => " << tmp2->second << '\n';
		tmp2++;
	}
	tmp2--;

	other.swap(foo); //tmp2 iterates through other
					//tmp3 iterates throught foo
	print(other);
	print(foo);
	print(bar);
	while(tmp != bar.begin())
	{
		std::cout << tmp->first << " => " << tmp->second << '\n';
		tmp--;
	}
	std::cout << tmp->first << " => " << tmp->second << '\n';

	while(tmp2 != other.begin())
	{
		std::cout << tmp2->first << " => " << tmp2->second << '\n';
		tmp2--;
	}
	std::cout << tmp2->first << " => " << tmp2->second << '\n';

	while(tmp3 != foo.end())
	{
		std::cout << tmp3->first << " => " << tmp3->second << '\n';
		tmp3++;
	}
	tmp3--;

	bar.swap(foo); //tmp3 iterates through bar
				//tmp iterates through foo

	print(other);
	print(foo);
	print(bar);

	while(tmp != foo.end())
	{
		std::cout << tmp->first << " => " << tmp->second << '\n';
		tmp++;
	}

	while(tmp2 != other.end())
	{
		std::cout << tmp2->first << " => " << tmp2->second << '\n';
		tmp2++;
	}

	while(tmp3 != bar.begin())
	{
		std::cout << tmp3->first << " => " << tmp3->second << '\n';
		tmp3--;
	}
	std::cout << tmp3->first << " => " << tmp3->second << '\n';

  return 0;
}