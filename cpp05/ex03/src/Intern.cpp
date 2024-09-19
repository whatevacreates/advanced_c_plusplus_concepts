#include "Utils.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
    return;
}

AForm* Intern::makeForm(std::string form_name, const std::string target)
{
    
   std::string forms[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

 arrayPointerFunctions[0] = &Intern::makePresidentialForm;
 arrayPointerFunctions[1] = &Intern::makeRobotomyForm;
 arrayPointerFunctions[2] = &Intern::makeShrubberyForm;


    for(int i = 0; i < 3; i++)
    {
        if(forms[i] == form_name)
        {
            std::cout << BOLD << "Intern creates: " << forms[i] << std::endl;
        return (this->*arrayPointerFunctions[i])(target);
        }
    }

    throw NameDoesNotExists();
}



AForm* Intern::makePresidentialForm(std::string const target)
{
   
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeShrubberyForm(std::string const target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomyForm(std::string const target)
{
    return new RobotomyRequestForm(target);
}