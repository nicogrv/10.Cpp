#include "../Include/FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_name = name;
    this->_hitPoints = 100;
    this->_energiePoints = 100;
    this->_attackDamage = 30;
    std::cout << "FLAG " << name << " build !" << std::endl;
}

FragTrap::FragTrap(FragTrap const &cpy) : ClapTrap(cpy)
{
    this->_name = cpy._name;
    this->_hitPoints = cpy._hitPoints;
    this->_energiePoints = cpy._energiePoints;
    this->_attackDamage = cpy._attackDamage;
    std::cout << "FLAG " << this->_name << " cpy build !" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FLAG " << this->_name << " destroy !" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::string test;

    std::cout << "high fives ? ";
    if (!std::getline(std::cin, test))
			exit(0);
    std::cout << "HIGH FIVES " << this->_name << " !" << std::endl;
    
}
