#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <math.h>
# include <climits>
# include <vector>
# include <deque>

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

		template<typename T>
		void	addNumbers(typename T::iterator	begin, typename T::iterator	end)
		{
			unsigned int sizeOfAdd = 0;
			typename T::iterator	it = begin;

			while (it != end)
			{
				sizeOfAdd++;
				it++;
			}
			if (this->_lenght - this->_vec.size() < sizeOfAdd)
				throw std::runtime_error("can't add numbers: not enough space");
			while (begin != end)
			{
				this->_vec.push_back(*begin);
				begin++;
			}
		}
	
	private:
		const unsigned long	_lenght;
		std::vector<int>	_vec;
		
};

#endif