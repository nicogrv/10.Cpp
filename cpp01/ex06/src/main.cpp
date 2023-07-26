#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "../Include/Harl.hpp"

int main(int c, char **v) 
{
	if (c != 2)
	{
		std::cout << "Error" << std::endl;
		return (1);
	}
	Harl log;
	log.complain(v[1]);
	return (0);
}
