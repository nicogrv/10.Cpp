#ifndef WrongCAT_HPP
	#define WrongCAT_HPP
	#include "./WrongAnimal.hpp"


class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat &src);
		WrongCat	&operator=(const WrongCat &src);
		virtual ~WrongCat();


		std::string getType() const;
		void		setType(std::string type);
		void		makeSound() const;

	protected:
		std::string type;

};



#endif