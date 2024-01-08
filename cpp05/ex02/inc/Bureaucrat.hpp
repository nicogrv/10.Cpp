/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasgriveau <nicolasgriveau@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:32:09 by ngriveau          #+#    #+#             */
/*   Updated: 2024/01/08 17:50:38 by nicolasgriv      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
	#define BUREAUCRAT_HPP
	#include "./AForm.hpp"
	#include <iostream>
	#include <string>

class AForm;

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

		void		signForm(AForm &form);

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
