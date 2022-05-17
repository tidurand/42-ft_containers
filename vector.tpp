/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:08:19 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/17 17:01:35 by tidurand         ###   ########.fr       */
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
	_alloc = alloc;
	_array = NULL;
}

template <class T, class Allocator>
vector<T, Allocator>::vector( size_type count, const T& value, const Allocator& alloc)
{
	_size = count;
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
	_alloc = other._alloc;
	_array = _alloc.allocate(_size);
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

//ACCESSEURS

template <class T, class Allocator>
T& vector<T, Allocator>::operator[](size_type pos)
{
	return (_array[pos]);
}

template <class T, class Allocator>
const T& vector<T, Allocator>::operator[](size_type pos) const
{
	return (_array[pos]);
}

//CAPACITY

template <class T, class Allocator>
size_type vector<T, Allocator>::empty() const
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

}
