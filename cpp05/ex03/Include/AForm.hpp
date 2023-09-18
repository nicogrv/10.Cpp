#ifndef AForm_HPP
    #define AForm_HPP
    #include <iostream>
    #include "./Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    public:
        AForm(std::string name, int const signGrade, int const executeGrade);
        AForm(AForm &cpy);
        virtual ~AForm();
        AForm &operator=(AForm &cpy);

        std::string const getName() const;
        bool getSign() const;
        int getSignGrade() const;
        int getExecuteGrade() const;

        void beSigned(Bureaucrat &bureaucrat);
        // virtual AForm *NewForm(std::string name) = 0;
        virtual void	execute(const Bureaucrat &executor) const = 0;
        
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

std::ostream& operator<<(std::ostream& os, AForm &cpy);
#endif