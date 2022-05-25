/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:57:17 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/25 17:43:04 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <iostream>
# include <algorithm>
# include <vector>
#include <limits>
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
		typedef	ft::reverse_iterator<T>					reverse_iterator; //must be <iterator>
		typedef	ft::reverse_iterator<const T>			const_reverse_iterator;
		
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
		vector( InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type = NULL, const Allocator& alloc = Allocator())
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
			_size = other._size;
			_capacity = other._capacity;
			_alloc = other._alloc;
			if (other._capacity > 0)
				_array = _alloc.allocate(_capacity);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(&_array[i], other._array[i]);
		};
		~vector()
		{
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&_array[i]);
			if (_array && _capacity > 0)
				_alloc.deallocate(_array, _capacity);
		};
		vector& operator=( const vector& other )
		{
			if (_array)
			{
				for (size_type i = 0; i < _size; i++)
					get_allocator().destroy(&_array[i]);
				if (_capacity > 0)
					get_allocator().deallocate(_array, _capacity);
			}
			_size = other._size;
			_capacity = other._size;
			_alloc = other._alloc;
			if (other._capacity > 0)
				_array = _alloc.allocate(_capacity);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(&_array[i], other._array[i]);
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
			_alloc.deallocate(temp, _size);
			_size = count;	
		};
		template< class InputIt>
		void assign( InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type = NULL)
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
			_alloc.deallocate(temp, _size);
			_size = count;
		};
		allocator_type get_allocator() const {return _alloc;};
		reference at( size_type pos )
		{
			if (pos < 0 || pos > _capacity)
				throw OutOfRange();
			return (_array[pos]);
		};
		const_reference at( size_type pos ) const
		{
			if (pos < 0 || pos > _capacity)
				throw OutOfRange();
			return (_array[pos]);
		};
		reference operator[]( size_type pos )
		{
			if (pos < 0 || pos > _capacity)
				throw OutOfRange();
			return (_array[pos]);
		};
		const_reference operator[]( size_type pos ) const
		{
			if (pos < 0 || pos > _capacity)
				throw OutOfRange();
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
			typename vector<T, Allocator>::reverse_iterator it(_array);
			for (size_t i = 0; i < _size; i++)
				--it;
			return (it);
		};
		const_reverse_iterator rbegin() const
		{
			typename vector<T, Allocator>::const_reverse_iterator it(_array);
			for (size_t i = 0; i < _size; i++)
				--it;
			return (it);
		};
		reverse_iterator rend()
		{
			typename vector<T, Allocator>::reverse_iterator it(_array);
			return (it);
		};
		const_reverse_iterator rend() const
		{
			typename vector<T, Allocator>::const_reverse_iterator it(_array);	
			return (it);
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
			return std::numeric_limits<difference_type>::max() / sizeof(difference_type);
		};
		void reserve( size_type new_cap )
		{
			if (new_cap > max_size())
				throw OutOfRangeReserve();
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
			while (_size > 0 && *pos != _array[count])
				count++;
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
			return pos;
		};
		void insert( iterator pos, size_type count, const T& value )
		{
			size_type c = 0;
			while (_size > 0 && *pos != _array[c])
				c++;
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
				_alloc.construct(&_array[i], value);
			for (size_type i = c + count; i < _size + count; i++)
				_alloc.construct(&_array[i], temp[i - count]);
			_alloc.deallocate(temp, _size);
			_size+= count;
		};
		template< class InputIt >
		void insert( iterator pos, InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type = NULL)
		{
			size_type count = 0;
			for (InputIt it = first; it != last; it++)
				count++;
			size_type c = 0;
			while (_size > 0 && *pos != _array[c])
				c++;
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
			_alloc.deallocate(temp, _size);
			_size+= count;
		};
		iterator erase( iterator pos )
		{
			T *temp = _alloc.allocate(_size);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(&temp[i], _array[i]);
			size_type count = 0;
			while (_size > 0 && *pos != _array[count])
				count++;
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&_array[i]);
			for (size_type i = 0; i < count; i++)
				_alloc.construct(&_array[i], temp[i]);
			for (size_type i = count + 1; i < _size; i++)
				_alloc.construct(&_array[i-1], temp[i]);
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
			while (*first != _array[begin])
				begin++;
				
			size_type end = 0;
			while (*last != _array[end])
				end++;
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&_array[i]);
			for (size_type i = 0; i < begin; i++)
				_alloc.construct(&_array[i], temp[i]);
			for (size_type i = begin + end; i < _size; i++)
				_alloc.construct(&_array[i-end], temp[i]);
			_alloc.deallocate(temp, _size);
			_size -= end - begin;
			return last;
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
				T *temp = _alloc.allocate(count);
				for (size_type i = 0; i < count; i++)
					_alloc.construct(&temp[i], _array[i]);
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_array[i]);
				for (size_type i = 0; i < count; i++)
					_alloc.construct(&_array[i], temp[i]);
				_size = count; 
				_alloc.deallocate(temp, count);
			}
			if (count > _size)
			{
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
		class OutOfRange : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{return ("vector :Out of range");}
		};
		class OutOfRangeReserve : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{return ("vector::reserve");}
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
	return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
};
template< class T, class Alloc >
bool operator!=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
{
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
	return !ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
};
template< class T, class Alloc >
bool operator>=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
{
	return !ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
};

template< class T, class Alloc >
void swap( std::vector<T,Alloc>& lhs, std::vector<T,Alloc>& rhs ) 
{
	std::swap(lhs, rhs);
};

}

//#include "vector.tpp"

#endif