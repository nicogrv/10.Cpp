#ifndef WRONGANIMAL_HPP
	#define WRONGANIMAL_HPP
	#include <iostream>


class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &src);
		WrongAnimal	&operator=(const WrongAnimal &src);
		~WrongAnimal();

		std::string getType() const;
		void		setType(std::string type);
		void		makeSound() const;

	protected:
		std::string type;

};

#endif