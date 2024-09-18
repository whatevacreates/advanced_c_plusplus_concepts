#include "AForm.hpp"
#include "Utils.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): 
_name(""), _isSigned(false), _signGrade(0), _execGrade(0), _target("")
{
}

AForm::AForm(std::string name, int signGrade, int execGrade, std::string target): 
_name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade), _target(target)
{
    if(signGrade < MAX_GRADE || execGrade < MAX_GRADE)
    throw AForm::GradeTooHighException();
    if(signGrade > MIN_GRADE || execGrade > MIN_GRADE)
    throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other) : _name(other._name), _isSigned(false), _signGrade(other._signGrade), _execGrade(other._execGrade), _target(other._target)
{
     if(_signGrade < MAX_GRADE || _execGrade < MAX_GRADE)
    throw AForm::GradeTooHighException();
    if(_signGrade > MIN_GRADE || _execGrade > MIN_GRADE)
    throw AForm::GradeTooLowException();
}

AForm& AForm::operator=(const AForm& other)
{
    if(this != &other)
    {
        this->_isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm()
{}

std::string AForm::getName() const
{
    return _name;
}
    bool AForm::getIsSigned() const
    {
        return _isSigned;
    }

    int AForm::getSignGrade() const
    {
        return _signGrade;
    }

    int AForm::getExecGrade() const
    {
        return _execGrade;
    }
    std::string AForm::getTarget() const
    {
        return _target;
    }

    //member functions

void AForm::beSigned(const Bureaucrat& src)
 {
    std::cout << "was this called ?????? " << std::endl;
    if(src.getGrade() < MAX_GRADE)
        throw AForm::GradeTooHighException();
        if(src.getGrade() > MIN_GRADE)
        throw AForm::GradeTooLowException();
    if(src.getGrade() <= _signGrade)
    _isSigned = true;

    src.signFormA(*this);
 }

void AForm::setIsSigned(bool isSigned)
{
    _isSigned = isSigned;
}
/*
  void AForm::checkExecution(Bureaucrat const &executor) const
  {
    if(!_isSigned)
    throw AForm::FormNotSignedException();
  }
  */