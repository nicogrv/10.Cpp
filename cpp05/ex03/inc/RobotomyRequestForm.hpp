#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP 
# include "./AForm.hpp"
# include <iostream>
# include<cstdlib>


class RobotomyRequestForm : public AForm
{

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        ~RobotomyRequestForm();
        RobotomyRequestForm   &operator=(const RobotomyRequestForm &copy);

        RobotomyRequestForm(std::string target);

    private:
        void 		executeContract(const Bureaucrat &executor) const;
};



#endif