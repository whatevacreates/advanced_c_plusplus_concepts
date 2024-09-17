#include "Utils.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form():_name(""),_isSigned(false),_grade(0)
{
    return;
}

Form::Form(bool isSigned, int grade, const std::string name):_name(name),_isSigned(isSigned), _grade(grade)
{
    if(_grade < MAX_GRADE)
    throw Form::GradeTooHighException();
    if(_grade > MIN_GRADE)
    throw Form::GradeTooLowException();
}

Form::Form(const Form& other)
    : _name(other._name), _isSigned(other._isSigned), _grade(other._grade)
{
    std::cout << "Form copy constructor called." << std::endl;
}

Form& Form::operator=(const Form& other)
{   
    if(this != &other)
    {
        _isSigned = other._isSigned;
    }
    return *this;
}

Form::~Form()
{
    return;
}

bool Form::getIsSigned() const
{
    return _isSigned;
}

int Form::getGrade() const
{
    return _grade;
}

std::string Form::getName() const
{
    return _name;
}

std::ostream& operator<<(std::ostream &out, Form const &src)
{
    std::string printSigned;

    if(src.getIsSigned())
    printSigned = "is signed";
    else
    printSigned = "not signed";
    return out << src.getName() << " has grade: " << src.getGrade() << " and the form is " << printSigned << std::endl;
}

 void Form::beSigned(const Bureaucrat& src)
 {
    if(src.getGrade() < MAX_GRADE)
        throw Form::GradeTooHighException();
        if(src.getGrade() > MIN_GRADE)
        throw Form::GradeTooLowException();

    if(src.getGrade() <= 20)
    _isSigned = true;

    src.signForm(*this);
 }

