#ifndef SHRUBBERYCREATIONFORM
    #define SHRUBBERYCREATIONFORM  
    #include "./AForm.hpp"
    #include <fstream>


class AForm;

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm(std::string name);
        ShrubberyCreationForm(ShrubberyCreationForm &cpy);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm &operator=(ShrubberyCreationForm &cpy);
        
        void	execute(const Bureaucrat &executor) const;
        static AForm *NewForm(std::string name);

};

#endif