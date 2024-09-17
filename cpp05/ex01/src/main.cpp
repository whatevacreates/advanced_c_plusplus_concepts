#include "Utils.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

void createBureaucrats(std::string name, int grade)
{
    Form f;
    std::cout << " grade " << grade << std::endl;
    Bureaucrat b(name, grade);
    b.incrementGrade();
    b.incrementGrade();
    b.incrementGrade();
    b.decrementGrade();
    b.decrementGrade();
    f.beSigned(b);

}

int main(void)
{
    
    try
    {
        createBureaucrats("good", 15);
    }
    catch (const Bureaucrat::GradeTooHighException &e) {
            std::cerr << e.what() << std::endl; 
        }
        catch (const Bureaucrat::GradeTooLowException &e) {
            std::cerr << e.what() << std::endl; 
        }
    
}
      

