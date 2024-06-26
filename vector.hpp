/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:57:17 by tidurand          #+#    #+#             */
/*   Updated: 2022/10/05 13:55:12 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <iostream>
# include <algorithm>
# include <vector>
#include <limits>
#include <stdexcept>
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "utils.hpp"

namespace ft {

template <class T, class Allocator = std::allocator<T> >
class vector
{
	public:
		typedef	T										value_type;
		typedef	Allocator								allocator_type;
		typedef std::size_t								size_type;
		typedef	std::ptrdiff_t							difference_type;
		typedef	value_type&								reference;
		typedef	const value_type&						const_reference;
		typedef	typename Allocator::pointer				pointer;
		typedef	typename Allocator::const_pointer		const_pointer;
		typedef	ft::iterator<T>							iterator;
		typedef	ft::iterator<const T>					const_iterator;
		typedef	ft::reverse_iterator<iterator>			reverse_iterator;
		typedef	ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		
		vector(): _size(0), _capacity(0), _array(NULL){};
		explicit vector( const Allocator& alloc )
		{
			_size = 0;
			_capacity = 0;
			_alloc = alloc;
			_array = NULL;
		};
		explicit vector( size_type count, const T& value = T(),
				const Allocator& alloc = Allocator())
		{
			_size = count;
			_capacity = count;
			_alloc = alloc;
			_array = _alloc.allocate(count);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(&_array[i], value);
		};
		template< class InputIt>
		vector( InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, bool>::type = true, const Allocator& alloc = Allocator())
		{
			size_type	count = 0;
			
			for (InputIt it = first; it != last; it++)
				count++;
			_size = count;
			_capacity = count;
			_alloc = alloc;
			_array = _alloc.allocate(_capacity);

			count = 0;
			for (InputIt it = first; it != last; it++)
			{
				_alloc.construct(&_array[count], *it);
				count++;
			}
		};
		vector( const vector& other )
		{
			_size = 0;
			_capacity = 0;
			_size = other._size;
			_capacity = other._size;
			_alloc = other._alloc;
			_array = NULL;
			if (_capacity > 0)
				_array = _alloc.allocate(_capacity);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(&_array[i], other._array[i]);
		};
		~vector()
		{
			if (_array && _capacity > 0)
			{
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_array[i]);
				_alloc.deallocate(_array, _capacity);
			}
		};
		vector& operator=( const vector& other )
		{
			if (_array)
			{
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_array[i]);
				if (_capacity > 0)
					_alloc.deallocate(_array, _capacity);
			}
			_size = other._size;
			if (other._size > _capacity)
				_capacity = other._size;
			_alloc = other._alloc;
			if (_capacity > 0)
			{
				_array = _alloc.allocate(_size);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_array[i], other._array[i]);
			}
			else
				_array = NULL;
			return (*this);
		};
		void assign( size_type count, const T& value)
		{
			T *temp = _alloc.allocate(_size);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(&temp[i], _array[i]);
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&_array[i]);
			if ((size_t)count > _capacity)
			{
				_alloc.deallocate(_array, _capacity);
				_array = _alloc.allocate(count);
				_capacity = count;
			}
			for (size_type i = 0; i < (size_t)count; i++)
				_alloc.construct(&_array[i], value);
			for (size_type i = _size; i < _size; i++)
				_alloc.construct(&_array[i], temp[i]);
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&temp[i]);
			_alloc.deallocate(temp, _size);
			_size = count;	
		};
		template< class InputIt>
		void assign( InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, bool>::type = true)
		{
			size_type	count = 0;
			
			for (InputIt it = first; it != last; it++)
				count++;
			T *temp = _alloc.allocate(_size);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(&temp[i], _array[i]);
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&_array[i]);
			if (count > _capacity)
			{
				_alloc.deallocate(_array, _capacity);
				_array = _alloc.allocate(count);
				_capacity = count;
			}
			int j = 0;
			for (InputIt it = first; it != last; it++)
			{
				_alloc.construct(&_array[j], *it);
				j++;
			}
			for (size_type i = _size; i < _size; i++)
				_alloc.construct(&_array[i], temp[i]);
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&temp[i]);
			_alloc.deallocate(temp, _size);
			_size = count;
		};
		allocator_type get_allocator() const {return _alloc;};
		reference at( size_type pos )
		{
			if (pos < 0 || pos > _size)
				throw std::out_of_range("Out_of_range");
			return (_array[pos]);
		};
		const_reference at( size_type pos ) const
		{
			if (pos < 0 || pos > _size)
				throw std::out_of_range("Out_of_range");
			return (_array[pos]);
		};
		reference operator[]( size_type pos )
		{
			if (pos < 0 || pos > _size)
				throw std::out_of_range("Out_of_range");
			return (_array[pos]);
		};
		const_reference operator[]( size_type pos ) const
		{
			if (pos < 0 || pos > _size)
				throw std::out_of_range("Out_of_range");
			return (_array[pos]);
		};
		reference front() {return (_array[0]);};
		const_reference front() const {return (_array[0]);};
		reference back() {return (_array[_size - 1]);};
		const_reference back() const {return (_array[_size - 1]);};
		T* data() {return (&_array[0]);};
		const T* data() const {return (&_array[0]);};
		iterator begin()
		{
			typename vector<T, Allocator>::iterator it(_array);
			return (it);
		};
		const_iterator begin() const
		{
			typename vector<T, Allocator>::const_iterator it(_array);
			return (it);
		};
		iterator end()
		{
			typename vector<T, Allocator>::iterator it(_array);
			for (size_t i = 0; i < _size; i++)
				++it;
			return (it);
		};
		const_iterator end() const
		{
			typename vector<T, Allocator>::const_iterator it(_array);
			for (size_t i = 0; i < _size; i++)
				++it;
			return (it);
		};
		reverse_iterator rbegin()
		{
			return vector<T, Allocator>::reverse_iterator(this->end());
		};
		const_reverse_iterator rbegin() const
		{
			return vector<T, Allocator>::const_reverse_iterator(this->end());
		};
		reverse_iterator rend()
		{
			return vector<T, Allocator>::reverse_iterator(this->begin());
		};
		const_reverse_iterator rend() const
		{
			return vector<T, Allocator>::const_reverse_iterator(this->begin());
		};
		bool empty() const
		{
			if (_size == 0)
				return true;
			else
				return false;
		};
		size_type size() const {return _size;};
		size_type max_size() const
		{
			return std::numeric_limits<difference_type>::max();
		};
		void reserve( size_type new_cap )
		{
			if (new_cap > max_size())
				throw std::length_error("length error");
			if (new_cap > _capacity)
			{
				T *temp = _alloc.allocate(_size);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&temp[i], _array[i]);
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_array[i]);
				if (_capacity > 0)
				{
					_alloc.deallocate(_array, _capacity);
					_capacity = 0;
				}
				_array = _alloc.allocate(new_cap);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_array[i], temp[i]);
				_capacity = new_cap;
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&temp[i]);
				_alloc.deallocate(temp, _size);
			}
		};
		size_type capacity() const {return _capacity;};
		void clear()
		{
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&_array[i]);
			_size = 0;
		};
		iterator insert( iterator pos, const T& value )
		{
			size_type count = 0;
			if (_size > 0)
			{
				for (typename vector<T, Allocator>::iterator it = this->begin(); it != pos; ++it)
					count++;
			}
			if (_capacity == _size)
				reserve(_size + 1);
			T *temp = _alloc.allocate(_size);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(&temp[i], _array[i]);
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&_array[i]);
			for (size_type i = 0; i < count; i++)
				_alloc.construct(&_array[i], temp[i]);
			_alloc.construct(&_array[count], value);
			for (size_type i = count; i < _size ; i++)
				_alloc.construct(&_array[i+1], temp[i]);
			_alloc.deallocate(temp, _size);
			_size++;
			typename vector<T, Allocator>::iterator it(_array + count);
			return it;
		};
		void insert( iterator pos, size_type count, const T& value)
		{
			size_type c = 0;
			if (_size > 0)
			{
				for (typename vector<T, Allocator>::iterator it = this->begin(); it != pos; ++it)
					c++;
			}
			if (_capacity < _size + count)
			{
				reserve(_size * 2);
				reserve(_size + count);
			}
			T *temp = _alloc.allocate(_size);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(&temp[i], _array[i]);
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&_array[i]);
			for (size_type i = 0; i < c; i++)
				_alloc.construct(&_array[i], temp[i]);
			for (size_type i = c; i < c + count; i++)
				_alloc.construct(&_array[i], value);
			for (size_type i = c + count; i < _size + count; i++)
				_alloc.construct(&_array[i], temp[i - count]);
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&temp[i]);
			_alloc.deallocate(temp, _size);
			_size += count;
		};
		template< class InputIt >
		void insert( iterator pos, InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, bool>::type = true)
		{
			size_type count = 0;
			for (InputIt it = first; it != last; it++)
				count++;
			size_type c = 0;
			if (_size > 0)
			{
				for (typename vector<T, Allocator>::iterator it = this->begin(); it != pos; ++it)
					c++;
			}
			if (_capacity < _size + count)
				reserve(_size + count);
			T *temp = _alloc.allocate(_size);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(&temp[i], _array[i]);
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&_array[i]);
			for (size_type i = 0; i < c; i++)
				_alloc.construct(&_array[i], temp[i]);
			for (size_type i = c; i < c + count; i++)
				_alloc.construct(&_array[i], *first++);
			for (size_type i = c + count; i < _size + count; i++)
				_alloc.construct(&_array[i], temp[i - count]);
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&temp[i]);
			_alloc.deallocate(temp, _size);
			_size += count;
		};
		iterator erase( iterator pos )
		{
			T *temp = _alloc.allocate(_size);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(&temp[i], _array[i]);
			size_type count = 0;
			if (_size > 0)
			{
				for (typename vector<T, Allocator>::iterator it = this->begin(); it != pos; ++it)
					count++;
			}
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&_array[i]);
			for (size_type i = 0; i < count; i++)
				_alloc.construct(&_array[i], temp[i]);
			for (size_type i = count + 1; i < _size; i++)
				_alloc.construct(&_array[i-1], temp[i]);
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&temp[i]);
			_alloc.deallocate(temp, _size);
			_size--;
			return pos;
		};
		iterator erase( iterator first, iterator last )
		{
			T *temp = _alloc.allocate(_size);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(&temp[i], _array[i]);
				
			size_type begin = 0;
			for (typename vector<T, Allocator>::iterator it = this->begin(); it != first; ++it)
				begin++;
			size_type end = 0;
			for (typename vector<T, Allocator>::iterator it = this->begin(); it != last; ++it)
				end++;
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&_array[i]);
			for (size_type i = 0; i < begin; i++)
				_alloc.construct(&_array[i], temp[i]);
			for (size_type i = end; i < _size; i++)
				_alloc.construct(&_array[i-end + begin], temp[i]);
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&temp[i]);
			_alloc.deallocate(temp, _size);
			_size -= end - begin;
			return first;
		};
		void push_back( const T& value )
		{
			if (_size == 0)
				reserve(1);
			if (_size == _capacity)
				reserve(_capacity * 2);
			_alloc.construct(&_array[_size], value);
			_size++;
		};
		void pop_back()
		{
			_alloc.destroy(&_array[_size - 1]);
			_size--;
		};
		void resize( size_type count, T value = T() )
		{
			if (count < _size)
			{
				reserve(count);
				T *temp = _alloc.allocate(count);
				for (size_type i = 0; i < count; i++)
					_alloc.construct(&temp[i], _array[i]);
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_array[i]);
				for (size_type i = 0; i < count; i++)
					_alloc.construct(&_array[i], temp[i]);
				_size = count; 
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&temp[i]);
				_alloc.deallocate(temp, count);
			}
			if (count > _size)
			{
				if (count > _capacity)
				{
					reserve(count);
					reserve(_size * 2);
				}
				T *temp = _alloc.allocate(count);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&temp[i], _array[i]);
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_array[i]);
				if (_capacity > 0)
				{
					_alloc.deallocate(_array, _capacity);
				}
				_array = _alloc.allocate(count);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_array[i], temp[i]);
				for (size_type i = _size; i < count; i++)
					_alloc.construct(&_array[i], value);
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&temp[i]);
				_size = count;
				_alloc.deallocate(temp, count);
			}
		};
		void swap( vector& other )
		{
			std::swap(_array, other._array);
			std::swap(_size, other._size);
			std::swap(_capacity, other._capacity);
		};
	private:
		size_type _size;
		size_type _capacity;
		T*	_array;
		allocator_type _alloc;

};

template< class T, class Alloc >
bool operator==( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
{
	if (lhs.size() != rhs.size())
		return false;
	return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
};
template< class T, class Alloc >
bool operator!=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
{
	if (lhs.size() != rhs.size())
		return true;
	return !ft::equal(lhs.begin(), lhs.end(), rhs.begin());
};
template< class T, class Alloc >
bool operator<( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
{
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
};
template< class T, class Alloc >
bool operator<=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
{
	if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()))
		return true;
	return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
};
template< class T, class Alloc >
bool operator>( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
{
	if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()))
		return false;
	return !ft::equal(lhs.begin(), lhs.end(), rhs.begin());
};
template< class T, class Alloc >
bool operator>=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
{
	if (!ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())
	|| (ft::equal(lhs.begin(), lhs.end(), rhs.begin()) && lhs.size() == rhs.size()))
		return true;
	return false;
};

template< class T, class Alloc >
void swap( ft::vector<T,Alloc>& lhs, ft::vector<T,Alloc>& rhs ) 
{
	lhs.swap(rhs);
};

}

#endif