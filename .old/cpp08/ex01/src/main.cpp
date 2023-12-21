#include "../Include/Span.hpp"
#include <cstdlib>
#include <ctime>
#include <vector>
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
		int size = 20;
		Span sp = Span(size);
		try {
			for (int i = 0; i < size; i++ ) {

				const int value = rand();
				sp.addNumber(value);
				// std::cout << value << std::endl;
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}


		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{

		Span sp = Span(5);
		try {
			std::vector<int> numbers;
			numbers.push_back(1);
			numbers.push_back(2);
			numbers.push_back(3);
			numbers.push_back(4);
			numbers.push_back(5);
			sp.addMultiNumber(numbers.begin(), numbers.end());
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
			std::cout << std::endl;
			sp.displayTab();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}


	}


	std::cout << std::endl << std::endl;

}