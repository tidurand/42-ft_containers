/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:43:07 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/31 09:47:58 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <map>
#include <iostream>

#include "utils.hpp"

namespace ft {
	
template <class Key, class T, class Compare = std::less<Key>,
class Allocator = std::allocator<ft::pair<const Key, T>>>
class map
{
	public:
		typedef	Key						key_type;
		typedef	T						mapped_type;
		typedef	ft::pair<const Key, T>	value_type;
		typedef	std::size_t				size_type;
		typedef	std::ptrdiff_t			difference_type;
		typedef	Compare					key_compare;
		typedef	Allocator				allocator_type;
		typedef	value_type&				reference;
		typedef	const value_type&		const_reference;
		typedef	typename Allocator::pointer				pointer;
		typedef	typename Allocator::const_pointer		const_pointer;
		typedef	std::iterator<T>							iterator;
		typedef	std::iterator<const T>					const_iterator;
		typedef	std::reverse_iterator<iterator>					reverse_iterator; //must be <iterator>
		typedef	std::reverse_iterator<const_iterator>			const_reverse_iterator;

		map();
		map(const Compare& comp = Compare(), const Allocator& alloc = Allocator());
		template <class Input It>
		map(InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator());
		map(const map& other);
		map& operator=(const map& other);
		~map();
		allocator_type get_allocator() const;
		T& at( const Key& key );
		const T& at( const Key& key ) const;
		T& operator[]( const Key& key );
		T& operator[]( Key&& key );
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
		void clear();
		std::pair<iterator, bool> insert( const value_type& value );
		iterator insert( iterator hint, const value_type& value );
		template< class InputIt >
		void insert( InputIt first, InputIt last );
		void erase( iterator pos );
		void erase( iterator first, iterator last );
		size_type erase( const Key& key );
		void swap( map& other );
		size_type count( const Key& key ) const;
		iterator find( const Key& key );
		const_iterator find( const Key& key ) const;
		std::pair<iterator,iterator> equal_range( const Key& key );
		std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const;
		iterator lower_bound( const Key& key );
		const_iterator lower_bound( const Key& key ) const;
		iterator upper_bound( const Key& key );
		const_iterator upper_bound( const Key& key ) const;
		key_compare key_comp() const;
		std::map::value_compare value_comp() const;

	private:
};

template< class Key, class T, class Compare, class Alloc >
bool operator==( const std::map<Key,T,Compare,Alloc>& lhs,
                 const std::map<Key,T,Compare,Alloc>& rhs );
				 
template< class Key, class T, class Compare, class Alloc >
bool operator!=( const std::map<Key,T,Compare,Alloc>& lhs,
                 const std::map<Key,T,Compare,Alloc>& rhs );

template< class Key, class T, class Compare, class Alloc >
bool operator<( const std::map<Key,T,Compare,Alloc>& lhs,
                const std::map<Key,T,Compare,Alloc>& rhs );

template< class Key, class T, class Compare, class Alloc >
bool operator<=( const std::map<Key,T,Compare,Alloc>& lhs,
                const std::map<Key,T,Compare,Alloc>& rhs );

template< class Key, class T, class Compare, class Alloc >
bool operator>( const std::map<Key,T,Compare,Alloc>& lhs,
                const std::map<Key,T,Compare,Alloc>& rhs );
				
template< class Key, class T, class Compare, class Alloc >
bool operator>=( const std::map<Key,T,Compare,Alloc>& lhs,
                 const std::map<Key,T,Compare,Alloc>& rhs );
				 				 
template< class Key, class T, class Compare, class Alloc >
void swap( std::map<Key,T,Compare,Alloc>& lhs,
           std::map<Key,T,Compare,Alloc>& rhs );
	
}

#endif