/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngriveau <ngriveau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:13:16 by nicolasgriv       #+#    #+#             */
/*   Updated: 2024/01/17 16:03:01 by ngriveau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"

AForm::AForm() : _name("Contract"), _gardeForSign(100), _gardeForExecute(50), _target("target")
{
    this->_signed = false;
}

AForm::AForm(const AForm &copy) : _name(copy._name), _gardeForSign(copy._gardeForSign), _gardeForExecute(copy._gardeForExecute), _target("target")
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

AForm::AForm(const std::string name, const int gardeForSign, const int gardeForExecute) : _name(name), _gardeForSign(gardeForSign), _gardeForExecute(gardeForExecute), _target("target")
{
    this->_signed = false;
}

AForm::AForm(const std::string name, const int gardeForSign, const int gardeForExecute, const std::string target) : _name(name), _gardeForSign(gardeForSign), _gardeForExecute(gardeForExecute), _target(target)
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

std::string AForm::getTarget() const 
{   return this->_target;}


void	AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= this->getGardeForSign() && !this->_signed)
    {
        std::cout << bureaucrat.getName() << " signed " << this->getName() << std::endl;
        this->_signed = true;
    }
    else if (this->_signed) 
    {
        std::cout << bureaucrat.getName() << " couldn t sign " << this->getName() << " because already sign" << std::endl;
        throw AForm::GradeTooLowException("Already sign");
    }
    else
    {
        std::cout << bureaucrat.getName() << " couldn t sign " << this->getName() << " because grade is to low for sign this form" << std::endl;
        throw AForm::GradeTooLowException("Grade is to low for sign this form");
    }
}

void 		AForm::execute(const Bureaucrat &executor) const
{
    if (!this->getSigned()) {
        std::cout << executor.getName() << " not execute " << this->getName() << "Beacause form not sign" << std::endl;
        throw AForm::GradeTooLowException("Form not sign");
    }
    else if (this->getGradeForExecute() <= executor.getGrade())
    {
        std::cout << executor.getName() << " not execute " << this->getName() << "Beacause bureaucrat not have a grade for execute"  << std::endl;
        throw AForm::GradeTooLowException("Not have a grade for execute");
    }
    else
    {
        try
        {
            this->executeContract(executor);
        }
        catch (std::exception &e)
        {
            throw;
        }
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
    os << "Form: " << srcs.getName() << " target: " << srcs.getTarget() <<  " (Signed: " << srcs.getSigned() \
    << ") Need " << srcs.getGardeForSign() << " for sign and " << srcs.getGradeForExecute() \
    << " for exeute";
    return os;
}
