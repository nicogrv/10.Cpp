#include "../Include/main.hpp"


void HumanB::attack() 
{
	if (this->weapon == NULL)
		std::cout << this->name << " Dont have a weapon for attacks" << std::endl;	
	else
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	return ;
}

HumanB::HumanB( std::string name)
{
	this->weapon = NULL;
	this->name = name;
}
void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

HumanB::~HumanB( void )
{
	return ;
}