#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP 
# include "./AForm.hpp"
# include <iostream>
# include<cstdlib>


class PresidentialPardonForm : public AForm
{

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &copy);
        ~PresidentialPardonForm();
        PresidentialPardonForm   &operator=(const PresidentialPardonForm &copy);

        PresidentialPardonForm(std::string target);
        static AForm   *createForm(std::string target);

    private:
        void 		executeContract(const Bureaucrat &executor) const;
};



#endif