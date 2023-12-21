#ifndef FORM_HPP
    #define FORM_HPP
    #include <iostream>
    #include "../Include/Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public:
        Form(std::string name, int const signGrade, int const executeGrade);
        Form(Form const &cpy);
        ~Form();
        Form &operator=(Form const &cpy);

        const std::string	getName() const;
        bool                getSign() const;
        int                 getSignGrade() const;
        int					getExecuteGrade() const;

        void				beSigned(Bureaucrat &bureaucrat);

		class				GradeTooHighException;
		class				GradeTooLowException;
		

    private:
        std::string const   _name;
        bool                _sign;
        int const           _signGrade;
        int const           _executeGrade;
};

class Form::GradeTooHighException : public std::exception 
{
	public:
		const char* what() const throw();
		GradeTooHighException(const char *error);
	private:
		const char *_error;
};

class Form::GradeTooLowException : public std::exception 
{
	public:
		const char* what() const throw();
		GradeTooLowException(const char *error);
	private:
		const char *_error;
};
        
std::ostream& operator<<(std::ostream& os, Form &cpy);

#endif