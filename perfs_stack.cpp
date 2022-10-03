/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perfs_stack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:26:17 by tidurand          #+#    #+#             */
/*   Updated: 2022/10/03 09:55:10 by tidurand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include "stack.hpp"
#ifndef TYPE
#define TYPE std
#endif
#define	MAX 10000000

int main()
{
	srand(time(NULL));
	TYPE::stack<int> s;

	for (int i = 0; i < MAX; i++)
	{
		s.push(rand() % MAX);
	}
	for (int i = 0; i < MAX; i++)
	{
		s.pop();
	}
}