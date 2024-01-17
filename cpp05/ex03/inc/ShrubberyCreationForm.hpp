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

        ShrubberyCreationForm(std::string target);

    private:
        void 		executeContract(const Bureaucrat &executor) const;
};



#endif