#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "L’adresse de la string en mémoire.\t" << &str << std::endl;
    std::cout << "L’adresse stockée dans stringPTR.\t" << stringPTR << std::endl;
    std::cout << "L’adresse stockée dans stringREF.\t" << &stringREF << std::endl;

    std::cout << std::endl;

    std::cout << "La valeur de la string.\t\t\t" << str << std::endl;
    std::cout << "La valeur pointée par stringPTR\t\t" << *stringPTR << std::endl;
    std::cout << "La valeur pointée par stringREF\t\t" << stringREF << std::endl;
    return (0);
}