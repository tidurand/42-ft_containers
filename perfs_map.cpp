/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perfs_map.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:26:57 by tidurand          #+#    #+#             */
/*   Updated: 2022/10/03 09:57:30 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include "map.hpp"
#ifndef TYPE
#define TYPE ft
#endif
#define	MAX 1000000

int main()
{
	srand(time(NULL));
	TYPE::map<int, std::string> m;

	for (int i = 0; i < MAX; i++)
	{
		m.insert(TYPE::pair<int, std::string>(i, "a"));
	}
	for (int i = 0; i < MAX; i++)
	{
		m.erase(i);
	}
	for (int i = 0; i < MAX; i++)
	{
		m[rand() % MAX] = "a";
	}
	m.erase(m.begin(), m.end());
}