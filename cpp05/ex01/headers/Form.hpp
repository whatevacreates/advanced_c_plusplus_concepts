#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include <string>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
    const std::string _name;
    bool _isSigned;
    const int _grade;
    public:
    Form();
    Form(bool isSigned, int grade, const std::string name);
    Form(const Form& other);
    Form& operator=(const Form& oother);
    ~Form();
    std::string getName() const;
    bool getIsSigned() const;
    int getGrade() const;
    void beSigned(const Bureaucrat& src);
    class GradeTooHighException : public std::exception
    {
        public:
        const char *what() const throw()
        {
             return "Grade is too high";
        }
       
    };
    class GradeTooLowException : public std::exception
    {
        const char *what() const throw()
        {
            return "Grade is too high";
        }
    };
};

std::ostream& operator<<(std::ostream &out, Form const &src);

#endif