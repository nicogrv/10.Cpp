#ifndef MUTANTSTACK
# define MUTANTSTACK
# include <iostream>
# include <stack>
# include <list>
template < typename T>

class MutantStack : public std::stack<T>
{

	public:
		MutantStack<T>();
		MutantStack<T>(MutantStack<T> const &cpy);
		MutantStack<T>	&operator=(const MutantStack<T> &src);
		~MutantStack<T>();

};


#endif