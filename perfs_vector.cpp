/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perfs_vector.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:26:40 by tidurand          #+#    #+#             */
/*   Updated: 2022/10/03 11:29:02 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include "vector.hpp"
#ifndef TYPE
#define TYPE std
#endif
#define	MAX 1000000

int main()
{
	srand(time(NULL));
	TYPE::vector<int> v;

	for (int i = 0; i < MAX; i++)
	{
		v.push_back(rand() % MAX);
	}
	for (int i = 0; i < MAX; i++)
	{
		v.pop_back();
	}
	v.insert(v.begin(), MAX, rand() % MAX);
	v.erase(v.begin(), v.end());
	v.assign(MAX, 8);
	v.clear();
}