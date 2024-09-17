#include "Bureaucrat.hpp"
#include "Utils.hpp"


Bureaucrat::Bureaucrat()
{
   
    return;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{  if (grade < MAX_GRADE) {
            throw Bureaucrat::GradeTooHighException();
        }
        if (grade > MIN_GRADE) {
            throw Bureaucrat::GradeTooLowException();
        }
        _grade = grade;  
    
    
  
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
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
    if(_grade <= MAX_GRADE)
    throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void Bureaucrat::incrementGrade()
{
    if(_grade >= MIN_GRADE)
    throw Bureaucrat::GradeTooLowException();
    _grade++;
}

Bureaucrat::~Bureaucrat()
{
    return;
}

std::ostream& operator<<(std::ostream &out, Bureaucrat const& src)
{
    return out << "Bureacrat named: " << src.getName() << " has grade: " << src.getGrade() <<std::endl; 
}