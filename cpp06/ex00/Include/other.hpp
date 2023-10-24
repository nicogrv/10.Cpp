#ifndef OTHER_HPP
#	define OTHER_HPP

	enum Couleur {
		_Error,
		_Char,
		_Int,
		_Float,
		_Double,
		_NInf,
		_PInf,
		_Nan
	};

	int ft_strlen(char *str);
	int ft_is_what(char *str);
	int	ft_atoi(char *str);



#endif