/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:03:10 by tidurand          #+#    #+#             */
/*   Updated: 2022/08/15 14:56:35 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include <iostream>
# include "iterator_traits.hpp"
#include "red_black_tree.hpp"
#include "utils.hpp"
namespace ft {

template <class It>
class map_iterator
{
	public:
		typedef node<It>						node;
		typedef	It								iterator_type;
		typedef	std::ptrdiff_t					difference_type;
		typedef	It*								pointer;
		typedef	It&								reference;
		typedef	std::random_access_iterator_tag	iterator_category; 
		map_iterator() {_p = NULL;_last = NULL;};
		explicit map_iterator(node *it) {_p = it;_last = NULL;};
		template<class It2>
		map_iterator( const map_iterator<It2>& other ) {*this = other;};
		template<class It2>
		map_iterator& operator=(const map_iterator<It2>& other) {_p = other.base();_last = other._last; return (*this);};
		~map_iterator(){};
		node *base(){return _p;};
		const node *base() const {return _p;};
		reference operator*(){return _p->data;};
		pointer operator->(){return &_p->data;};
		map_iterator &operator++()
		{
			if (_last)
			{
				_p = _last;
				_last = NULL;
			}
			if (_p->is_leaf == true)
			{
				_p = _p->parent;
				_last = _p;
				return *this;
			}
			if (_p->right && _p->right->is_leaf == false)
			{
				_p = _p->right;
				while (_p->left->is_leaf == false)
					_p = _p->left;
				_last = _p;
				return *this;
			}
			_last = _p;
			while (42)
			{
				if (_p->parent == NULL) //=last
				{
					while (_p->right)
						_p = _p->right;
					_p->parent = _last;
					return *this;
				}
				if (_p->parent->left == _p)
				{
					_p = _p->parent;
					_last = _p;
					return *this;
				}
				_p = _p->parent;
			}
			return *this;
		};
		map_iterator operator++(int)
		{
			map_iterator tmp = *this;
			operator++();
			return tmp;
		}
		map_iterator& operator--()
		{
			if (_last)
			{
				_p = _last;
				_last = NULL;
			}
			if (_p->is_leaf == true)
			{
				_p = _p->parent;
				_last = _p;
				return *this;
			}
			if (_p->left && _p->left->is_leaf == false)
			{
				_p = _p->left;
				while (_p->right->is_leaf == false)
					_p = _p->right;
				_last = _p;
				return *this;
			}
			_last = _p;
			while (42)
			{
				if (_p->parent == NULL)
				{
					while (_p->left)
						_p = _p->left;
					_p->parent = _last;
					return *this;
				}
				if (_p->parent->right == _p)
				{
					_p = _p->parent;
					_last = _p;
					return *this;
				}
				_p = _p->parent;
			}
			return *this;
		};
		map_iterator operator--(int)
		{
			map_iterator tmp = *this;
			operator--();
			return tmp;
		}
		template<class It2>
   		bool operator==(const map_iterator<It2>& rhs) const { return _p == rhs._p; };
		template<class It2>
   		bool operator!=(const map_iterator<It2>& rhs) const { return base() != rhs.base(); };
		template<class It2>
   		bool operator<=(const map_iterator<It2>& rhs) const { return _p <= rhs._p; };
		template<class It2>
   		bool operator<(const map_iterator<It2>& rhs) const { return _p < rhs._p; };
		template<class It2>
   		bool operator>=(const map_iterator<It2>& rhs) const { return _p >= rhs._p; };
		template<class It2>
   		bool operator>(const map_iterator<It2>& rhs) const { return _p > rhs._p; };
	private:
		node *_last;
		node *_p;
};

}

#endif