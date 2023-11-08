#include <iostream>


template < typename T, typename U, typename V >
void iter(T  list, U  lenght, V  fonction) {
	for (int i = 0; i < lenght; i++) {
		list[i] = fonction(list[i]);
	}
}