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
    const int _gradeReq;
    const int _gradeExecute;
    public:
    Form();
    Form(const std::string name);
    Form(const Form& other);
    Form& operator=(const Form& oother);
    ~Form();
    std::string getName() const;
    bool getIsSigned() const;
    int getGradeReq() const;
    int getGradeExecute() const;
    void beSigned(const Bureaucrat& src);
    class GradeTooHighException : public std::exception
    {
        public:
        const char *what() const throw()
        {
             return "Exception thrown::: Grade is too high";
        }
       
    };
    class GradeTooLowException : public std::exception
    {
        const char *what() const throw()
        {
            return "Exception thrown::: Grade is too high";
        }
    };
};

std::ostream& operator<<(std::ostream &out, Form const &src);

#endif