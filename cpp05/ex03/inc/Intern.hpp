/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:05:23 by ngriveau          #+#    #+#             */
/*   Updated: 2024/01/17 12:30:48 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include "./AForm.hpp"
# include "./PresidentialPardonForm.hpp"
# include "./RobotomyRequestForm.hpp"
# include "./ShrubberyCreationForm.hpp"

/* ************************************************************************** */

class Intern
{
	public:
		Intern();
		Intern(const Intern &copy);
		~Intern();
        Intern   &operator=(const Intern &copy);

		AForm	*makeForm(std::string nameOfTheFrom, std::string target); 


	private:

		
};

/* ************************************************************************** */


#endif