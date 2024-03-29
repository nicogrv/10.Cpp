/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:26:29 by ngriveau          #+#    #+#             */
/*   Updated: 2024/02/20 20:03:30 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

/* ************************************************************************** */

int main(int c, char **v)
{
	if (c == 1)
		return 0;
	return (pmergeMe(c, v));
}

/* ************************************************************************** */
