#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <exception>
#include "AForm.hpp"
#define SCF_GRADE_SIGN 145
#define SCF_GRADE_EXEC 137

class ShrubberyCreationForm : public AForm
{
    private:
    std::string _target;

    public:
    ShrubberyCreationForm();
     ShrubberyCreationForm(std::string _target);
     ShrubberyCreationForm(const  ShrubberyCreationForm& other);
     ShrubberyCreationForm& operator=(const  ShrubberyCreationForm& other);
    ~ShrubberyCreationForm();
    void execute(Bureaucrat const &executor) const;   
    void beSigned(const Bureaucrat & src);
};

std::ostream& operator<<(std::ostream &out, ShrubberyCreationForm const &form);

#endif