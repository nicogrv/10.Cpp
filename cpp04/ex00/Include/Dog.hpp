#ifndef DOG_HPP
	#define DOG_HPP
	#include "./Animal.hpp"


class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &src);
		Dog	&operator=(const Dog &src);
		virtual ~Dog();


		std::string getType() const;
		void		setType(std::string type);
		virtual void		makeSound() const;

	protected:
		std::string type;

};



#endif