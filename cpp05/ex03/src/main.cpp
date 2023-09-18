#include "../Include/Bureaucrat.hpp"
#include "../Include/AForm.hpp"
#include "../Include/ShrubberyCreationForm.hpp"
#include "../Include/RobotomyRequestForm.hpp"
#include "../Include/PresidentialPardonForm.hpp"
#include "../Include/Intern.hpp"


int main()
{
    try
    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    }
    catch(const std::exception& e)
    {
        std::cout << "\n\nERROR\t" << e.what() << '\n';
    }

    
    

}