#ifndef MUTANTSTACK
# define MUTANTSTACK
# include <iostream>

template < typename T>

class MutantStack : public std::stack
{
	private:
		/* data */
	public:
		MutantStack(/* args */);
		~MutantStack();
};

MutantStack::MutantStack(/* args */)
{
}

MutantStack::~MutantStack()
{
}

#endif