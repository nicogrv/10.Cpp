#include "../Include/Bureaucrat.hpp"
#include "../Include/AForm.hpp"
#include "../Include/ShrubberyCreationForm.hpp"
#include "../Include/RobotomyRequestForm.hpp"
#include "../Include/PresidentialPardonForm.hpp"


int main()
{
    try
    {
        Bureaucrat Bob("Bob", 1);
        ShrubberyCreationForm Test("Arbre");
        std::cout << Test;
        Bob.signForm(Test);
        std::cout << Test;
        Test.execute(Bob);
        RobotomyRequestForm Robot("bip");
        // Robot.execute(Bob);
        Robot.beSigned(Bob);
        Robot.execute(Bob);

        PresidentialPardonForm Pardon("Chaps");
        // Pardon.execute(Bob);
        std::cout << Pardon;
        Pardon.beSigned(Bob);
        Pardon.execute(Bob);
        std::cout << Pardon;

        Bob.executeForm(Pardon);


        Bureaucrat Tim("Bob", 1);
        RobotomyRequestForm Bot("TOK");
        Tim.signForm(Bot);
        Tim.executeForm(Bot);
        Bot.execute(Tim);

    }
    catch(const std::exception& e)
    {
        std::cout << "\n\nERROR\t" << e.what() << '\n';
    }

    
    

}