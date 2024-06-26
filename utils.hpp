/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 14:20:42 by tidurand          #+#    #+#             */
/*   Updated: 2022/10/03 15:32:42 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

namespace ft{
    
template<bool B, class T = void>
struct enable_if {};
template<class T>
struct enable_if<true, T> { typedef T type; };


template< class T, T v >
struct integral_constant
{
    typedef T						value_type;
    typedef integral_constant<T,v>	type;
    const static T	value = v;
    operator T() const {return value;}
};
typedef integral_constant< bool, true >		true_type;
typedef integral_constant< bool, false >	false_type;
template< class T >
struct is_integral: false_type {};
template< class T >
struct is_integral<const T>: is_integral<T> {};
template <>
struct is_integral<bool> : true_type {};
template <>
struct is_integral<char> : true_type {};
template <>
struct is_integral<wchar_t> : true_type {};
template <>
struct is_integral<signed char> : true_type {};
template <>
struct is_integral<short int> : true_type {};
template <>
struct is_integral<int> : true_type {};
template <>
struct is_integral<long int> : true_type {};
template <>
struct is_integral<long long int> : true_type {};
template <>
struct is_integral<unsigned char> : true_type {};
template <>
struct is_integral<unsigned short int> : true_type {};
template <>
struct is_integral<unsigned int> : true_type {};
template <>
struct is_integral<unsigned long int> : true_type {};
template <>
struct is_integral<unsigned long long int> : true_type {};


template<class InputIt1, class InputIt2>
bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
                             InputIt2 first2, InputIt2 last2)
{
    for (; (first1 != last1) && (first2 != last2); ++first1, (void)++first2 ) {
        if (*first1 < *first2) return true;
        if (*first2 < *first1) return false;
    }
    return (first1 == last1) && (first2 != last2);
}

template<class InputIt1, class InputIt2>
bool equal(InputIt1 first1, InputIt1 last1, 
           InputIt2 first2)
{
    for (; (first1 != last1); ++first1, (void) ++first2) {
        if (!(*first1 == *first2)) {
            return false;
        }
    }
    return true;
}


template<class T1,class T2>
struct pair
{
	typedef	T1 first_type;
	typedef	T2 second_type;
    pair(): first(), second(){};
    pair( const T1& x, const T2& y ): first(x), second(y){};
    template< class U1, class U2 >
    pair( const pair<U1, U2>& p ): first(p.first), second(p.second){};
    pair& operator=( const pair& other )
    {
        first = other.first;
        second = other.second;
        return *this;
    };
    ~pair(){}
    T1 first;
    T2 second;
};

template <class T1,class T2>
pair<T1,T2> make_pair (T1 x, T2 y)
{
	return ( pair<T1,T2>(x,y) );
}
template< class T1, class T2 >
bool operator==( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
{
    return (lhs.first == rhs.first && lhs.second == rhs.second);
}

template< class T1, class T2 >
bool operator!=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
{
    return !(lhs == rhs);
}

template< class T1, class T2 >
bool operator<( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
{
    if (lhs.first == rhs.first)
        return (lhs.second < rhs.second);
    else
        return (lhs.first < rhs.first);
}

template< class T1, class T2 >
bool operator<=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
{
    return !(rhs < lhs);
}

template< class T1, class T2 >
bool operator>( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
{
    return rhs < lhs;
}

template< class T1, class T2 >
bool operator>=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
{
    return !(lhs < rhs);
}

}

template <class Data>
struct node {
    struct node *left;
    struct node *right;
    struct node *parent;
    int color;
    bool is_leaf;
    Data data;
    node(): data(Data()){}
    node(Data data_param): data(data_param){}
};



#endif