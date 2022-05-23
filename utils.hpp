/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 14:20:42 by tidurand          #+#    #+#             */
/*   Updated: 2022/05/23 18:50:06 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft{
    
template<bool B, class T = void>
struct enable_if {};
template<class T>
struct enable_if<true, T> { typedef T type; };

// template< class T >
// struct is_integral;


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
    for (; first1 != last1; ++first1, ++first2) {
        if (!(*first1 == *first2)) {
            return false;
        }
    }
    return true;
}

template<class T1,class T2>
class pair<T1, T2>
{
    public:
	typedef	T1 first_type;
	typedef	T2 second_type;
    pair(): first(), second(){};
    pair( const T1& x, const T2& y ): first(x), second(y){};
    template< class U1, class U2 >
    pair( const pair<U1, U2>& p ): first(p.first), second(p.second){};
    ~pair(){}
    template< class T1, class T2 >
    std::pair<T1,T2> make_pair( T1 t, T2 u )
    {
	    return ( pair<T1,T2>(t,u));
    };
    private:
    T1 first;
    T2 second;
};

// template <class T1,class T2>
// pair<T1,T2> make_pair (T1 x, T2 y)
// {
// 	return ( pair<T1,T2>(x,y) );
// }
}