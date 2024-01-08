/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasgriveau <nicolasgriveau@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:36:54 by nicolasgriv       #+#    #+#             */
/*   Updated: 2024/01/08 17:18:10 by nicolasgriv      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
    #define FORM_HPP
    #include <iostream>
    #include "Bureaucrat.hpp"

class Bureaucrat;

/* ************************************************************************** */

class Form
{
	public:
		Form();
		Form(const Form &copy);
		~Form();
		Form    &operator=(const Form &copy);

		Form(const std::string name, const int gardeForSign, const int gardeForExecute);

		void		beSigned(Bureaucrat &bureaucrat);

		std::string	getName() const;
		bool		getSigned() const;
		int			getGardeForSign() const;
		int 		getGradeForExecute() const;

		class	GradeTooHighException;
		class	GradeTooLowException;

	private:
		const std::string	_name;
		bool				_signed;
		const int			_gardeForSign;
		const int			_gardeForExecute;

};

/* ************************************************************************** */

class Form::GradeTooLowException : public std::exception 
{
	public:
		GradeTooLowException(const char *message);
		const char *what() const throw();
	private:
		const char *_message;
};

class Form::GradeTooHighException : public std::exception 
{
	public:
		GradeTooHighException(const char *message);
		const char *what() const throw();
	private:
		const char *_message;
};

/* ************************************************************************** */

std::ostream& operator<<(std::ostream& os, const Form& srcs);

#endif