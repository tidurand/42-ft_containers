/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:03:10 by tidurand          #+#    #+#             */
/*   Updated: 2022/10/02 11:33:20 by tidurand         ###   ########.fr       */
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
		typedef	std::bidirectional_iterator_tag	iterator_category; 
		map_iterator() {_p = NULL;_last = NULL;};
		explicit map_iterator(node *it):_last(NULL), _p(it){};
		template<class It2>
		map_iterator( const map_iterator<It2>& other ) {*this = other;};
		template<class It2>
		map_iterator& operator=(const map_iterator<It2>& other) {_p = other.base();_last = other._last; return (*this);};
		~map_iterator(){};
		node *base() {return _p;};
		const node *base() const {return _p;};
		reference operator*() const {return _p->data;};
		pointer operator->(){return &_p->data;};
		const pointer operator->() const {return &_p->data;};
		map_iterator &operator++()
		{
			if (_p->is_leaf == true)
			{
				_p = _p->parent;
				_last = _p;
				return *this;
			}
			if (_last)
			{
				_p = _last;
				_last = NULL;
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
			if (_p->is_leaf == true)
			{
				_p = _p->parent;
				_last = _p;
				return *this;
			}
			if (_last)
			{
				_p = _last;
				_last = NULL;
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
   		bool operator!=(const map_iterator<It2>& rhs) const { return _p != rhs._p; };
		template<class It2>
   		bool operator<=(const map_iterator<It2>& rhs) const { return _p <= rhs._p; };
		template<class It2>
   		bool operator<(const map_iterator<It2>& rhs) const { return _p < rhs._p; };
		template<class It2>
   		bool operator>=(const map_iterator<It2>& rhs) const { return _p >= rhs._p; };
		template<class It2>
   		bool operator>(const map_iterator<It2>& rhs) const { return _p > rhs._p; };
	public:
		node *_last;
		node *_p;
};

template <class It>
class const_map_iterator
{
	public:
		typedef node<It>						node;
		typedef	const It						iterator_type;
		typedef	std::ptrdiff_t					difference_type;
		typedef const It*						pointer;
		typedef	const It&						reference;
		typedef	std::bidirectional_iterator_tag	iterator_category; 
		const_map_iterator() {_p = NULL;_last = NULL;};
		explicit const_map_iterator(node *it):_last(NULL), _p(it){};
		const_map_iterator( const map_iterator<It> &it):_last(it._last), _p(it._p){};
		template<class It2>
		const_map_iterator( const const_map_iterator<It2>& other ) {*this = other;};
		template<class It2>
		const_map_iterator& operator=(const const_map_iterator<It2>& other) {_p = other.base();_last = other._last; return (*this);};
		~const_map_iterator(){};
		const node *base() const {return _p;};
		reference operator*() const {return _p->data;};
		const pointer operator->() const {return &_p->data;};
		const_map_iterator &operator++()
		{
			if (_p->is_leaf == true)
			{
				_p = _p->parent;
				_last = _p;
				return *this;
			}
			if (_last)
			{
				_p = _last;
				_last = NULL;
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
		const_map_iterator operator++(int)
		{
			const_map_iterator tmp = *this;
			operator++();
			return tmp;
		}
		const_map_iterator& operator--()
		{
			if (_p->is_leaf == true)
			{
				_p = _p->parent;
				_last = _p;
				return *this;
			}
			if (_last)
			{
				_p = _last;
				_last = NULL;
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
		const_map_iterator operator--(int)
		{
			const_map_iterator tmp = *this;
			operator--();
			return tmp;
		}
		template<class It2>
   		bool operator==(const const_map_iterator<It2>& rhs) const { return _p == rhs._p; };
		template<class It2>
   		bool operator!=(const const_map_iterator<It2>& rhs) const { return _p != rhs._p; };
		template<class It2>
   		bool operator<=(const const_map_iterator<It2>& rhs) const { return _p <= rhs._p; };
		template<class It2>
   		bool operator<(const const_map_iterator<It2>& rhs) const { return _p < rhs._p; };
		template<class It2>
   		bool operator>=(const const_map_iterator<It2>& rhs) const { return _p >= rhs._p; };
		template<class It2>
   		bool operator>(const const_map_iterator<It2>& rhs) const { return _p > rhs._p; };
	public:
		node *_last;
		node *_p;
};

template <class It>
bool	operator==(const const_map_iterator<It>& lhs, const map_iterator<It>& rhs)
{
	return lhs.base() == rhs.base();
}

template <class It>
bool	operator==(const map_iterator<It>& lhs, const const_map_iterator<It>& rhs)
{
	return lhs.base() == rhs.base();
}

template <class It>
bool	operator!=(const const_map_iterator<It>& lhs, const map_iterator<It>& rhs)
{
	return lhs.base() != rhs.base();
}

template <class It>
bool	operator!=(const map_iterator<It>& lhs, const const_map_iterator<It>& rhs)
{
	return lhs.base() != rhs.base();
}

}

#endif