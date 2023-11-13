#include "../Include/Span.hpp"
#include <cstdlib>
#include <ctime>
int main()
{
    srand(time(NULL));
	{

		Span sp = Span(5);
		try {
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}


		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}


	std::cout << std::endl << std::endl;

	{
		int size = 20000;
		Span sp = Span(size);
		try {
			for (int i = 0; i < size; i++ ) {

				const int value = rand();
				sp.addNumber(value);
				std::cout << value << std::endl;
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}


		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}


}