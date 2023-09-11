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
ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &cpy)
{
    (void) cpy;
    return (*this);
}