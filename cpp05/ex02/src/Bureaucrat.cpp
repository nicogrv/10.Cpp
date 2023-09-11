#include "../Include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade)
{
    this->_name = name;
        if (grade < 1)
            throw Bureaucrat::GradeTooHighException("Error: The grade is too high\n");
        else if (150 < grade)
            throw Bureaucrat::GradeTooLowException("Error: The grade is too low\n");
        else
            this->_grade = grade;
    std::cout << "New Bureaucrat: " << this->_name << "(" << this->_grade << ")" << std::endl;
}
Bureaucrat::Bureaucrat(Bureaucrat &cpy)
{
    *this = cpy;
    std::cout << "Bureaucrat Cpy" << std::endl;
}   
Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destroy" << std::endl;
}
Bureaucrat &Bureaucrat::operator=(Bureaucrat &cpy)
{
    this->_grade = cpy._grade;
    this->_name = cpy._name;
    std::cout << "Bureaucrat ==" << std::endl;
    return (*this);
}
std::ostream& operator<<(std::ostream& os, Bureaucrat &cpy)
{
    os << cpy.getName() << ", brueaucrat garde " << cpy.getGrade() << std::endl;
    return (os);
}


std::string Bureaucrat::getName() const
{
    return (this->_name);
}
int Bureaucrat::getGrade() const
{
    return (this->_grade);
}
void Bureaucrat::decrementGrade()
{
    if (this->_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException("Error: The grade is too low\n");
    this->_grade++;
    std::cout << "(-) new grade: " << this->_grade << std::endl;
}
void Bureaucrat::incrementGrade() 
{
    if (this->_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException("Error: The grade is too hight\n");
    this->_grade--;
    std::cout << "(+) new grade: " << this->_grade << std::endl;
}

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
    }
    catch(const std::exception& e)
    {
        std::cout << this->_name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
    
}

void Bureaucrat::executeForm(AForm &form)
{
    if (this->getGrade() > form.getExecuteGrade())
        throw Bureaucrat::GradeTooLowException("Error: The grade is too hight\n");
    else if (!form.getSign())
        throw Bureaucrat::GradeTooLowException("The contract is not signed \n");
    else
        try
        {
            form.execute(*this);
        }
        catch(const std::exception& e)
        {
            std::cout << "\nERROR " << e.what() << '\n';
        }
}





// ================================================== // 


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return (this->_error);
}
Bureaucrat::GradeTooHighException::GradeTooHighException(const char *error)
{
    this->_error = error;
}

// ================================================== // 


const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return (this->_error);
}
Bureaucrat::GradeTooLowException::GradeTooLowException(const char *error)
{
    this->_error = error;
}

