#include <iostream>


template < typename T, typename U, typename V >
void iter(T  list, U  length, V  fonction) {
	for (int i = 0; i < length; i++) {
		list[i] = fonction(list[i]);
	}
}