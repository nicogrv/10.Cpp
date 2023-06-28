#include "../Include/main.hpp"


void HumanA::attack() 
{
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	return ;
}

HumanA::HumanA( std::string name, Weapon& weapon)
{
	this->name = name; 
	this->weapon = &weapon;
}

HumanA::~HumanA( void )
{
	return ;
}

