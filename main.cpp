/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:52:56 by tidurand          #+#    #+#             */
/*   Updated: 2022/06/01 17:38:18 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "TYPE::vector.hpp"
#include "stack.hpp"
#include <stack>
#include <utility>
#ifndef TYPE
#define TYPE ft
#endif

template <class T>
void	print(TYPE::vector<TYPE::vector<T> >& lst)
{
	for (typename TYPE::vector<TYPE::vector<T> >::iterator it = lst.begin(); it != lst.end(); it++)
	{
		for (typename TYPE::vector<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
			std::cout << *it2 << ' ';
		std::cout << '\n';
	}
}

template <class T>
void	print(TYPE::vector<T>& lst)
{
	for (typename TYPE::vector<T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
}

int main ()
{
  TYPE::vector<int> foo (3,100);   // three ints with a value of 100
  TYPE::vector<int> bar (5,200);   // five ints with a value of 200

  foo.swap(bar);

  std::cout << "foo contains:";
  for (unsigned i=0; i<foo.size(); i++)
    std::cout << ' ' << foo[i];
  std::cout << '\n';

  std::cout << "bar contains:";
  for (unsigned i=0; i<bar.size(); i++)
    std::cout << ' ' << bar[i];
  std::cout << '\n';

{
	TYPE::vector<int> foo,bar;

	foo.push_back(100);
	foo.push_back(200);

	bar.push_back(11);
	bar.push_back(22);
	bar.push_back(33);


	TYPE::vector<int>::const_iterator tmp = foo.begin(); //tmp iterates through foo
	TYPE::vector<int>::const_iterator tmp2 = bar.begin(); //tmp2 iterates through bar

std::cout << bar.size() << foo.size() << bar.capacity() << foo.capacity() << std::endl; 
	swap(bar, foo); //tmp iterates through bar
					//tmp2 iterates through foo
    // foo.swap(bar);
    // bar.swap(foo);
std::cout << bar.size() << foo.size() << bar.capacity() << foo.capacity() << std::endl; 

	TYPE::vector<int>	other;

	other.push_back(73);
	other.push_back(173);
	other.push_back(763);
	other.push_back(73854);
	other.push_back(74683);
	other.push_back(753);

	TYPE::vector<int>::const_iterator tmp3 = other.begin(); // tmp3 iterates through other

	std::cout << "foo contains:\n";
	for (TYPE::vector<int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << *it << '\n';

	std::cout << "bar contains:\n";
	for (TYPE::vector<int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << *it << '\n';
  while(tmp != bar.end())
  {
    std::cout << *tmp << '\n';
    tmp++;
  }
  tmp--;

  while(tmp2 != foo.end())
  {
    std::cout << *tmp2 << '\n';
    tmp2++;
  }
  tmp2--;

  swap(other, foo); //tmp2 iterates through other
          //tmp3 iterates throught foo
  print(other);
  print(foo);
  print(bar);
  while(tmp != bar.begin())
  {
    std::cout << *tmp << '\n';
    tmp--;
  }
  std::cout << *tmp << '\n';

  while(tmp2 != other.begin())
  {
    std::cout << *tmp2 << '\n';
    tmp2--;
  }
    std::cout << *tmp2 << '\n';

  while(tmp3 != foo.end())
  {
    std::cout << *tmp3 << '\n';
    tmp3++;
  }
  tmp3--;

  swap(bar, foo);
  swap(foo, bar);
  swap(bar, foo); //tmp3 iterates through bar
        //tmp iterates through foo

  print(other);
  print(foo);
  print(bar);

  while(tmp != foo.end())
  {
    std::cout << *tmp << '\n';
    tmp++;
  }

  while(tmp2 != other.end())
  {
    std::cout << *tmp2 << '\n';
    tmp2++;
  }

  while(tmp3 != bar.begin())
  {
    std::cout << *tmp3 << '\n';
    tmp3--;
  }
    std::cout << *tmp3 << '\n';
}

  return 0;
}