#ifndef FORM_HPP
    #define FORM_HPP
    #include <iostream>
    #include "./Bureaucrat.hpp"

class Form
{
    public:
        Form(std::string name, int const signGrade, int const executeGrade);
        Form(Form &cpy);
        ~Form();
        Form &operator=(Form &cpy);

        std::string const getName() const;
        bool getSign() const;
        int getSignGrade() const;
        int getExecuteGrade() const;

        void beSigned(Bureaucrat &bureaucrat);
        void signForm() const;

        class GradeTooHighException : public std::exception 
        {
            public:
                const char* what() const throw();
                GradeTooHighException(const char *error);
            private:
                const char *_error;

        };
        class GradeTooLowException : public std::exception 
        {
            public:
                const char* what() const throw();
                GradeTooLowException(const char *error);
            private:
                const char *_error;

        };
        


    private:
        std::string const _name;
        bool _sign;
        int const _signGrade;
        int const _executeGrade;

};

std::ostream& operator<<(std::ostream& os, Form &cpy);
#endif