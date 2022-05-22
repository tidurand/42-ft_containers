/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 17:43:40 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/22 18:03:30 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

namespace ft {
	
template <class T>
struct iterator_traits
{
	typedef	std::ptrdiff_t					difference_type;
	typedef	T								value_type;
	typedef	T*								pointer;
	typedef	T&								reference;
	typedef	std::random_access_iterator_tag	iterator_category;
		
};
	
	
	
}

#endif