#include "Utils.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"


void runTests(std::string form_name)
{
  Intern intern;
    AForm* form;
    
    try
    {
    form = intern.makeForm(form_name, "pool");
    std::cout << "All forms successfully created." <<std::endl;
    } catch(const Bureaucrat::GradeTooHighException &e)
    {
      std::cerr << e.what() << std::endl;

    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
      std::cerr << e.what() <<std::endl;
    }
    catch (const AForm::FormNotSignedException &e)
    {
      std::cerr << e.what() <<std::endl;
    }
    catch(const Intern::NameDoesNotExists &e)
    {
      std::cerr << e.what() << " Wrong name: " << form_name << std::endl;
    }
   
}

      
int main(void)
{
    std::cout << B_ROSE << BOLD << "::::::::::::::::::::::::::::::::::::::::TEST 1::::::::::::::::::::::::::::::::::::::::" << RESET << std::endl;
     std::cout << std::endl;
    runTests("Greenery");
     std::cout <<  B_ROSE <<BOLD << "::::::::::::::::::::::::::::::::::::::::TEST 2::::::::::::::::::::::::::::::::::::::::" << RESET << std::endl;
      std::cout << std::endl;
    runTests("PresidentialPardonForm");
     std::cout <<  B_ROSE <<BOLD << "::::::::::::::::::::::::::::::::::::::::TEST 3::::::::::::::::::::::::::::::::::::::::" << RESET << std::endl;
      std::cout << std::endl;
    runTests("Pancake");
     std::cout <<  B_ROSE <<BOLD << "::::::::::::::::::::::::::::::::::::::::TEST 4::::::::::::::::::::::::::::::::::::::::" << RESET << std::endl;
      std::cout << std::endl;
    runTests("RobotomyRequestForm");
     std::cout <<  B_ROSE <<BOLD << "::::::::::::::::::::::::::::::::::::::::TEST 5::::::::::::::::::::::::::::::::::::::::" << RESET << std::endl;
      std::cout << std::endl;
    runTests("ShrubberyCreationForm");
    std::cout <<  B_ROSE <<BOLD<< "::::::::::::::::::::::::::::::::::::::::TEST 6::::::::::::::::::::::::::::::::::::::::" << RESET << std::endl;
      std::cout << std::endl;
    runTests("oops");
}



