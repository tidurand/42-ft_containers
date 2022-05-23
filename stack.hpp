/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:24:02 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/23 14:24:56 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"
#include <stack>

namespace ft {
	
template <class T, class Container = ft::vector<T> >
class stack
{
	public:
		typedef	Container							container_type;
		typedef	typename Container::value_type		value_type;
		typedef	typename Container::size_type		size_type;
		typedef	typename Container::reference		reference;
		typedef	typename Container::const_reference	const_reference;
	
		stack(const Container& cont = Container()){c = cont;};
		stack (const stack& other){c = other.c;};
		~stack(){};
		stack& operator=(const stack& other){c = other.c;};
		reference top(){return c.back();};
		const_reference top() const {return c.back();};
		bool empty() const {return c.empty();};
		size_type size() const {return c.size();};
		void push( const value_type& value ) {c.push_back(value);};
		void pop() {c.pop_back();};

		
	protected:
		container_type c;
};

template< class T, class Container >
bool operator==( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){return (lhs.c == rhs.c);};

template< class T, class Container >
bool operator!=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){return (lhs.c != rhs.c);};

template< class T, class Container >
bool operator<( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){return (lhs.c < rhs.c);};

template< class T, class Container >
bool operator<=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){return (lhs.c <= rhs.c);};

template< class T, class Container >
bool operator>( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){return (lhs.c > rhs.c);};

template< class T, class Container >
bool operator>=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs ){return (lhs.c >= rhs.c);};

}
#endif