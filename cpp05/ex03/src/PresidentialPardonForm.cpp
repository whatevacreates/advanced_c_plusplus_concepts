#include "Utils.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
    return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidency", PPF_GRADE_SIGN, PPF_GRADE_EXEC, target), _target(target)
{
    return;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): _target(other._target)
{
    return;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
    if(this!= &other)
    {
        this->_target = other._target;
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
   if(!getIsSigned())
   {
     std::cout << STRIKE << getName() << " cannot execute " << getName() << " because the form is not signed." << RESET << std::endl;
    throw FormNotSignedException();
   }

     std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
     std::cout << B_SALMON << executor.getName() << " executed "<< getName() << " form." <<RESET <<std::endl;

}

std::ostream& operator<<(std::ostream &out, PresidentialPardonForm const &form)
{
     out << "target: " << form.getTarget() << std::endl;
return out;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    return;
}


void PresidentialPardonForm::beSigned(const Bureaucrat& src)
 {
    if(src.getGrade() < MAX_GRADE)
        throw AForm::GradeTooHighException();
        if(src.getGrade() > MIN_GRADE)
        throw AForm::GradeTooLowException();
    if(src.getGrade() <= getSignGrade())
    setIsSigned(true);

    src.signFormA(*this);
 }