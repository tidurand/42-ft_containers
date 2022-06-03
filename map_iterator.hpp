/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:03:10 by tidurand          #+#    #+#             */
/*   Updated: 2022/06/03 14:36:47 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include <iostream>
# include "iterator_traits.hpp"

namespace ft {

template <class It>
class map_iterator : public std::iterator<std::random_access_iterator_tag, It>
{
	public:
		typedef	It								iterator_type;
		typedef	std::ptrdiff_t					difference_type;
		typedef	It*								pointer;
		typedef	It&								reference;
		typedef	std::random_access_iterator_tag	iterator_category; 
		
		map_iterator() {_p = NULL;};
		explicit map_iterator(It *it) {_p = it;};
		template<class It2>
		map_iterator<It>( const map_iterator<It2>& other ) {*this = other;};
		template<class It2>
		map_iterator<It>& operator=(const map_iterator<It2>& other) {_p = other.base(); return (*this);};
		~map_iterator(){};
		It *base(){return _p;};
		It &operator*(){return *_p;};
		It *operator->(){return _p;};
		
	private:
		It *_p;
};

}

#endif