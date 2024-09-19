#include "Utils.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery", SCF_GRADE_SIGN, SCF_GRADE_EXEC, target), _target(target)
{
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): _target(other._target)
{
    return;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
    if(this!= &other)
    {
        this->_target = other._target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
   if(!getIsSigned())
   {
     std::cout << STRIKE << getName() << " cannot execute " << getName() << " because the form is not signed." <<RESET << std::endl;
    throw FormNotSignedException();
   }
   
    if(getIsSigned() && executor.getGrade() < getExecGrade())
    {
        

        try 
        {
        std::ofstream file(_target + "_shrubbery");
        file.exceptions(std::ofstream::failbit | std::ofstream::badbit);
        file << "       *\n";
        file << "      ***\n";
        file << "     *****\n";
        file << "    *******\n";
        file << "   *********\n";
        file << "      |||\n";
        file.close();
         std::cout << B_LAVENDER << executor.getName() << " executed "<< getName() << " form." <<RESET <<std::endl;
        }
        catch (const std::ofstream::failure& e)
        {
            std::cerr << "Error: could not create or write to file: " << e.what() << std::endl;
        }
    } 
    else
    std::cout << B_PERIWINKLE << getName() << " cannot execute " << std::endl;

}

std::ostream& operator<<(std::ostream &out, ShrubberyCreationForm const &form)
{
     out << "target: " << form.getTarget() << std::endl;
return out;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


void ShrubberyCreationForm::beSigned(const Bureaucrat& src)
 {
    if(src.getGrade() < MAX_GRADE)
        throw AForm::GradeTooHighException();
        if(src.getGrade() > MIN_GRADE)
        throw AForm::GradeTooLowException();
    if(src.getGrade() <= getSignGrade())
    setIsSigned(true);

    src.signFormA(*this);
 }