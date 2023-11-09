#include <iostream>

template <typename T>

class Array
{
	public:
		Array();
		Array(unsigned int N);
		Array(const Array &cpy);
		~Array();
		Array	&operator=(const Array &cpy);
	private:
		T *value;
		unsigned int *lenght;
};