/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:43:07 by tidurand          #+#    #+#             */
/*   Updated: 2022/08/15 14:44:29 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <map>
#include <functional>
#include <iostream>
#include <memory>
#include <limits>
#include <stdexcept>
#include "utils.hpp"
#include "red_black_tree.hpp"
#include "map_iterator.hpp"
#include "reverse_iterator.hpp"

namespace ft {
	
template <class Key, class T, class Compare = std::less<Key>,
class Allocator = std::allocator<ft::pair<const Key, T> > >
class map : public tree<Key, T, ft::pair<const Key, T> >
{
	public:
		typedef	Key										key_type;
		typedef	T										mapped_type;
		typedef	ft::pair<const Key, T>					value_type;
		typedef	std::size_t								size_type;
		typedef	std::ptrdiff_t							difference_type;
		typedef	Compare									key_compare;
		typedef	Allocator								allocator_type;
		typedef	value_type&								reference;
		typedef	const value_type&						const_reference;
		typedef	typename Allocator::pointer				pointer;
		typedef	typename Allocator::const_pointer		const_pointer;
		typedef	ft::map_iterator<value_type>			iterator;
		typedef	ft::map_iterator<value_type>		const_iterator;
		typedef	ft::reverse_iterator<iterator>			reverse_iterator;
		typedef	ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		class value_compare : public std::exception
		{
			protected:
				Compare comp;
				value_compare (Compare c) : comp(c) {}
			public:
				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;
				bool operator() (const value_type& x, const value_type& y) const
				{
					return comp(x.first, y.first);
				}
		};
		explicit map(const Compare& comp = Compare(), const Allocator& alloc = Allocator())
		{
			_tree = tree<Key, T, value_type>();
			_comp = comp;
			_alloc = alloc;
		};
		template <class InputIt>
		map(InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator())
		{
			_tree = tree<Key, T, value_type>();
			_comp = comp;
			_alloc = alloc;
			for (InputIt it = first; it != last; ++it)
				insert(*it);
		};
		map(const map& other)
		{
			*this = other;
		}
		map& operator=(const map& other)
		{
			_tree = other._tree;
			_comp = other._comp;
			_alloc = other._alloc;
			clear();
			for (typename map<Key, T>::iterator it = other.begin(); it != other.end(); ++it)
				insert(*it);
			return *this;
		}
		~map(){};
		allocator_type get_allocator() const {return _alloc;};
		T& at( const Key& key )
		{
			return _tree.search(_tree.getRoot(), key);
		};
		const T& at( const Key& key ) const
		{
			return _tree.search(_tree.getRoot(), key);
		};
		T& operator[]( const Key& key )
		{
			_tree.insert(make_pair(key, T()));
			node<value_type> *n = _tree.node_search(_tree.getRoot(), key);
				return n->data.second;
		};
		iterator begin()
		{
			typename map<Key, T>::iterator it(_tree.begin());
			return it;
		};
		const_iterator begin() const
		{
			typename map<Key, T>::const_iterator it(_tree.begin());
			return it;
		};;
		iterator end()
		{
			typename map<Key, T>::iterator ite(_tree.end());
			return ite;
		};
		const_iterator end() const
		{
			typename map<Key, T>::const_iterator it(_tree.end());
			return it;
		};
		reverse_iterator rbegin()
		{
			typename map<Key, T>::iterator it(_tree.end());
			return typename map<Key, T>::reverse_iterator(it);
		};
		const_reverse_iterator rbegin() const
		{
			typename map<Key, T>::const_iterator it(_tree.end());
			return typename map<Key, T>::const_reverse_iterator(it);
		};
		reverse_iterator rend()
		{
			typename map<Key, T>::iterator ite(_tree.begin());
			return typename map<Key, T>::reverse_iterator(ite);
		};
		const_reverse_iterator rend() const
		{
			typename map<Key, T>::const_iterator ite(_tree.begin());
			return typename map<Key, T>::const_reverse_iterator(ite);
		};
		bool empty() const
		{
			if (_tree.getSize() == 0)
				return true;
			else
				return false;
		};
		size_type size() const{return _tree.getSize();};
		size_type max_size() const
		{
			return std::numeric_limits<difference_type>::max() / sizeof(difference_type);
		};
		void clear()
		{
			size_t size = _tree.getSize() -1;
			for (size_t i = 0; i < size; i++)
			{
				typename map<Key, T>::iterator it = begin();
				erase(it);
				--size;
			}
		};
		std::pair<iterator, bool> insert( const value_type& value )
		{
			if (empty())
			{
				_tree.insert(value);
				return std::pair<iterator, bool>(begin(), true);
			}
			else
			{
				typename map<Key, T>::iterator it = find(value.first);
				if (it == end())
				{
					_tree.insert(value);
					return std::pair<iterator, bool>(it, false);
				}
				else
					return std::pair<iterator, bool>(it, true);
			}
		};
		iterator insert( iterator hint, const value_type& value );
		template< class InputIt >
		void insert( InputIt first, InputIt last )
		{
			for (; first != last; ++first)
			{
				_tree.insert(*first);
			}
		};
		void erase( iterator pos )
		{
			_tree.delete_node(pos.base());
		};
		void erase( iterator first, iterator last )
		{
			while (first != last)
			{
				typename map<Key, T>::iterator it = first;
				first++;
				_tree.delete_node(it.base());
			}
		};
		size_type erase( const Key& key )
		{
			if (_tree.delete_search(_tree.getRoot(), key))
				return 1;
			else
				return 0;
		};
		void swap( map& other )
		{
			std::swap(_tree, other._tree);
			std::swap(_comp, other._comp);
			std::swap(_alloc, other._alloc);
			// other.clear();
			// for (typename map<Key, T>::iterator it = other.begin(); it != other.end(); ++it)
			// 	insert(*it);
		};
		size_type count( const Key& key ) const
		{
			if (_tree.search(_tree.getRoot(), key))
				return 1;
			else
				return 0;
		}
		iterator find( const Key& key )
		{
			node<value_type> *n = _tree.node_search(_tree.getRoot(), key);
			typename map<Key, T>::iterator it(n);
			if (n == NULL)
				return end();
			return it;
		};
		const_iterator find( const Key& key ) const
		{
			node<value_type> *n = _tree.node_search(_tree.getRoot(), key);
			std::cout << "HERE" << std::endl;
			typename map<Key, T>::const_iterator it(n);
			if (n == NULL)
				return end();
			return it;
		};
		std::pair<iterator,iterator> equal_range( const Key& key );
		std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const;
		iterator lower_bound( const Key& key )
		{
			typename map<Key, T>::iterator it = begin();
			while (!_comp(key, it->first))
			{
				if (it->first == key)
					return it;
				it++;
			}
			return it;
		};
		const_iterator lower_bound( const Key& key ) const
		{
			typename map<Key, T>::const_iterator it = begin();
			while (!_comp(key, it->first))
			{
				if (it->first == key)
					return it;
				it++;
			}
			return it;
		};
		iterator upper_bound( const Key& key )
		{
			typename map<Key, T>::iterator it = begin();
			while (!_comp(key, it->first))
			{
				it++;
			}
			return it;
		};
		const_iterator upper_bound( const Key& key ) const
		{
			typename map<Key, T>::const_iterator it = begin();
			while (!_comp(key, it->first))
			{
				it++;
			}
			return it;
		};
		key_compare key_comp() const;
		value_compare value_comp() const;
		void print(){_tree.print();};	//debug

	private:
		allocator_type	_alloc;
		Compare			_comp;
		tree<Key, T, value_type>	_tree;
};

template< class Key, class T, class Compare, class Alloc >
bool operator==( const std::map<Key,T,Compare,Alloc>& lhs,
                 const std::map<Key,T,Compare,Alloc>& rhs )
				 {
					if (lhs.size() != rhs.size())
						return false;
					return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
				 };
				 
template< class Key, class T, class Compare, class Alloc >
bool operator!=( const std::map<Key,T,Compare,Alloc>& lhs,
                 const std::map<Key,T,Compare,Alloc>& rhs )
				 {
					if (lhs.size() != rhs.size())
						return true;
					return !ft::equal(lhs.begin(), lhs.end(), rhs.begin());
				};

template< class Key, class T, class Compare, class Alloc >
bool operator<( const std::map<Key,T,Compare,Alloc>& lhs,
                const std::map<Key,T,Compare,Alloc>& rhs )
				{
					return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
				};

template< class Key, class T, class Compare, class Alloc >
bool operator<=( const std::map<Key,T,Compare,Alloc>& lhs,
                const std::map<Key,T,Compare,Alloc>& rhs )
				{
					if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()))
						return true;
					return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
				};

template< class Key, class T, class Compare, class Alloc >
bool operator>( const std::map<Key,T,Compare,Alloc>& lhs,
                const std::map<Key,T,Compare,Alloc>& rhs )
				{
					if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()))
						return false;
					return !ft::equal(lhs.begin(), lhs.end(), rhs.begin());
				};
				
template< class Key, class T, class Compare, class Alloc >
bool operator>=( const std::map<Key,T,Compare,Alloc>& lhs,
                 const std::map<Key,T,Compare,Alloc>& rhs )
				 {
					if (!ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())
					|| (ft::equal(lhs.begin(), lhs.end(), rhs.begin()) && lhs.size() == rhs.size()))
						return true;
					return false;
				};
				 				 
template< class Key, class T, class Compare, class Alloc >
void swap( std::map<Key,T,Compare,Alloc>& lhs,
           std::map<Key,T,Compare,Alloc>& rhs )
			{
				lhs.swap(rhs);
			};
	
}

#endif