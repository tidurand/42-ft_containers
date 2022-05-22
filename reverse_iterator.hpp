/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 09:46:46 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/20 09:59:13 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include <iostream>

namespace ft {

template <typename It>	
class reverse_iterator
{
	public:
		reverse_iterator() {_p = NULL;};
		reverse_iterator(It *it) {_p = it;};
		reverse_iterator( const reverse_iterator& other ) {_p = other._p;};
		reverse_iterator& operator=(const reverse_iterator& other) {_p = other._p; return *this;};
		~reverse_iterator(){};
		It *	base(){return _p;};
		It &operator*() const	
		{
			It	*tmp = _p;
			--tmp;
			return (*tmp);
		};
		It *operator->() const	{return --_p;};
		reverse_iterator& operator++()
		{
			--_p;
			return *this;
		};
		reverse_iterator operator++(int)
		{
			reverse_iterator temp = *this;
			--_p;
			return temp;
		};
		reverse_iterator& operator--()
		{
			++_p;
			return *this;
		};
		reverse_iterator operator--(int)
		{
			reverse_iterator temp = *this;
			++_p;
			return temp;
		};
		reverse_iterator operator+=(int n)
		{
			_p = _p - n;
			return *this;
		};
		reverse_iterator operator-=(int n)
		{
			_p = _p + n;
			return *this;
		};
		reverse_iterator operator+(int n)
		{
			return (reverse_iterator(base() - n));
		};
		reverse_iterator operator-(int n)
		{
			return (reverse_iterator(_p + n));
		};
		It &operator[](int n)
		{
			It	*tmp = _p - n;
			--tmp;
			return (*tmp);
		};
		bool operator==(const reverse_iterator& rhs) const { return _p == rhs._p; };
   		bool operator!=(const reverse_iterator& rhs) const { return _p != rhs._p; };
		bool operator>(const reverse_iterator& rhs) const { return _p < rhs._p; };
   		bool operator>=(const reverse_iterator& rhs) const { return _p <= rhs._p; };
		bool operator<(const reverse_iterator& rhs) const { return _p > rhs._p; };
   		bool operator<=(const reverse_iterator& rhs) const { return _p >= rhs._p; };
	private:
		It *_p;
};
}


#endif