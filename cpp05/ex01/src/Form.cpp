#include "../Include/Form.hpp"

Form::Form(std::string name, int const signGrade, int const executeGrade)  : _name(name), _signGrade(signGrade), _executeGrade(executeGrade) 
{
    this->_sign = false;
    if (signGrade < 1)
        throw Form::GradeTooHighException("Error: signGrade is to high");
    else if (150 < signGrade)
        throw Form::GradeTooLowException("Error: signGrade is to low");
    else if (executeGrade < 1)
        throw Form::GradeTooHighException("Error: executeGrade is to high");
    else if (150 < executeGrade)
        throw Form::GradeTooLowException("Error: executeGrade is to low");
    
    std::cout << "New Form: " << this->_name << std::endl;
}

Form::Form(Form &cpy) :  _name(cpy.getName()), _signGrade(cpy.getSignGrade()), _executeGrade(cpy.getExecuteGrade())
{
    this->_sign = cpy._sign;
}
Form::~Form()
{
    std::cout << "Delete Form: " << this->_name << std::endl;
}
Form &Form::operator=(Form &cpy) 
{
    (void) cpy;
    return (*this);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (this->_signGrade < bureaucrat.getGrade())
        throw Form::GradeTooLowException("The bureaucrat doesn't have the grade to sign\n");
    this->_sign = true;
}


std::string const Form::getName() const
{return (this->_name);}

bool Form::getSign() const
{return (this->_sign);}

int Form::getSignGrade() const
{return (this->_signGrade);}

int Form::getExecuteGrade() const
{return (this->_executeGrade);}

std::ostream& operator<<(std::ostream& os, Form &cpy)
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

const char* Form::GradeTooHighException::what() const throw()
{
    return (this->_error);
}
Form::GradeTooHighException::GradeTooHighException(const char *error)
{
    this->_error = error;
}

// ================================================== // 


const char* Form::GradeTooLowException::what() const throw()
{
    return (this->_error);
}
Form::GradeTooLowException::GradeTooLowException(const char *error)
{
    this->_error = error;
}

