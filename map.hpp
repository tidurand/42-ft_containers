/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:43:07 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/24 13:27:01 by tidurand         ###   ########.fr       */
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
		// typedef	ft::iterator<T>							iterator;
		// typedef	ft::iterator<const T>					const_iterator;
		// typedef	ft::reverse_iterator<T>					reverse_iterator; //must be <iterator>
		// typedef	ft::reverse_iterator<const T>			const_reverse_iterator;
};
	
}

#endif