#include "./PhoneBook.hpp"
#include "./ex01.hpp"
#include "./Contact.hpp"

Contact::Contact(void)
{
    this->nname = "";
    this->fname = "";
    this->lname = "";
    this->phone = "";
    this->darkestSecret = "";
    return ;
}

Contact::~Contact(void)
{
    return ;
}