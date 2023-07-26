#include "../Include/ScavTrap.hpp"


ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_name = name;
    this->_hitPoints = 100;
    this->_energiePoints = 50;
    this->_attackDamage = 20;
    std::cout << "SCAV " << name << " build !" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &cpy) : ClapTrap(cpy)
{
    this->_name = cpy._name;
    this->_hitPoints = cpy._hitPoints;
    this->_energiePoints = cpy._energiePoints;
    this->_attackDamage = cpy._attackDamage;
    std::cout << "SCAV " << this->_name << " cpy build !" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "SCAV " << this->_name << " destroy !" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "SCAV " << this->_name << " MODE GATE KEEPER" << std::endl;

}

void ScavTrap::attack(const std::string& target)
{
    if (this->_hitPoints && this->_energiePoints)
    {
        this->_energiePoints--;
        std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage! (Energie = " << this->_energiePoints << ")" << std::endl;
    }
    else 
    {
        if (!this->_hitPoints)
            std::cout << "Not enough life" << std::endl;
        else
            std::cout << "Not enough energie" << std::endl;
    }
}

