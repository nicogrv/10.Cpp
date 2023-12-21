/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasgriveau <nicolasgriveau@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:13:16 by nicolasgriv       #+#    #+#             */
/*   Updated: 2023/12/21 19:15:25 by nicolasgriv      ###   ########.fr       */
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
    if (bureaucrat.getGrade() <= this->getGardeForSign())
    {
        std::cout << this->getName() << " has sign" << std::endl;
        this->_signed = true;
    }
    else
    {
        throw Form::GradeTooLowException("Grade is to low for sign this form");
    }
}

/* ************************************************************************** */

Form::GradeTooLowException::GradeTooLowException(char *message) : _message(message)
{}

Form::GradeTooHighException::GradeTooHighException(char *message)  : _message(message)
{}

/* ************************************************************************** */

std::ostream& operator<<(std::ostream& os, const Form& srcs)
{
    os << "Form: " << srcs.getName() << "(Signed: " << srcs.getSigned() \
    << ") Need " << srcs.getGardeForSign() << "for sign and " << srcs.getGardeForSign() \
    << "for exeute";
    return os;
}
