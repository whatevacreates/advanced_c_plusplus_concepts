#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#define  MIN_GRADE 150
#define  MAX_GRADE 1

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
    const std::string _name;
    int _grade;
    public:
    Bureaucrat();
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat(std::string name, int grade);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();
    std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void signForm(Form const &form) const;
    class GradeTooHighException: public std::exception
    {
        public:
        const char *what() const throw()
        {
            return "Exception thrown::: Grade is too high";
        }
    };
    class GradeTooLowException: public std::exception
    {
        public:
        const char *what() const throw()
        {
            return "Exception thrown::: Grade is too low";
        }
    };

};

std::ostream& operator<<(std::ostream &out, Bureaucrat const& src);

#endif
