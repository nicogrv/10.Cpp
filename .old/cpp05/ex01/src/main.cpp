#include "../Include/Bureaucrat.hpp"
#include "../Include/Form.hpp"


int main()
{
    Bureaucrat Bob("Bob", 5);
    ;
    try
    {
        Form Doc("Contract", 1, 1);
        // Form salut = Doc;

        Form salut();
        salut = Doc;
        // Form Doc("Contract", 10, 10);
        std::cout << "coucou " << salut;
        std::cout << Doc;
        Bob.signForm(Doc);
        std::cout << Doc;

    }
    catch(const std::exception& e)
    {
        std::cout << "ERROR\t" << e.what() << '\n';
    }

    
    

}