#include "../Include/RobotomyRequestForm.hpp"

dRobotomyRequestForm::dRobotomyRequestForm(std::string name) : AForm(name, 72, 45)
{
    std::cout << "New \"dRobotomyRequestForm\"" << name << std::endl;
}
dRobotomyRequestForm::dRobotomyRequestForm(dRobotomyRequestForm &cpy) : AForm(cpy.getName(), 72, 45)
{
    std::cout << "cpy \"dRobotomyRequestForm\"" << std::endl;
}
dRobotomyRequestForm::~dRobotomyRequestForm()
{
    std::cout << "Delete \"dRobotomyRequestForm\"" << this->getName() << std::endl;
}
dRobotomyRequestForm &dRobotomyRequestForm::operator=(dRobotomyRequestForm &obj)
{
	(void)	obj;
	return (*this);
}


void	dRobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (this->getExecuteGrade() < executor.getGrade())
        throw AForm::GradeTooLowException("The bureaucrat doesn't have the grade to execute\n");
    clock_t start_time = clock(); // Enregistrez le temps de début

    // Placez ici le code que vous souhaitez chronométrer

    clock_t end_time = clock(); // Enregistrez le temps de fin
    double elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000.0; // Convertissez le temps en millisecondes

    std::cout << "Temps écoulé en millisecondes : " << elapsed_time << " ms" << std::endl;

    return 0;


}