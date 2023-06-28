#include "../Include/Harl.hpp"

void Harl::debug() 
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "Debug: I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
}

void Harl::info()
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void Harl::warning()
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
}


void Harl::complain( std::string level )
{
	std::string option[4];
	int i;
	
	option[0] = "debug";
	option[1] = "info";
	option[2] = "warning";
	option[3] = "error";

	i = -1;
	while (++i < 4)
	{
		if (level.compare(option[i]) == 0)
			break ;
	}
	switch (i)
	{
		case 0:
			this->debug();
			this->info();
			this->warning();
			this->error();
			break;
		case 1:
			this->info();
			this->warning();
			this->error();

			break;
		case 2:
			this->warning();
			this->error();
			break;
		case 3:
			this->error();
			break;
		default:
			std::cout << "Invalide Level (debug / info / warning / error)" << std::endl;
	}
	
}
