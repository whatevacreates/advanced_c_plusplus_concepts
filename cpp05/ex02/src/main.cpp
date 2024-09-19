#include "Utils.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

void createShrubbery(std::string name, int grade, std::string target)
{
    ShrubberyCreationForm  f(target);
    Bureaucrat b(name, grade); 
    f.beSigned(b);
    f.execute(b);
    std::cout << BOLD << PASTEL_LIME << "Bureaucrat: " << b << RESET << std::endl;
  std::cout << BOLD << PASTEL_MINT << "AForm:  " << f << RESET << std::endl;
  

}

void createPresidentialPardon(std::string name, int grade, std::string target)
{
    PresidentialPardonForm  f(target);
    Bureaucrat b(name, grade); 
    f.beSigned(b);
    f.execute(b);
    std::cout << BOLD << PASTEL_LIME << "Bureaucrat: " << b << RESET << std::endl;
  std::cout << BOLD << PASTEL_MINT << "AForm:  " << f << RESET << std::endl;
  

}

void createRobotomyRequest(std::string name, int grade, std::string target)
{
    RobotomyRequestForm  f(target);
    Bureaucrat b(name, grade); 
    f.beSigned(b);
    f.execute(b);
    std::cout << BOLD << PASTEL_LIME << "Bureaucrat: " << b << RESET << std::endl;
  std::cout << BOLD << PASTEL_MINT << "AForm:  " << f << RESET << std::endl;
  

}

void runTests(std::string name, int grade, std::string target)
{
     try
    {
        createShrubbery(name, grade, target);
        createPresidentialPardon(name, grade, target);
        createRobotomyRequest(name, grade, target);
    }
    catch (const Bureaucrat::GradeTooHighException &e) {
            std::cerr << e.what() << std::endl; 
        }
        catch (const Bureaucrat::GradeTooLowException &e) {
            std::cerr << e.what() << std::endl; 
        }
        catch(const AForm::FormNotSignedException &e)
        {
            std::cerr << e.what() <<std::endl;
        }
}


      
int main(void)
{
    std::cout << B_ROSE << BOLD << "::::::::::::::::::::::::::::::::::::::::TEST 1::::::::::::::::::::::::::::::::::::::::" << RESET << std::endl;
     std::cout << std::endl;
    runTests("Bureaucrat1", 5, "garden");
     std::cout <<  B_ROSE <<BOLD << "::::::::::::::::::::::::::::::::::::::::TEST 2::::::::::::::::::::::::::::::::::::::::" << RESET << std::endl;
      std::cout << std::endl;
    runTests("Bureaucrat2", -10, "house");
     std::cout <<  B_ROSE <<BOLD << "::::::::::::::::::::::::::::::::::::::::TEST 3::::::::::::::::::::::::::::::::::::::::" << RESET << std::endl;
      std::cout << std::endl;
    runTests("Bureaucrat3", 2, "cocobush");
     std::cout <<  B_ROSE <<BOLD << "::::::::::::::::::::::::::::::::::::::::TEST 4::::::::::::::::::::::::::::::::::::::::" << RESET << std::endl;
      std::cout << std::endl;
    runTests("Bureaucrat4", 199, "pool");
     std::cout <<  B_ROSE <<BOLD << "::::::::::::::::::::::::::::::::::::::::TEST 5::::::::::::::::::::::::::::::::::::::::" << RESET << std::endl;
      std::cout << std::endl;
    runTests("Bureaucrat5", 30, "greenery");
    std::cout <<  B_ROSE <<BOLD<< "::::::::::::::::::::::::::::::::::::::::TEST 6::::::::::::::::::::::::::::::::::::::::" << RESET << std::endl;
      std::cout << std::endl;
    runTests("Bureaucrat5", 342230, "greenery");
    std::cout <<  B_ROSE << BOLD<< "::::::::::::::::::::::::::::::::::::::::TEST 7::::::::::::::::::::::::::::::::::::::::" << RESET << std::endl;
      std::cout << std::endl;
    runTests("Bureaucrat5", -30, "greenery");
}

