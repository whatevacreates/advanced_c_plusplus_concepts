#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"
#define PPF_GRADE_SIGN 25
#define PPF_GRADE_EXEC 5

class PresidentialPardonForm : public AForm
{
    private:
    std::string _target;
    public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string _target);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    ~PresidentialPardonForm();
    void execute(Bureaucrat const &executor) const;
};

#endif