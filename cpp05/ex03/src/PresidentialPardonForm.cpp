#include "../Include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm(name, 25, 5)
{
    std::cout << "New \"PresidentialPardonForm\"" << name << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &cpy) : AForm(cpy.getName(), 25, 5)
{
    std::cout << "cpy \"PresidentialPardonForm\"" << std::endl;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "Delete \"PresidentialPardonForm\"" << this->getName() << std::endl;
}
PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &obj)
{
	(void)	obj;
	return (*this);
}   


void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (this->getExecuteGrade() < executor.getGrade() )
        throw AForm::GradeTooLowException("The bureaucrat doesn't have the grade to execute\n");
    else if (!this->getSign())
        throw AForm::GradeTooLowException("The contract is not signed \n");
    else
        std::cout << executor.getName() << " a été pardonnée par Zaphod Beeblebrox." << std::endl;

}