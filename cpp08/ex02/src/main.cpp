#include "../Include/MutantStack.hpp"
#include "MutantStack.tpp"


#include <iostream> 
#include <stack>
#include <list>
#include <list>
int main()
{
	// std::stack<int> stack;
	// std::list<int> list;
	// stack.push(1);
	// stack.push(2);
	// stack.push(3);
	// stack.push(4);
	// std::cout << list.end();
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << std::begin(mstack);
	// std::iterator it = mstack.begin();
	// MutantStack<int>::iterator ite = mstack.end();
	// ++it;
	// --it;
	// while (it != ite)
	// {
	// std::cout << *it << std::endl;
	// ++it;
	// }
	// std::stack<int> s(mstack);
	// return 0
}