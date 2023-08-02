#include "../Include/Bureaucrat.hpp"
#include "../Include/Form.hpp"


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
        Form Doc("Contract", 150, 150);
        std::cout << Doc;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

}