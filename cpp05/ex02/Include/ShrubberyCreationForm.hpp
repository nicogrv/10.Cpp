#ifndef SHRUBBERYCREATIONFORM
    #define SHRUBBERYCREATIONFORM  
    #include "./AForm.hpp"


class AForm;

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm(std::string name);
        ShrubberyCreationForm(ShrubberyCreationForm &cpy);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm &operator=(ShrubberyCreationForm &cpy);


    private:
    
};

#endif