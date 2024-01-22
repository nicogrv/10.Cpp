/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:20:03 by ngriveau          #+#    #+#             */
/*   Updated: 2024/01/22 17:50:03 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Array.hpp"

int main()
{
	Array<int> coucou(12);
	Array<int> salut(coucou);	

	Array<int> aurevoir(12);
	Array<int> ciao(1);
	ciao = aurevoir;
}