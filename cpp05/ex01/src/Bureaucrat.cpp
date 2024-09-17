#include "Bureaucrat.hpp"
#include "Utils.hpp"
#include "Form.hpp"


Bureaucrat::Bureaucrat()
{
   
    return;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
std::cout << " parameterized contructor called " << _grade << std::endl;
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
         _grade = other._grade;
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
    if(_grade >= MAX_GRADE)
    throw Bureaucrat::GradeTooLowException();
    _grade++;
}

void Bureaucrat::incrementGrade()
{
    if(_grade <= MIN_GRADE)
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

void Bureaucrat::signForm(Form const &form) const
{
 
    if(form.getGrade() < MAX_GRADE)
    throw GradeTooHighException();
    if(form.getGrade() > MIN_GRADE)
    throw GradeTooLowException();

    if(form.getIsSigned())
    std::cout << _name << " signed " << form.getName() << std::endl;
    else
    std::cout << _name << "couldn't sign " << form.getName() << " because the grade is too low." << std::endl;
}