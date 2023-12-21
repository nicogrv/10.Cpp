#ifndef ROBOTOMYREQUESTFORM
    #define ROBOTOMYREQUESTFORM  
    #include "./AForm.hpp"
    #include <ctime>

class AForm;

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm(std::string name);
        RobotomyRequestForm(RobotomyRequestForm &cpy);
        ~RobotomyRequestForm();
        RobotomyRequestForm &operator=(RobotomyRequestForm &cpy);
        
        void	execute(const Bureaucrat &executor) const;
        static AForm *NewForm(std::string name);

};

#endif