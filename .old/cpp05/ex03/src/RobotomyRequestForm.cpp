#include "../Include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm(name, 72, 45)
{
    std::cout << "New \"RobotomyRequestForm\"" << name << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &cpy) : AForm(cpy.getName(), 72, 45)
{
    std::cout << "cpy \"RobotomyRequestForm\"" << std::endl;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Delete \"RobotomyRequestForm\"" << this->getName() << std::endl;
}
RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &obj)
{
	(void)	obj;
	return (*this);
}


void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (this->getExecuteGrade() < executor.getGrade() )
        throw AForm::GradeTooLowException("The bureaucrat doesn't have the grade to execute\n");
    else if (!this->getSign())
        throw AForm::GradeTooLowException("The contract is not signed \n");
    int start_time = clock(); // Enregistrez le temps de début

    if (start_time % 2 == 0)
        std::cout << "BIZZ: " << executor.getName() << " a ete robotomisée" << std::endl;
    else
        std::cout << executor.getName() << " n'a pas ete robotomisée..." << std::endl;


}

AForm *RobotomyRequestForm::NewForm(std::string name)
{
    AForm *form;
    form = new RobotomyRequestForm(name);
    std::cout << "New alloc \"RobotomyRequestForm\"" << name << std::endl;
    return form;
}
