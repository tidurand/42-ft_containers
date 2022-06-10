/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 17:43:40 by tidurand          #+#    #+#             */
/*   Updated: 2022/06/10 09:20:12 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

namespace ft {
	
template <class Iter>
struct iterator_traits
{
	typedef	typename Iter::difference_type	difference_type;
	//typedef	typename Iter::value_type		value_type;
	typedef	typename Iter::pointer			pointer;
	typedef	typename Iter::reference		reference;
	typedef	typename Iter::iterator_category	iterator_category;
		
};
	
}

#endif