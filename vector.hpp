/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:57:17 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/16 16:23:00 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <iostream>
# include <vector>

namespace ft {

template <class T, class Allocator = std::allocator<T>>
class vector
{
	typedef	T				value_type;
	typedef	Allocator		allocator_type;
	typedef	std::size_t		size_type;
	typedef	std::ptrdiff_t	difference_type;
	typedef	value_type&		reference;
	typedef	Allocator::pointer	pointer;
	typedef	Allocator::const_pointer	const_pointer;
	typedef	std::random_access_iterator	iterator;
	public:
		vector(/* args */);
		~vector();
};
}

#endif