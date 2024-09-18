#include "Utils.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

void createBureaucrats(std::string name, int grade, std::string form_name)
{
    //Form::Form(bool isSigned, int grade, const std::string name):_name(name),_isSigned(isSigned), _grade(grade)
    Form f(form_name);
    Bureaucrat b(name, grade);
    std::cout << BOLD << PASTEL_LIME << "Before: " << b << RESET << std::endl;
    b.incrementGrade();
    b.incrementGrade();
    b.incrementGrade();
    b.decrementGrade();
    b.decrementGrade();
    std::cout << BOLD << PASTEL_LIME << "After: "<< b << RESET << std::endl;
    std::cout << BOLD << PASTEL_MINT << "Form:  " << f << RESET << std::endl;
    f.beSigned(b);

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
    runTests("good_signed", 5, "form_1");
     std::cout <<  B_ROSE << "::::::::::::::::::::TEST 2::::::::::::::::::::" << RESET << std::endl;
    runTests("too_high", -10, "form_2");
     std::cout <<  B_ROSE << "::::::::::::::::::::TEST 3::::::::::::::::::::" << RESET << std::endl;
    runTests("too_high_for_increment", 2, "form_3");
     std::cout <<  B_ROSE << "::::::::::::::::::::TEST 4::::::::::::::::::::" << RESET << std::endl;
    runTests("too_low", 199, "form_4");
     std::cout <<  B_ROSE << "::::::::::::::::::::TEST 5::::::::::::::::::::" << RESET << std::endl;
    runTests("good_not_signed", 30, "form_5");
}
      

