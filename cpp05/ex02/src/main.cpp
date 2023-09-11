#include "../Include/Bureaucrat.hpp"
#include "../Include/AForm.hpp"
#include "../Include/ShrubberyCreationForm.hpp"


int main()
{
    Bureaucrat Bob("Bob", 5);
    try
    {
        // AForm Doc("Contract", 1, 1);
        // AForm Doc("Contract", 10, 10);
        ShrubberyCreationForm Test("Arbre");
        // std::cout << Doc;
        // Bob.signForm(Doc);
        // std::cout << Doc;

    }
    catch(const std::exception& e)
    {
        std::cout << "\n\nERROR\t" << e.what() << '\n';
    }

    
    

}