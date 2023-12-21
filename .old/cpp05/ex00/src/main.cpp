#include "../Include/Bureaucrat.hpp"

int main()
{
    Bureaucrat Bob("Bob", 1);
    Bureaucrat titou = Bob;
    std::cout << "bob " << Bob.getName() << " " << Bob.getGrade() << std::endl;
    std::cout << "titou " << titou.getName() << " " << titou.getGrade() <<  std::endl;
    try
    {
        Bureaucrat Tim("Tim", 0);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    try
    {
        Bob.decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    Bureaucrat Noe("Noe", 149);

    try
    {
        Noe.decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    try
    {
        Noe.decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    std::cout << Noe;
    


}