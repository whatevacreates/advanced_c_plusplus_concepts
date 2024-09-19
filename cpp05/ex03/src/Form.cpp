#include "Utils.hpp"
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form():_name(""),_isSigned(false),_gradeReq(20), _gradeExecute(110)
{
    return;
}

Form::Form(const std::string name):_name(name),_isSigned(false), _gradeReq(20), _gradeExecute(110)
{
    if(_gradeReq < MAX_GRADE || _gradeExecute < MAX_GRADE)
    throw Form::GradeTooHighException();
    if(_gradeReq > MIN_GRADE || _gradeExecute > MIN_GRADE)
    throw Form::GradeTooLowException();
}

Form::Form(const Form& other)
    : _name(other._name), _isSigned(other._isSigned), _gradeReq(other._gradeReq), _gradeExecute(other._gradeExecute)
{
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

int Form::getGradeReq() const
{
    return _gradeReq;
}


int Form::getGradeExecute() const
{
    return _gradeExecute;
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
    return out << src.getName() << ", required grade: " << src.getGradeReq() << 
    " , execute grade: " << src.getGradeExecute() << " and the form is currently: " << printSigned << std::endl;
}

 void Form::beSigned(const Bureaucrat& src)
 {
    if(src.getGrade() < MAX_GRADE)
        throw Form::GradeTooHighException();
        if(src.getGrade() > MIN_GRADE)
        throw Form::GradeTooLowException();
    if(src.getGrade() <= _gradeReq)
    _isSigned = true;

    src.signForm(*this);
 }

