#include "../Include/MutantStack.hpp"

template <typename T>

MutantStack<T>::MutantStack() : std::stack<T>(){
	std::cout << "start" << std::endl;
}

// MutantStack::MutantStack<T>(MutantStack<T> const &cpy){
	
// }

// MutantStack::MutantStack<T>	&operator=(const MutantStack<T> &src){
	
// }
template <typename T>


MutantStack<T>::~MutantStack() {
	std::cout << "delete" << std::endl;
	
}
