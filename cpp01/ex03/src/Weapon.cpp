#include "../Include/main.hpp"

std::string& Weapon::getType()
{   
	return (this->type);
}

void	Weapon::setType( std::string name_type )
{
	this->type = name_type;
	return ;
}


Weapon::Weapon( std::string name )
{
	this->type = name;
	return ;
}

Weapon::Weapon( void )
{
	// this->type = name;
	return ;
}
Weapon::~Weapon( void )
{
	// this->type = name;
	return ;
}