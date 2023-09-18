#include "../Include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm(name, 145, 137)
{
    std::cout << "New \"ShrubberyCreationForm\"" << name << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &cpy) : AForm(cpy.getName(), 145, 137)
{
    std::cout << "cpy \"ShrubberyCreationForm\"" << std::endl;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Delete \"ShrubberyCreationForm\"" << this->getName() << std::endl;
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &obj)
{
	(void)	obj;
	return (*this);
}


void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (this->getExecuteGrade() < executor.getGrade() )
        throw AForm::GradeTooLowException("The bureaucrat doesn't have the grade to execute\n");
    else if (!this->getSign())
        throw AForm::GradeTooLowException("The contract is not signed \n");

    std::string fileName = executor.getName().insert(executor.getName().length(), "_shrubbery");
    std::ofstream outFile(fileName.insert(0, "./").c_str());

outFile << "             /\\"<< std::endl;
outFile << "            <  >"<< std::endl;
outFile << "             \\/"<< std::endl;
outFile << "             /\\"<< std::endl;
outFile << "            /  \\"<< std::endl;
outFile << "           /++++\\"<< std::endl;
outFile << "          /  ()  \\"<< std::endl;
outFile << "          /      \\"<< std::endl;
outFile << "         /~`~`~`~`\\"<< std::endl;
outFile << "        /  ()  ()  \\"<< std::endl;
outFile << "        /          \\"<< std::endl;
outFile << "       /*&*&*&*&*&*&\\"<< std::endl;
outFile << "      /  ()  ()  ()  \\"<< std::endl;
outFile << "      /              \\"<< std::endl;
outFile << "     /++++++++++++++++\\"<< std::endl;
outFile << "    /  ()  ()  ()  ()  \\"<< std::endl;
outFile << "    /                  \\"<< std::endl;
outFile << "   /~`~`~`~`~`~`~`~`~`~`\\"<< std::endl;
outFile << "  /  ()  ()  ()  ()  ()  \\"<< std::endl;
outFile << "  /*&*&*&*&*&*&*&*&*&*&*&\\"<< std::endl;
outFile << " /                        \\"<< std::endl;
outFile << "/,.,.,.,.,.,.,.,.,.,.,.,.,.\\"<< std::endl;
outFile << "           |   |"<< std::endl;
outFile << "          |`````|"<< std::endl;
outFile << "          \\_____/"<< std::endl;
}


AForm *ShrubberyCreationForm::NewForm(std::string name)
{
    AForm *form;
    form = new ShrubberyCreationForm(name);
    std::cout << "New alloc \"ShrubberyCreationForm\"" << name << std::endl;
    return form;
}
