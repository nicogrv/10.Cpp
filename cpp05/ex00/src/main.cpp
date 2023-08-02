#include "../Include/Bureaucrat.hpp"

int main()
{
    Bureaucrat Bob("Bob", 1);
    try
    {
        Bureaucrat Tim("Tim", 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bob.decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    Bureaucrat Noe("Noe", 149);

    try
    {
        Noe.decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Noe.decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << Noe;
    


}