#include "../Include/Bureaucrat.hpp"
#include "../Include/AForm.hpp"
#include "../Include/ShrubberyCreationForm.hpp"
// #include "../Include/RobotomyRequestForm.hpp"


int main()
{
    try
    {
        Bureaucrat Bob("Bob", 1);
        ShrubberyCreationForm Test("Arbre");
        std::cout << Test;
        Bob.signForm(Test);
        std::cout << Test;
        // RobotomyRequestForm Robot("bip");
        Test.execute(Bob);

    }
    catch(const std::exception& e)
    {
        std::cout << "\n\nERROR\t" << e.what() << '\n';
    }

    
    

}