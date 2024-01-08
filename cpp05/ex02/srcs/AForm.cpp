/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasgriveau <nicolasgriveau@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:13:16 by nicolasgriv       #+#    #+#             */
/*   Updated: 2024/01/08 17:47:31 by nicolasgriv      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

AForm::AForm() : _name("Contract"), _gardeForSign(100), _gardeForExecute(50)
{
    this->_signed = false;
}

AForm::AForm(const AForm &copy) : _name(copy._name), _gardeForSign(copy._gardeForSign), _gardeForExecute(copy._gardeForExecute)
{
    *this = copy;
}

AForm::~AForm()
{}

AForm    &AForm::operator=(const AForm &copy)
{
    this->_signed = copy._signed;
    return *this;
}

/* ************************************************************************** */

AForm::AForm(const std::string name, const int gardeForSign, const int gardeForExecute) : _name(name), _gardeForSign(gardeForSign), _gardeForExecute(gardeForExecute)
{
    this->_signed = false;
}

/* ************************************************************************** */

std::string	AForm::getName() const 
{   return this->_name;}

bool		AForm::getSigned() const 
{   return this->_signed;}

int			AForm::getGardeForSign() const 
{   return this->_gardeForSign;}

int 		AForm::getGradeForExecute() const 
{   return this->_gardeForExecute;}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= this->getGardeForSign() && !this->_signed)
    {
        std::cout << this->getName() << " has sign by " << bureaucrat.getName()<< std::endl;
        this->_signed = true;
    }
    else if (this->_signed) 
    {
        throw AForm::GradeTooLowException("Already sign");
    }
    else
    {
        throw AForm::GradeTooLowException("Grade is to low for sign this Aform");
    }
}

/* ************************************************************************** */

AForm::GradeTooLowException::GradeTooLowException(const char *message) : _message(message)
{}

const char *AForm::GradeTooLowException::what() const throw() {
    return this->_message;
}

AForm::GradeTooHighException::GradeTooHighException(const char *message)  : _message(message)
{}

const char *AForm::GradeTooHighException::what() const throw() {
    return this->_message;
}

/* ************************************************************************** */

std::ostream& operator<<(std::ostream& os, const AForm& srcs)
{
    os << "Form: " << srcs.getName() << " (Signed: " << srcs.getSigned() \
    << ") Need " << srcs.getGardeForSign() << " for sign and " << srcs.getGradeForExecute() \
    << " for exeute";
    return os;
}
