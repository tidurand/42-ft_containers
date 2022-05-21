/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:08:19 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/21 11:01:55 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TPP
#define VECTOR_TPP
#include "vector.hpp"

namespace ft {
	
		typedef	std::size_t								size_type;
		typedef	std::ptrdiff_t							difference_type;



//CONSTRUCTEURS

template <class T, class Allocator>
vector<T, Allocator>::vector(): _size(0), _capacity(0), _array(NULL){}

template <class T, class Allocator>
vector<T, Allocator>::vector(const Allocator& alloc)
{
	_size = 0;
	_capacity = 0;
	_alloc = alloc;
	_array = NULL;
}

template <class T, class Allocator>
vector<T, Allocator>::vector( size_type count, const T& value, const Allocator& alloc)
{
	_size = count;
	_capacity = count;
	_alloc = alloc;
	_array = _alloc.allocate(count);
	for (size_type i = 0; i < _size; i++)
		_alloc.construct(&_array[i], value);
}

template <class T, class Allocator>
template <class InputIt>
vector<T, Allocator>::vector(InputIt first, InputIt last, const Allocator& alloc)
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
}

template <class T, class Allocator>
vector<T, Allocator>::vector(const vector& other)
{
	_size = other._size;
	_capacity = other._capacity;
	_alloc = other._alloc;
	_array = _alloc.allocate(_capacity);
	for (size_type i = 0; i < _size; i++)
		_alloc.construct(&_array[i], other._array[i]);
}

template <class T, class Allocator>
vector<T, Allocator>& vector<T, Allocator>::operator=(const vector& other)
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
	_array = _alloc.allocate(_capacity);
	for (size_type i = 0; i < _size; i++)
		_alloc.construct(&_array[i], other._array[i]);
	return (*this);
}

template <class T, class Allocator>
void	vector<T, Allocator>::assign(size_type count, const T& value)
{
	T *temp = _alloc.allocate(_size);
	for (size_type i = 0; i < _size; i++)
		_alloc.construct(&temp[i], _array[i]);
	for (size_type i = 0; i < _size; i++)
		_alloc.destroy(&_array[i]);
	if (count > _capacity)
	{
		_alloc.deallocate(_array, _capacity);
		_array = _alloc.allocate(count);
	}
	for (size_type i = 0; i < count; i++)
		_alloc.construct(&_array[i], value);
	for (size_type i = _size; i < _size; i++)
		_alloc.construct(&_array[i], temp[i]);
	_size = count;
	_alloc.deallocate(temp, count);
	
}

template <class T, class Allocator>
template< class InputIt >
void vector<T, Allocator>::assign(InputIt first, InputIt last)
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
	}
	int j = 0;
	for (InputIt it = first; it != last; it++)
	{
		_alloc.construct(&_array[j], *it);
		j++;
	}
	for (size_type i = _size; i < _size; i++)
		_alloc.construct(&_array[i], temp[i]);
	_size = count;
	_alloc.deallocate(temp, count);
}

//DESTRUCTEUR

template <class T, class Allocator>
vector<T, Allocator>::~vector()
{
	if (_array)
		_alloc.deallocate(_array, _capacity);
}

//ACCESSEURS
template <class T, class Allocator>
Allocator vector<T, Allocator>::get_allocator() const
{
	return _alloc;
}

template <class T, class Allocator>
T& vector<T, Allocator>::at( size_type pos )
{
	if (pos < 0)
		throw OutOfRange();
	return (_array[pos]);
}

template <class T, class Allocator>
const T& vector<T, Allocator>::at( size_type pos ) const
{
	if (pos < 0)
		throw OutOfRange();
	return (_array[pos]);
}

template <class T, class Allocator>
T& vector<T, Allocator>::operator[](size_type pos)
{
	if (pos < 0)
		throw OutOfRange();
	return (_array[pos]);
}

template <class T, class Allocator>
const T& vector<T, Allocator>::operator[](size_type pos) const
{
	if (pos < 0)
		throw OutOfRange();
	return (_array[pos]);
}

template <class T, class Allocator>
T& vector<T, Allocator>::front()
{
	return (_array[0]);
}

template <class T, class Allocator>
const T& vector<T, Allocator>::front() const
{
	return (_array[0]);
}

template <class T, class Allocator>
T& vector<T, Allocator>::back()
{
	return (_array[_size - 1]);
}

template <class T, class Allocator>
const T& vector<T, Allocator>::back() const
{
	return (_array[_size - 1]);
}

template <class T, class Allocator>
T* vector<T, Allocator>::data()
{
	return (&_array[0]);
}

template <class T, class Allocator>
const T* vector<T, Allocator>::data() const
{
	return (&_array[0]);
}

//ITERATORS

template< class T, class Allocator >
typename vector<T, Allocator>::iterator vector<T, Allocator>::begin()
{
	typename vector<T, Allocator>::iterator it(_array);

	return (it);
}


template< class T, class Allocator >
typename vector<T, Allocator>::const_iterator vector<T, Allocator>::begin() const
{
	typename vector<T, Allocator>::const_iterator it(_array);

	return (it);
}

template< class T, class Allocator >
typename vector<T, Allocator>::iterator vector<T, Allocator>::end()
{
	typename vector<T, Allocator>::iterator it(_array);
	for (size_t i = 0; i < _size; i++)
		++it;

	return (it);
}

template< class T, class Allocator >
typename vector<T, Allocator>::const_iterator vector<T, Allocator>::end() const
{
	typename vector<T, Allocator>::const_iterator it(_array);
	for (size_t i = 0; i < _size; i++)
		++it;

	return (it);
}

template< class T, class Allocator >
typename vector<T, Allocator>::reverse_iterator vector<T, Allocator>::rbegin()
{
	typename vector<T, Allocator>::reverse_iterator it(_array);
	for (size_t i = 0; i < _size; i++)
		--it;
	return (it);
}

template< class T, class Allocator >
typename vector<T, Allocator>::const_reverse_iterator vector<T, Allocator>::rbegin() const
{
	typename vector<T, Allocator>::const_reverse_iterator it(_array);
	for (size_t i = 0; i < _size; i++)
		--it;
	return (it);
}

template< class T, class Allocator >
typename vector<T, Allocator>::reverse_iterator vector<T, Allocator>::rend()
{
	typename vector<T, Allocator>::reverse_iterator it(_array);
	
	return (it);
}

template< class T, class Allocator >
typename vector<T, Allocator>::const_reverse_iterator vector<T, Allocator>::rend() const
{
	typename vector<T, Allocator>::const_reverse_iterator it(_array);
	
	return (it);
}

//CAPACITY

template <class T, class Allocator>
bool vector<T, Allocator>::empty() const
{
	if (_size == 0)
		return true;
	else
		return false;
}

template <class T, class Allocator>
size_type vector<T, Allocator>::size() const
{
	return _size;
}

template <class T, class Allocator>
size_type vector<T, Allocator>::max_size() const
{
	return std::numeric_limits<difference_type>::max() / sizeof(difference_type);
}

template <class T, class Allocator>
void vector<T, Allocator>::reserve(size_type new_cap)
{
	if (new_cap > _capacity)
	{
		T *temp = _alloc.allocate(_size);
		for (size_type i = 0; i < _size; i++)
			_alloc.construct(&temp[i], _array[i]);
		for (size_type i = 0; i < _size; i++)
			_alloc.destroy(&_array[i]);
		if (_capacity > 0)
			_alloc.deallocate(_array, _capacity);
		_array = _alloc.allocate(new_cap);
		for (size_type i = 0; i < _size; i++)
			_alloc.construct(&_array[i], temp[i]);
		_capacity = new_cap;
		_alloc.deallocate(temp, _size);
	}
}

template <class T, class Allocator>
size_type vector<T, Allocator>::capacity() const
{
	return _capacity;
}

//MODIFIERS

template <class T, class Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::insert( iterator pos, const T& value )
{
	if (_capacity == _size)
		reserve(_size + 1);
	T *temp = _alloc.allocate(_size);
	for (size_type i = 0; i < _size; i++)
		_alloc.construct(&temp[i], _array[i]);
	size_type count = 0;
	while (*pos != _array[count])
		count++;
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
}

template <class T, class Allocator>
void vector<T, Allocator>::insert( iterator pos, size_type count, const T& value )
{
	if (_capacity < _size + count)
		reserve(_size + count);
	T *temp = _alloc.allocate(_size);
	for (size_type i = 0; i < _size; i++)
		_alloc.construct(&temp[i], _array[i]);
	size_type c = 0;
	while (*pos != _array[c])
		c++;
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
}

template <class T, class Allocator>
template< class InputIt >
void vector<T, Allocator>::insert( iterator pos, InputIt first, InputIt last )
{
	size_type count = 0;
	for (InputIt it = first; it != last; it++)
		count++;
	if (_capacity < _size + count)
		reserve(_size + count);
	T *temp = _alloc.allocate(_size);
	for (size_type i = 0; i < _size; i++)
		_alloc.construct(&temp[i], _array[i]);
	size_type c = 0;
	while (*pos != _array[c])
		c++;
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
}

template <class T, class Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::erase( iterator pos )
{
	T *temp = _alloc.allocate(_size);
	for (size_type i = 0; i < _size; i++)
		_alloc.construct(&temp[i], _array[i]);
	size_type count = 0;
	while (*pos != _array[count])
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
}
template <class T, class Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::erase( iterator first, iterator last )
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
}
		
template <class T, class Allocator>
void vector<T, Allocator>::clear()
{
	for (size_type i = 0; i < _size; i++)
		_alloc.destroy(&_array[i]);
	_size = 0;
}

template <class T, class Allocator>
void vector<T, Allocator>::push_back(const T& value)
{
	if (_size == 0)
		reserve(1);
	if (_size == _capacity)
		reserve(_capacity * 2);
	_alloc.construct(&_array[_size], value);
	_size++;
}

template <class T, class Allocator>
void vector<T, Allocator>::pop_back()
{
	_alloc.destroy(&_array[_size - 1]);
	_size--;
}

template <class T, class Allocator>
void vector<T, Allocator>::resize( size_type count, T value)
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
			_alloc.deallocate(_array, _capacity);
		_array = _alloc.allocate(count);
		for (size_type i = 0; i < _size; i++)
			_alloc.construct(&_array[i], temp[i]);
		for (size_type i = _size; i < count; i++)
			_alloc.construct(&_array[i], value);
		_size = count;
		_alloc.deallocate(temp, count);
	}
}

template <class T, class Allocator>
void vector<T, Allocator>::swap(vector& other)
{
	std::swap(_array, other._array);
	std::swap(_size, other._size);
	std::swap(_capacity, other._capacity);
}

}
//COMPARAISONS

#endif