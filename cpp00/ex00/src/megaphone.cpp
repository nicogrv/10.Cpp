#include <iostream>
#include <cctype>

int main(int c, char **v)
{
	int i = 0;
	int j = 1;
	if (c == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (j < c)
	{
		i = 0;
		while (v[j][i]) 
		{
			v[j][i] = std::toupper(v[j][i]);
			i++;
		}
		std::cout << v[j] << " ";
		j++;
	}
	std::cout << std::endl;
	return 0;
}
