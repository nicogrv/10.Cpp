#ifndef PRESIDENTIALPARDONFORM
    #define PRESIDENTIALPARDONFORM  
    #include "./AForm.hpp"
    #include <fstream>


class AForm;

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm(std::string name);
        PresidentialPardonForm(PresidentialPardonForm &cpy);
        ~PresidentialPardonForm();
        PresidentialPardonForm &operator=(PresidentialPardonForm &cpy);
        
        void	execute(const Bureaucrat &executor) const;
        static AForm *NewForm(std::string name);

};

#endif