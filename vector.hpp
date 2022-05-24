/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:57:17 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/24 17:20:46 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <iostream>
# include <algorithm>
# include <vector>
#include <limits>
#include <type_traits>
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "utils.hpp"

namespace ft {

template <class T, class Allocator = std::allocator<T> >
class vector
{
	public:
		typedef	T										value_type;
		typedef	Allocator								allocator_type;
		typedef std::size_t								size_type;
		typedef	std::ptrdiff_t							difference_type;
		typedef	value_type&								reference;
		typedef	const value_type&						const_reference;
		typedef	typename Allocator::pointer				pointer;
		typedef	typename Allocator::const_pointer		const_pointer;
		typedef	ft::iterator<T>							iterator;
		typedef	ft::iterator<const T>					const_iterator;
		typedef	ft::reverse_iterator<T>					reverse_iterator; //must be <iterator>
		typedef	ft::reverse_iterator<const T>			const_reverse_iterator;
		
		vector();
		explicit vector( const Allocator& alloc );
		explicit vector( typename ft::enable_if<std::is_integral<T>::value, T>::type count, const T& value = T(),
                 const Allocator& alloc = Allocator());
		template< class InputIt>
		vector( InputIt first, InputIt last, const Allocator& alloc = Allocator());
		vector( const vector& other );
		~vector();
		vector& operator=( const vector& other );
		void assign( typename ft::enable_if<std::is_integral<T>::value, T>::type count, const T& value );
		template< class InputIt>
		void assign( InputIt first, InputIt last);
		allocator_type get_allocator() const;
		reference at( size_type pos );
		const_reference at( size_type pos ) const;
		reference operator[]( size_type pos ) ;
		const_reference operator[]( size_type pos ) const;
		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;
		T* data();
		const T* data() const;
		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;
		bool empty() const;
		size_type size() const;
		size_type max_size() const;
		void reserve( size_type new_cap );
		size_type capacity() const;
		void clear();
		iterator insert( iterator pos, const T& value );
		void insert( iterator pos, size_type count, const T& value );
		template< class InputIt >
		void insert( iterator pos, InputIt first, InputIt last );
		iterator erase( iterator pos );
		iterator erase( iterator first, iterator last );
		void push_back( const T& value );
		void pop_back();
		void resize( size_type count, T value = T() );
		void swap( vector& other );
		class OutOfRange : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{return ("vector :Out of range");}
		};
	
	private:
		size_type _size;
		size_type _capacity;
		T*	_array;
		allocator_type _alloc;

};

template< class T, class Alloc >
bool operator==( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
{
	return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
};
template< class T, class Alloc >
bool operator!=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
{
	return !ft::equal(lhs.begin(), lhs.end(), rhs.begin());
};
template< class T, class Alloc >
bool operator<( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
{
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
};
template< class T, class Alloc >
bool operator<=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
{
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
};
template< class T, class Alloc >
bool operator>( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
{
	return !ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
};
template< class T, class Alloc >
bool operator>=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
{
	return !ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
};

template< class T, class Alloc >
void swap( std::vector<T,Alloc>& lhs, std::vector<T,Alloc>& rhs ) 
{
	std::swap(lhs, rhs);
};

}



#include "vector.tpp"

#endif