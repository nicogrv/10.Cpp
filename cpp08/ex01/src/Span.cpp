#include "../Include/Span.hpp"
#include <limits.h>	

Span::Span(const unsigned int N) {
	this->tab = new int[N];
	this->length = N;
	this->indexTab = 0;
}
	


Span::Span(const Span &src) {
 (void) src;
}

Span::~Span() {

}

Span	&Span::operator=(const Span &src) {
	(void) src;
	return *this;
}


void Span::addNumber(const int N) {
	if (this->length <= this->indexTab)
		throw (outOfRange("Out of range add"));
	this->tab[this->indexTab] = N;
	// for (unsigned int i = 0; i < this->indexTab; i++)
	// 	std::cout << this->tab[i] << std::endl;
	// std::cout << std::endl;
	this->indexTab++;
}	

int Span::shortestSpan(void) {
	int diff = INT_MAX;
	if (this->indexTab < 2)
		return (-1);
	for (unsigned int i = 0; i < this->indexTab;i++) {
		for (unsigned int j = i; j < this->indexTab;j++) {
			if (this->tab[i] < this->tab[j] && this->tab[j] - this->tab[i] < diff)
				diff = this->tab[j] - this->tab[i];
			else if (this->tab[j] < this->tab[i] && this->tab[i] - this->tab[j] < diff)
				diff = this->tab[i] - this->tab[j];
		}
	}
	return (diff);
}

int Span::longestSpan(void) {
	if (this->indexTab < 2)
		return (-1);
	int min = this->tab[0];
	int max = this->tab[0];
	for (unsigned int i = 0; i < this->indexTab; i++) {
		if (this->tab[i] < min)
			min = this->tab[i];
		if (max < this->tab[i])
			max = this->tab[i];
	}
	return (max - min);

}