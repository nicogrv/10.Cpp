/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:29:50 by ngriveau          #+#    #+#             */
/*   Updated: 2024/01/16 18:47:40 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Damien")
{
	this->_grade = 42;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name)
{
	*this = copy;
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
	this->_grade = copy._grade;	
	return *this;
}

/* ************************************************************************** */

Bureaucrat::Bureaucrat(std::string name) : _name(name)
{
	this->_grade = 42;  
}

Bureaucrat::Bureaucrat(int grade) : _name("Damien")
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException("Grade is too High !");
	else if (150 < grade)
		throw Bureaucrat::GradeTooLowException("Grade is too Low !");
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException("Grade is too High !");
	else if (150 < grade)
		throw Bureaucrat::GradeTooLowException("Grade is too Low !");
	else 
		this->_grade = grade;	
}

/* ************************************************************************** */

void		Bureaucrat::increment()
{
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException("Grade is too High !");
	else
		this->_grade -= 1;
}

void		Bureaucrat::decrement()
{
	if (150 <= this->_grade)
		throw Bureaucrat::GradeTooLowException("Grade is too Low !");
	else
		this->_grade += 1;
}

std::string	Bureaucrat::getName() const
{
	return this->_name;
}

int			Bureaucrat::getGrade() const
{
	return this->_grade;
}

void		Bureaucrat::signForm(AForm &form)
{
	try 
	{
		form.beSigned(*this);
	}
	catch (std::exception &e)
	{
		throw;
	}
}

void		Bureaucrat::executeForm(const AForm &form)
{
	try 
	{
		form.execute(*this);
	}
	catch (std::exception &e)
	{
		throw ;
	}		
}


/* ************************************************************************** */
		
Bureaucrat::GradeTooLowException::GradeTooLowException(const char *message) : _message(message)
{}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return this->_message;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const char *message) : _message(message) 
{}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return this->_message;
}

/* ************************************************************************** */

std::ostream& operator<<(std::ostream& os, const Bureaucrat& srcs)
{
	os << srcs.getName() << ", bureaucrat grade " << srcs.getGrade() << std::endl;
	return os;
}