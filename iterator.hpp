/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:49:52 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/22 18:02:23 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP
#include <iostream>
# include "iterator_traits.hpp"

namespace ft {

template <class It>
class iterator : public std::iterator<std::random_access_iterator_tag, It>
{
	public:
	typedef	std::ptrdiff_t	difference_type;
	typedef It				value_type;
	typedef	It*				pointer;
	typedef	It&				reference;
	typedef	std::random_access_iterator_tag	iterator_category; 
	
		iterator() {_p = NULL;};
		iterator(It *it) {_p = it;};
		iterator( const iterator& other ) {_p = other._p;};
		iterator& operator=(const iterator& other) {_p = other._p; return (*this);};
		~iterator(){};
		It *	base(){return _p;};
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
		iterator operator+=(int n)
		{
			_p = _p + n;
			return *this;
		};
		iterator operator-=(int n)
		{
			_p = _p - n;
			return *this;
		};
		iterator operator+(int n)
		{
			return (iterator(_p + n));
		};
		iterator operator-(int n)
		{
			return (iterator(_p - n));
		};
		It &operator[](int n)
		{
			It	*tmp = _p + n;
			return (*tmp);
		};
		bool operator==(const iterator& rhs) const { return _p == rhs._p; };
   		bool operator!=(const iterator& rhs) const { return _p != rhs._p; };
		bool operator>(const iterator& rhs) const { return _p > rhs._p; };
   		bool operator>=(const iterator& rhs) const { return _p >= rhs._p; };
		bool operator<(const iterator& rhs) const { return _p < rhs._p; };
   		bool operator<=(const iterator& rhs) const { return _p <= rhs._p; };
	protected:
		It* _p;
};

template< class T >
iterator<T> operator+(iterator<T>& lhs, iterator<T>& rhs)
{
	return lhs.base() + rhs.base();
}



}

#endif