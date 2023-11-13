#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>

class outOfRange : public std::exception 
{
	public:
		outOfRange(const char *error) : _error(error) {}
		const char* what() const throw() {
			return _error;
		}

	private:
		const char *_error;
};

class Span 
{
	public:
		Span(const unsigned int N);
		Span(const Span &src);
		~Span();
		Span	&operator=(const Span &src);

		void addNumber(const int N);	
		int shortestSpan(void);
		int longestSpan(void);
	private:
		Span();
		int *tab;
		unsigned int length;
		unsigned int indexTab;
};
#endif