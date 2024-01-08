/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasgriveau <nicolasgriveau@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:36:54 by nicolasgriv       #+#    #+#             */
/*   Updated: 2024/01/08 17:57:22 by nicolasgriv      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
    #define AFORM_HPP
    #include <iostream>
    #include "Bureaucrat.hpp"

class Bureaucrat;

/* ************************************************************************** */

class AForm
{
	public:
		AForm();
		AForm(const AForm &copy);
		AForm    &operator=(const AForm &copy);
		virtual ~AForm() = 0;

		AForm(const std::string name, const int gardeForSign, const int gardeForExecute);

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

class AForm::GradeTooLowException : public std::exception 
{
	public:
		GradeTooLowException(const char *message);
		const char *what() const throw();
	private:
		const char *_message;
};

class AForm::GradeTooHighException : public std::exception 
{
	public:
		GradeTooHighException(const char *message);
		const char *what() const throw();
	private:
		const char *_message;
};

/* ************************************************************************** */

std::ostream& operator<<(std::ostream& os, const AForm& srcs);

#endif