#ifndef CAT_HPP
	#define CAT_HPP
	#include "./Animal.hpp"
	#include "./Brain.hpp"


class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &src);
		Cat	&operator=(const Cat &src);
		~Cat();
		void makeSound() const;
		std::string getBrain(int index) const;
		void setBrain(std::string Ideas, int index);

	private:
		Brain *brain;

};



#endif