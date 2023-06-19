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
		std::cout << v[j];
		j++;
	}
	std::cout << std::endl;
	return 0;
}

// $>./megaphone "shhhhh... I think the students are asleep..."
// SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
// $>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
// DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
// $>./megaphone
// * LOUD AND UNBEARABLE FEEDBACK NOISE *
// $>
