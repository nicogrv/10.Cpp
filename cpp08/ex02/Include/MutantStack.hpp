#ifndef MUTANTSTACK
# define MUTANTSTACK
# include <iostream>

template < typename T>

class MutantStack : public std::stack
{

	public:
		MutantStack<T>();
		~MutantStack<T>();

		private:
};


#endif