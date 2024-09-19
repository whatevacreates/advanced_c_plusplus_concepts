#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class AForm;

class Intern
{
    private:
    AForm* (Intern::*arrayPointerFunctions[3])(const std::string);
    public:
    Intern();
    AForm* makeShrubberyForm(const std::string target);
    AForm* makePresidentialForm(const std::string target);
    AForm* makeRobotomyForm(const std::string target);
    Intern(const Intern &other);
    Intern& operator=(const Intern &other);
    ~Intern();
    AForm *makeForm(std::string form_name, const std::string target);

    //exceptions

    class NameDoesNotExists: public std::exception
    {
        public:
        const char *what() const throw()
        {
            return "Exception thrown: a form passed as a parameter doesn't exists.";
        }
    };
};

#endif