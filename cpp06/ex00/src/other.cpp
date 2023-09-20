#include <iostream>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}


bool ft_is_char(char *str)
{
	if (str && ft_strlen(str) == 3 && str[0] == '\'' && str[ft_strlen(str)-1] =='\'')
		return (true);
	return (false);
}

bool ft_is_int(char *str)
{
	
}