#ifndef HUMANB_HPP
    #define HUMANB_HPP
    #include <iostream>
	#include "../Include/Weapon.hpp"

    class HumanB{
        public:
			HumanB( std::string name);
			~HumanB();
            void	setWeapon(Weapon weapon);
			Weapon	weapon;
			void 	attack();
        private:
            std::string name;
    };

#endif