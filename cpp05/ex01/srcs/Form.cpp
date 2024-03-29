/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:13:16 by nicolasgriv       #+#    #+#             */
/*   Updated: 2024/01/17 15:12:01 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

Form::Form() : _name("Contract"), _gardeForSign(100), _gardeForExecute(50)
{
    this->_signed = false;
}

Form::Form(const Form &copy) : _name(copy._name), _gardeForSign(copy._gardeForSign), _gardeForExecute(copy._gardeForExecute)
{
    *this = copy;
}

Form::~Form()
{}

Form    &Form::operator=(const Form &copy)
{
    this->_signed = copy._signed;
    return *this;
}

/* ************************************************************************** */

Form::Form(const std::string name, const int gardeForSign, const int gardeForExecute) : _name(name), _gardeForSign(gardeForSign), _gardeForExecute(gardeForExecute)
{
    this->_signed = false;
}

/* ************************************************************************** */

std::string	Form::getName() const 
{   return this->_name;}

bool		Form::getSigned() const 
{   return this->_signed;}

int			Form::getGardeForSign() const 
{   return this->_gardeForSign;}

int 		Form::getGradeForExecute() const 
{   return this->_gardeForExecute;}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= this->getGardeForSign() && !this->_signed)
    {
        std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
        this->_signed = true;
    }
    else if (this->_signed) 
    {
        std::cout << bureaucrat.getName() << " couldn t sign " << this->getName() << " because already sign" << std::endl;
        throw Form::GradeTooLowException("Already sign");
    }
    else
    {
        std::cout << bureaucrat.getName() << " couldn t sign " << this->getName() << " because grade is to low for sign this form" << std::endl;
        throw Form::GradeTooLowException("Grade is to low for sign this form");
    }
}

/* ************************************************************************** */

Form::GradeTooLowException::GradeTooLowException(const char *message) : _message(message)
{}

const char *Form::GradeTooLowException::what() const throw() {
    return this->_message;
}

Form::GradeTooHighException::GradeTooHighException(const char *message)  : _message(message)
{}

const char *Form::GradeTooHighException::what() const throw() {
    return this->_message;
}

/* ************************************************************************** */

std::ostream& operator<<(std::ostream& os, const Form& srcs)
{
    os << "Form: " << srcs.getName() << " (Signed: " << srcs.getSigned() \
    << ") Need " << srcs.getGardeForSign() << " for sign and " << srcs.getGradeForExecute() \
    << " for exeute";
    return os;
}
