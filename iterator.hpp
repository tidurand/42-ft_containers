/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:49:52 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/18 19:48:21 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP
#include <iostream>

namespace ft {

template <class It>
class iterator : public std::iterator<std::random_access_iterator_tag, It>
{
	public:
		iterator() {_p = NULL;};
		iterator(It *it) {_p = it;};
		iterator( const iterator& other ) {_p = other._p;};
		iterator& operator=(const iterator& other) {_p = other._p;};
		~iterator(){};
		It &operator*() const	{return *_p;};
		It *operator->() const	{return _p;};
		iterator& operator++()
		{
			++_p;
			return *this;
		};
		iterator operator++(int)
		{
			iterator temp = *this;
			++_p;
			return temp;
		};
		iterator& operator--()
		{
			--_p;
			return *this;
		};
		iterator operator--(int)
		{
			iterator temp = *this;
			--_p;
			return temp;
		};
		iterator operator+(int n)
		{
			_p = _p + n;
			return *this;
		};
		iterator operator-(int n)
		{
			_p = _p - n;
			return *this;
		};
		iterator operator[](int n)
		{
			_p = _p + n;
			return *this;
		};
		bool operator==(const iterator& rhs) const { return _p == rhs._p; };
   		bool operator!=(const iterator& rhs) const { return _p != rhs._p; };
		bool operator>(const iterator& rhs) const { return _p > rhs._p; };
   		bool operator>=(const iterator& rhs) const { return _p >= rhs._p; };
		bool operator<(const iterator& rhs) const { return _p < rhs._p; };
   		bool operator<=(const iterator& rhs) const { return _p <= rhs._p; };
	private:
		It* _p;
};

}

#endif