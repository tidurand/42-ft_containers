/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perfs_vector.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:26:40 by tidurand          #+#    #+#             */
/*   Updated: 2022/10/02 12:56:27 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include "vector.hpp"
#ifndef TYPE
#define TYPE ft
#endif
#define	MAX 100000

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
	for (int i = 0; i < 10; i++)
	{
		v.insert(v.begin(), 1);
	}
	// v.insert(v.begin(), MAX, 1);
	for (int i = 0; i < 10; i++)
	{
		v.erase(v.begin());
	}
	v.assign(MAX, 8);
	v.clear();
}