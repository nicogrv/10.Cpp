#include "../Include/ClapTrap.hpp"


ClapTrap::ClapTrap(std::string name)
{
    this->_hitPoints = 10;
    this->_energiePoints = 10;
    this->_attackDamage = 0;
    this->_name = name;
    std::cout << name << " build !" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &cpy)
{
    this->_hitPoints = cpy._hitPoints;
    this->_energiePoints = cpy._energiePoints;
    this->_attackDamage = cpy._attackDamage;
    this->_name = cpy._name;
    std::cout << cpy._name << " copy build !" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &src)
{
    this->_hitPoints = src._hitPoints;
    this->_energiePoints = src._energiePoints;
    this->_attackDamage = src._attackDamage;
    std::cout << "ClapTrap " << this->_name << " =  " << src._name << std::endl;
    return (*this);
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->_name << " destroy !" << std::endl;
    return ;
}


void ClapTrap::attack(const std::string& target)
{
    if (this->_hitPoints && this->_energiePoints)
    {
        this->_energiePoints--;
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage! (Energie = " << this->_energiePoints << ")" << std::endl;
    }
    else 
    {
        if (!this->_hitPoints)
            std::cout << "Not enough life" << std::endl;
        else
            std::cout << "Not enough energie" << std::endl;
    }
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount > this->_hitPoints)
        this->_hitPoints = 0;
    else
        this->_hitPoints -= amount;
    std::cout << "ClapTrap " << this->_name << " take  "<< amount << " damage (" << this->_hitPoints << " hp)" << std::endl;

}
void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hitPoints && this->_energiePoints)
    {
        this->_hitPoints += amount;
        this->_energiePoints--;
        std::cout << "ClapTrap recovers " << amount << " points of life (Energie = " << this->_energiePoints << ")" << std::endl;
    }
    else 
    {
        if (!this->_hitPoints)
            std::cout << "Not enough life" << std::endl;
        else
            std::cout << "Not enough energie" << std::endl;
    }
}
// 