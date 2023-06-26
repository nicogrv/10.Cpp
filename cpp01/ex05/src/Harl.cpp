#include "../Include/Harl.hpp"

void Harl::debug() 
{
	std::cout << "Debug: I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}


void Harl::complain( std::string level )
{
	std::string option[4];
	void        (Harl::*ft[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int i;
	
	option[0] = "debug";
	option[1] = "info";
	option[2] = "warning";
	option[3] = "error";

	i = -1;
	while (++i < 4)
	{
		if (level.compare(option[i]) == 0)
			return ((this->*ft[i])());
	}
	std::cout << "Invalide Level (debug / info / warning / error)" << std::endl;
}
