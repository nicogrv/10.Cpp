#ifndef BUREAUCRAT_HPP
    #define BUREAUCRAT_HPP
    #include <stdexcept>
    #include <iostream>
    #include "./AForm.hpp"

class AForm;

class Bureaucrat
{
    public:
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat &cpy);
        ~Bureaucrat();
        Bureaucrat &operator=(Bureaucrat &cpy);

        std::string getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();
        void executeForm(AForm & form); 
        void signForm(AForm &form);

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
        std::string _name;
        int _grade;

};

std::ostream& operator<<(std::ostream& os, Bureaucrat &cpy);


#endif 