#ifndef ZOMBIE_HPP
    #define ZOMBIE_HPP
    #include <iostream>

class   Zombie{
	public:
		Zombie();
		~Zombie();
		void	give_name( std::string name);

	private:
		std::string	name;
};

Zombie* zombieHorde( int N, std::string name );

#endif