/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:08:19 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/18 11:00:20 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

namespace ft {
	
		typedef	std::size_t								size_type;
		typedef	std::ptrdiff_t							difference_type;



//CONSTRUCTEURS

template <class T, class Allocator>
vector<T, Allocator>::vector(): _size(0), _array(NULL){}

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
	(void)first;
	(void)last;
	(void)alloc;
	//TODO
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

//DESTRUCTEUR

template <class T, class Allocator>
vector<T, Allocator>::~vector()
{
	if (_array)
		_alloc.deallocate(_array, _size);
}

template <class T, class Allocator>
Allocator vector<T, Allocator>::get_allocator() const
{
	return _alloc;
}


//ACCESSEURS

template <class T, class Allocator>
T& vector<T, Allocator>::at( size_type pos )
{
	if (pos < 0 || pos >= _capacity)
		throw OutOfRange();
	return (_array[pos]);
}

template <class T, class Allocator>
const T& vector<T, Allocator>::at( size_type pos ) const
{
	if (pos < 0 || pos >= _capacity)
		throw OutOfRange();
	return (_array[pos]);
}

template <class T, class Allocator>
T& vector<T, Allocator>::operator[](size_type pos)
{
	if (pos < 0 || pos >= _capacity)
		throw OutOfRange();
	return (_array[pos]);
}

template <class T, class Allocator>
const T& vector<T, Allocator>::operator[](size_type pos) const
{
	if (pos < 0 || pos >= _capacity)
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

// template <class T, class Allocator>
// size_type vector<T, Allocator>::max_size() const
// {
// 	return std::distance(begin(), end());
// }

template <class T, class Allocator>
void vector<T, Allocator>::reserve(size_type new_cap)
{
	if (new_cap > _capacity)
	{
		T *temp = _array;
		for (size_type i = 0; i < _size; i++)
			_alloc.destroy(&_array[i]);
		if (_array)
			_alloc.deallocate(_array, _capacity);
		_array = _alloc.allocate(new_cap);
		for (size_type i = 0; i < _size; i++)
			_alloc.construct(&_array[i], temp[i]);
		_capacity = new_cap;
	}
}

template <class T, class Allocator>
size_type vector<T, Allocator>::capacity() const
{
	return _capacity;
}

//MODIFIERS
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
}
//COMPARAISONS
