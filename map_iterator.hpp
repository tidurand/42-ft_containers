/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:03:10 by tidurand          #+#    #+#             */
/*   Updated: 2022/06/06 15:58:50 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include <iostream>
# include "iterator_traits.hpp"
#include "red_black_tree.hpp"
#include "utils.hpp"
namespace ft {

// template <class It>
// class map_iterator
// {
// 	public:
// 	typedef  node<It, It> node;
// 		typedef	It								iterator_type;
// 		typedef	std::ptrdiff_t					difference_type;
// 		typedef	It*								pointer;
// 		typedef	It&								reference;
// 		typedef	std::random_access_iterator_tag	iterator_category; 
// 		// typedef struct node {
// 		// 	struct node *left;
// 		// 	struct node *right;
// 		// 	struct node *parent;
// 		// 	int color;
// 		// 	It data;
// 		// } node;
// 		map_iterator() {_p = NULL;};
// 		explicit map_iterator(node *it) {_p = it;};
// 		template<class It2>
// 		map_iterator<It>( const map_iterator<It2>& other ) {*this = other;};
// 		template<class It2>
// 		map_iterator<It>& operator=(const map_iterator<It2>& other) {_p = other.base(); return (*this);};
// 		~map_iterator(){};
// 		node *base(){return _p;};
// 		node &operator*(){return *_p;};
// 		node *operator->(){return _p;};
// 		map_iterator& operator++()
// 		{
// 			return *this;
// 		};
// 	private:
// 		node *_p;
// };

template <class It>
class map_iterator
{
	public:
		typedef node<It>		node;
		typedef	It								iterator_type;
		typedef	std::ptrdiff_t					difference_type;
		typedef	It*								pointer;
		typedef	It&								reference;
		typedef	std::random_access_iterator_tag	iterator_category; 
		map_iterator() {_p = NULL;};
		explicit map_iterator(node *it) {_p = it;};
		template<class It2>
		map_iterator( const map_iterator<It2>& other ) {*this = other;};
		template<class It2>
		map_iterator& operator=(const map_iterator<It2>& other) {_p = other.base(); return (*this);};
		~map_iterator(){};
		node *base(){return _p;};
		node &operator*(){return *_p;};
		node *operator->(){return _p;};
		map_iterator& operator++()
		{
			if (_p->right && _p->right->is_leaf == false)
			{
				_p = _p->right;
				while (_p->left->is_leaf == false)
					_p = _p->left;
				return *this;
			}
			while (42)
			{
				if (_p->parent == NULL)
				{
					_p = NULL;
					return *this;
				}
				if (_p->parent->left == _p)
				{
					_p = _p->parent;
					return *this;
				}
			}
			return *this;
		};
	private:
		node *_p;
};

}

#endif