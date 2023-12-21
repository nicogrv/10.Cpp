/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:47:20 by vde-leus          #+#    #+#             */
/*   Updated: 2023/11/08 15:46:19 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base.hpp"
// #include "base.cpp"


int	main(void)
{
	int limite = 5;
	for (int i = 0; i < limite; i++) {
		
		Base	*test1 = generate();
		identify(test1);
		delete test1;

	}
	return (0);
		
}