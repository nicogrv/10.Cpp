#include "../Include/main.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
		Weapon ak = Weapon("AK47");
		jim.setWeapon(ak);
		jim.attack();
		ak.setType("FAMAS");
		jim.attack();

	}
	return 0;
}