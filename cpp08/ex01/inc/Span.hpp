#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <math.h>
# include <climits>
# include <vector>
# include <deque>
# include <algorithm>

class Span {

	public:
		Span();
		~Span();
		Span(const Span &copy);
		Span &operator=(const Span &copy);

		Span(unsigned long N);

		void addNumber(int number);
		long long shortestSpan();
		long long longestSpan();

		unsigned long getLenght();
		void printTab();

		template<typename T>
		void	addNumbers(typename T::iterator	begin, typename T::iterator	end)
		{
			std::cout << this->_lenght << " : " << this->_vec.size() << " : " << this->_lenght -  this->_vec.size()<< " : "  <<  std::distance(begin, end) << std::endl;
			if ((static_cast<unsigned int>(this->_lenght - this->_vec.size()) < std::distance(begin, end)))
				throw std::runtime_error("can't add numbers: not enough space");
			for(;begin != end; begin++)
			{
				try
				{
					this->addNumber(*begin);
				}
				catch (...)
				{
					throw ;
				}
			}
		}
	
	private:
		const unsigned long	_lenght;
		std::vector<int>	_vec;
		
};

#endif