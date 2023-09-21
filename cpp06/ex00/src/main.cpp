#include "../Include/ScalarConverter.hpp"


int main(int c, char **v)
{
	(void) c;
	if (c == 2)
		ScalarConverter::convert(v[1]);
}
