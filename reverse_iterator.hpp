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
# include "iterator_traits.hpp"

namespace ft {

template <class It>	
class reverse_iterator : public std::iterator<std::random_access_iterator_tag, It>
{
	public:
	typedef	It													iterator_type;
	typedef	std::ptrdiff_t										difference_type;
	typedef typename ft::iterator_traits<It>::iterator_category	iterator_category;
	//typedef	typename ft::iterator_traits<It>::value_type		value_type;
	typedef	typename ft::iterator_traits<It>::pointer			pointer;
	typedef	typename ft::iterator_traits<It>::reference			reference;

		reverse_iterator() {/*_iter = NULL;*/};
		explicit reverse_iterator(It it) {_iter = it;};
		template<class It2>
		reverse_iterator<It>( const reverse_iterator<It2>& other ) {*this = other;};
		template<class It2>
		reverse_iterator<It>& operator=(const reverse_iterator<It2>& other) {_iter = other.base(); return (*this);};
		~reverse_iterator(){};
		It	base(){return _iter;};
		const It	base() const {return _iter;};
		reference operator*() const
		{
			It tmp = _iter;
			return *--tmp;
		};
		// const reference operator*() const
		// {
		// 	return _iter.operator*();
		// };
		pointer operator->()	{return &(operator*());};
		const pointer operator->() const	{return &(operator*());};
		reverse_iterator& operator++()
		{
			--_iter;
			return *this;
		};
		reverse_iterator operator++(int)
		{
			reverse_iterator temp = *this;
			--_iter;
			return temp;
		};
		reverse_iterator& operator--()
		{
			++_iter;
			return *this;
		};
		reverse_iterator operator--(int)
		{
			reverse_iterator temp = *this;
			++_iter;
			return temp;
		};
		reverse_iterator operator+=(int n)
		{
			_iter = _iter - n;
			return *this;
		};
		reverse_iterator operator-=(int n)
		{
			_iter = _iter + n;
			return *this;
		};
		reverse_iterator operator+(int n)
		{
			return (reverse_iterator(base() - n));
		};
		reverse_iterator operator-(int n)
		{
			return (reverse_iterator(_iter + n));
		};
		reference operator[](int n)
		{
			return (base()[-n-1]);;
		};
		template<class It2>
		bool operator==(const reverse_iterator<It2>& rhs) const { return base() == rhs.base(); };
		template<class It2>
   		bool operator!=(const reverse_iterator<It2>& rhs) const { return base() != rhs.base(); };
		template<class It2>
		bool operator>(const reverse_iterator<It2>& rhs) const { return base() < rhs.base(); };
		template<class It2>
   		bool operator>=(const reverse_iterator<It2>& rhs) const { return base() <= rhs.base(); };
		template<class It2>
		bool operator<(const reverse_iterator<It2>& rhs) const { return base() > rhs.base(); };
		template<class It2>
   		bool operator<=(const reverse_iterator<It2>& rhs) const { return base() >= rhs.base(); };
	private:
		It _iter;
};

template<typename T>
reverse_iterator<T> operator+(int n, reverse_iterator<T>& r)
{
     return (reverse_iterator<T>(r.base() - n));
}

template< class T >
reverse_iterator<T> operator+(reverse_iterator<T>& lhs, reverse_iterator<T>& rhs)
{
	return lhs.base() + rhs.base();
}

template< class T, class T2 >
typename reverse_iterator<T>::difference_type operator-(reverse_iterator<T>& lhs, reverse_iterator<T2>& rhs)
{
	return rhs.base() - lhs.base();
}

}


#endif