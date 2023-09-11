#include "../Include/AForm.hpp"

AForm::AForm(std::string name, int const signGrade, int const executeGrade)  : _name(name), _signGrade(signGrade), _executeGrade(executeGrade) 
{
    this->_sign = false;
    if (signGrade < 1)
        throw AForm::GradeTooHighException("Error: signGrade is to high");
    else if (150 < signGrade)
        throw AForm::GradeTooLowException("Error: signGrade is to low");
    else if (executeGrade < 1)
        throw AForm::GradeTooHighException("Error: executeGrade is to high");
    else if (150 < executeGrade)
        throw AForm::GradeTooLowException("Error: executeGrade is to low");
    
    std::cout << "New AForm: " << this->_name << std::endl;
}

AForm::AForm(AForm &cpy) :  _name(cpy.getName()), _signGrade(cpy.getSignGrade()), _executeGrade(cpy.getExecuteGrade())
{
    this->_sign = cpy._sign;
}
AForm::~AForm()
{
    std::cout << "Delete AForm: " << this->_name << std::endl;
}
AForm &AForm::operator=(AForm &cpy) 
{
    (void) cpy;
    return (*this);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (this->_signGrade < bureaucrat.getGrade())
        throw AForm::GradeTooLowException("The bureaucrat doesn't have the grade to sign\n");
    this->_sign = true;
    std::cout << bureaucrat.getName() << " Signe " << this->getName() << std::endl;
}


std::string const AForm::getName() const
{return (this->_name);}

bool AForm::getSign() const
{return (this->_sign);}

int AForm::getSignGrade() const
{return (this->_signGrade);}

int AForm::getExecuteGrade() const
{return (this->_executeGrade);}


std::ostream& operator<<(std::ostream& os, AForm &cpy)
{
    os << cpy.getName() << "Sign -> ";
    if (cpy.getSign())
        std::cout << "TRUE";
    else
        std::cout << "FALSE";
    std::cout << ". Can be signed by grade: " << cpy.getSignGrade() << ". Can be signed by grade: " << cpy.getExecuteGrade() << std::endl;
    return (os);
}

// ================================================== // 

const char* AForm::GradeTooHighException::what() const throw()
{
    return (this->_error);
}
AForm::GradeTooHighException::GradeTooHighException(const char *error)
{
    this->_error = error;
}

// ================================================== // 


const char* AForm::GradeTooLowException::what() const throw()
{
    return (this->_error);
}
AForm::GradeTooLowException::GradeTooLowException(const char *error)
{
    this->_error = error;
}

