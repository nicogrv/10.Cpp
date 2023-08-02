#ifndef HUMANA_HPP
    #define HUMANA_HPP
    #include <iostream>
	#include "../Include/Weapon.hpp"

    class HumanA{
        public:
			HumanA( std::string name, Weapon& weapon);
			~HumanA();
			Weapon* weapon;
			void  attack();
            std::string name;
        private:
    };

#endif