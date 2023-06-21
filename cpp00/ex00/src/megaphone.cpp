#include <iostream>
#include <cctype>

int main(int c, char **v)
{
	int j = 1;
	std::string str;

	if (c == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (j < c)
	{
		str += v[j];
		if (j++ < c-1)
			str += " ";
	}
	for (size_t i = 0; i <= str.size(); i++)
		str[i] = std::toupper(str[i]);
	std::cout << str << std::endl;
	return (0);
}

