#include <iostream>
#include <vector>

template < typename T>

int easyfind(T & tab, int value) {
	std::vector<int>::iterator it = tab.begin();
	while (it != tab.end()) {
		if (*it == value)
			return *it;
		it++;
	}
	return -1;
}