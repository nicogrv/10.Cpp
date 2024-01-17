/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:36:54 by nicolasgriv       #+#    #+#             */
/*   Updated: 2024/01/17 14:23:20 by ngriveau         ###   ########.fr       */
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
		AForm(const std::string name, const int gardeForSign, const int gardeForExecute, const std::string target);

		void		beSigned(Bureaucrat &bureaucrat);
		void 		execute(const Bureaucrat &executor) const;

		std::string	getName() const;
		std::string	getTarget() const;
		bool		getSigned() const;
		int			getGardeForSign() const;
		int 		getGradeForExecute() const;

		class	GradeTooHighException;
		class	GradeTooLowException;

	
	private:
		const std::string	_name;
		const int			_gardeForSign;
		const int			_gardeForExecute;
		const std::string	_target; 
		bool				_signed;

		virtual void 		executeContract(const Bureaucrat &executor) const = 0;
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