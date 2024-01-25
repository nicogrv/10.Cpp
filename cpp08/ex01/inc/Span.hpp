#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <math.h>
# include <climits>
# include <vector>

class Span {

	public:
		Span();
		~Span();
		Span(const Span &copy);
		Span &operator=(const Span &copy);

		Span(unsigned long N);

		void addNumber(int number);
		int shortestSpan();
		int longestSpan();

		unsigned long getLenght();
		void printTab();
	
	private:
		const unsigned long	_lenght;
		std::vector<int>	_vec;
		
};

#endif