#ifndef WrongCAT_HPP
	#define WrongCAT_HPP
	#include "./WrongAnimal.hpp"


class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat &src);
		WrongCat	&operator=(const WrongCat &src);
		~WrongCat();
		void makeSound() const;

};



#endif