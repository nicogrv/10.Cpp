#ifndef BUREAUCRAT_HPP
    #define BUREAUCRAT_HPP
    #include <stdexcept>
    #include <iostream>
    #include "./Form.hpp"

class Form;

class Bureaucrat
{

    public:
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat const &cpy);
        ~Bureaucrat();
        Bureaucrat &operator=(Bureaucrat const &cpy);

        std::string	getName() const;
        int 		getGrade() const;

        void incrementGrade();
        void decrementGrade();

        void signForm(Form &form);

        class GradeTooHighException;
        class GradeTooLowException;
        
    private:
        const std::string	_name;
        int					_grade;
};

class Bureaucrat::GradeTooHighException : public std::exception 
{
    public:
        const char* what() const throw();
        GradeTooHighException(const char *error);
    private:
        const char *_error;
};

class Bureaucrat::GradeTooLowException : public std::exception 
{
    public:
        const char* what() const throw();
        GradeTooLowException(const char *error);
    private:
        const char *_error;
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const &cpy);


#endif 