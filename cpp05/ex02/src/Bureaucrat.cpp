#include "Bureaucrat.hpp"
#include "Utils.hpp"
#include "AForm.hpp"


Bureaucrat::Bureaucrat()
{
    return;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
      if (grade < MAX_GRADE) {
            throw Bureaucrat::GradeTooHighException();
        }
        if (grade > MIN_GRADE) {
            throw Bureaucrat::GradeTooLowException();
        }
        _grade = grade;  
}

Bureaucrat::Bureaucrat(const Bureaucrat& other):_name(other._name), _grade(other._grade)
{
    
    if(this != &other)
    {
        if (other._grade < MAX_GRADE)
        throw Bureaucrat::GradeTooHighException();
       
        if(other._grade > MIN_GRADE)
        throw Bureaucrat::GradeTooLowException();
         _grade = other._grade;
    }
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
     
    if(this != &other)
    {
        _grade = other._grade;
        if (other._grade < MAX_GRADE)
        throw Bureaucrat::GradeTooHighException();
       
        if(other._grade > MIN_GRADE)
        throw Bureaucrat::GradeTooLowException();
    }
    return *this;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

std::string Bureaucrat::getName() const
{
    return _name;
}

void Bureaucrat::decrementGrade()
{
    if(_grade >= MIN_GRADE)
    throw Bureaucrat::GradeTooLowException();
    _grade++;
}

void Bureaucrat::incrementGrade()
{
    if(_grade <= MAX_GRADE)
    throw Bureaucrat::GradeTooHighException();
    _grade--;
}

Bureaucrat::~Bureaucrat()
{
    return;
}

std::ostream& operator<<(std::ostream &out, Bureaucrat const& src)
{ 
    return out << "Bureacrat named: " << src.getName() << " has grade: " << src.getGrade() <<std::endl; 
}

void Bureaucrat::signFormA(AForm const &form) const
{
    if(getGrade() < MAX_GRADE)
    throw GradeTooHighException();
    if(getGrade() > MIN_GRADE)
    throw GradeTooLowException();
    
    if(form.getIsSigned())
    std::cout << B_BLACK << BOLD << _name << " SIGNED " << form.getName() << RESET << std::endl;
    else
    std::cout << B_BLACK << BOLD << _name << " COULDN'T SIGN " << form.getName() << " because the grade is too low." << RESET << std::endl;
}

void Bureaucrat::executeForm(AForm const &form)
{
    if(form.getSignGrade() < form.getExecGrade())
     std::cout << UNDERLINE << BOLD << _name << " executed " << form.getName() << RESET << std::endl;
     else
     std::cout << UNDERLINE << BOLD << _name << " cannot execute " << form.getName() << " because exec grade is lower than sign grade " << RESET << std::endl;
}