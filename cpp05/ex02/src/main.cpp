#include "Utils.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

void createBureaucrats(std::string name, int grade, std::string form_name)
{
    ShrubberyCreationForm  f(form_name);
    Bureaucrat b(name, grade); 
    f.beSigned(b);
    f.execute(b);
    std::cout << BOLD << PASTEL_LIME << "Bureaucrat: " << b << RESET << std::endl;
  std::cout << BOLD << PASTEL_MINT << "AForm:  " << f << RESET << std::endl;
  

}

void runTests(std::string name, int grade, std::string form_name)
{
     try
    {
        createBureaucrats(name, grade, form_name);
    }
    catch (const Bureaucrat::GradeTooHighException &e) {
            std::cerr << e.what() << std::endl; 
        }
        catch (const Bureaucrat::GradeTooLowException &e) {
            std::cerr << e.what() << std::endl; 
        }
}


      
int main(void)
{
    std::cout << B_ROSE << "::::::::::::::::::::TEST 1::::::::::::::::::::" << RESET << std::endl;
     std::cout << std::endl;
    runTests("Bureaucrat1", 5, "garden");
     std::cout <<  B_ROSE << "::::::::::::::::::::TEST 2::::::::::::::::::::" << RESET << std::endl;
      std::cout << std::endl;
    runTests("Bureaucrat2", -10, "house");
     std::cout <<  B_ROSE << "::::::::::::::::::::TEST 3::::::::::::::::::::" << RESET << std::endl;
      std::cout << std::endl;
    runTests("Bureaucrat3", 2, "cocobush");
     std::cout <<  B_ROSE << "::::::::::::::::::::TEST 4::::::::::::::::::::" << RESET << std::endl;
      std::cout << std::endl;
    runTests("Bureaucrat4", 199, "pool");
     std::cout <<  B_ROSE << "::::::::::::::::::::TEST 5::::::::::::::::::::" << RESET << std::endl;
      std::cout << std::endl;
    runTests("Bureaucrat5", 30, "greenery");
}

