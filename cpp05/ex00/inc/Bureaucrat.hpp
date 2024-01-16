/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:32:09 by ngriveau          #+#    #+#             */
/*   Updated: 2024/01/15 17:16:22 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP	
	#define BUREAUCRAT_HPP
	#include <iostream>
	#include <string>

/* ************************************************************************** */

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat();
		Bureaucrat	&operator=(const Bureaucrat &copy);

		Bureaucrat(std::string name);
		Bureaucrat(int grade);
		Bureaucrat(std::string name, int grade);

		std::string	getName() const;
		int			getGrade() const;

		void		increment();
		void		decrement();

		class		GradeTooHighException;
		class		GradeTooLowException;
	
	private:
		const std::string	_name;
		int					_grade;
};

/* ************************************************************************** */

class Bureaucrat::GradeTooHighException : public std::exception 
{
	public:
		GradeTooHighException(const char *message);
		const char	*what() const throw();
	
	private:
		const char *_message;
};

class Bureaucrat::GradeTooLowException : public std::exception 
{
	public:
		GradeTooLowException(const char *message);
		const char	*what() const throw();
	
	private:
		const char *_message;
};

/* ************************************************************************** */

std::ostream& operator<<(std::ostream& os, const Bureaucrat& srcs);

/* ************************************************************************** */

#endif
