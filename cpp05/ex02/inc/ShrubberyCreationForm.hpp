#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP 
# include "./AForm.hpp"
# include <iostream>

class ShrubberyCreationForm : public AForm
{

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &copy);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm   &operator=(const ShrubberyCreationForm &copy);


        
    

    private:
        std::string _name;

};



#endif