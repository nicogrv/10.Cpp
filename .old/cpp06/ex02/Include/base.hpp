/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:40:35 by vde-leus          #+#    #+#             */
/*   Updated: 2023/11/08 15:35:59 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_H
# define BASE_H

# include <iostream>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>
# include <cstdlib>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

class Base
{
	public :
		virtual ~Base(){};
};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif