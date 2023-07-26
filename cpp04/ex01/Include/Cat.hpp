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
		virtual ~Cat();


		std::string getType() const;
		void		setType(std::string type);
		virtual void		makeSound() const;

	protected:
		std::string type;
		Brain *cerv;

};



#endif