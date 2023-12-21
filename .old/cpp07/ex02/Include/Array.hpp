#include <iostream>

class limiteTab : public std::exception 
{
	public:
		limiteTab(const char *error) : _error(error) {} // Definition for the constructor
		const char* what() const throw() {
			return _error;
		}

	private:
		const char *_error;
};

template <typename T>
class Array
{
	public:

		Array<T>() {
			std::cout << "New " << std::endl;
			this->value =  new T;
			this->length = 1;

		}
		Array<T>(unsigned int N) {
			std::cout << "New avec N" << std::endl;
			this->value =  new T[N];
			this->length = N;
			for (unsigned int i = 0; i < N; i++) {
				this->value[i] = 0;
			}
		}
		Array (const Array <T> &cpy) :  value(new T[cpy.length]), length(cpy.length){
			std::cout << "Cpy" << std::endl;
			for (unsigned int i = 0; i < this->length; i++) {
				this->value[i] = cpy.value[i];
			}
		}
		~Array<T>()
		{
			std::cout << "Delete" << std::endl;
			delete [] value;
		}
		Array	&operator=(const Array &cpy) {
			std::cout << "Egal" << std::endl;
			return cpy;
		}
		T& operator[](unsigned int index) {
			if (!(0 <= index && index < this->length))
				throw limiteTab("Index out of tab!");
        	return this->value[index];
    	}

	private:
		T *value;
		unsigned int length;
};