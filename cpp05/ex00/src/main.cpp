#include "Utils.hpp"
#include "Bureaucrat.hpp"

void createBureaucrats(std::string name, int grade)
{
    Bureaucrat b(name, grade);
    std::cout << BOLD << PASTEL_LIME << b << RESET << std::endl;
    b.incrementGrade();
    std::cout << BOLD << PASTEL_LIME << b << RESET << std::endl;
     b.incrementGrade();
      std::cout << BOLD << PASTEL_LIME << b << RESET << std::endl;
     b.incrementGrade();
      std::cout << BOLD << PASTEL_LIME << b << RESET << std::endl;
     b.decrementGrade();
     std::cout << BOLD << PASTEL_LIME << b << RESET << std::endl;

}

int main(void)
{
    std::string input;
    int grade;
    std::string name;

while(true)
{
    std::cout << BOLD << PASTEL_LAVENDER << "Input the grade. Min: 150, max: 1. (exit)" << RESET << std::endl;
    std::getline(std::cin, input);
    if(input == "exit")
    break;
    std::cout << BOLD << PASTEL_LAVENDER << "Input the name for the Bureaucrat." << RESET << std::endl;
    std::getline(std::cin, name);

    try
    {
        grade = std::stoi(input);
        createBureaucrats(name, grade);
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Error: Invalid input. Please enter a number." << std::endl; 
    }
    catch(const std::out_of_range &e)
    {
        std::cerr << "Error: Input number is out of range for integers." << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException &e) {
            std::cerr << e.what() << std::endl; 
            std::cerr << "Please input a lower grade." << std::endl;
        }
        catch (const Bureaucrat::GradeTooLowException &e) {
            std::cerr << e.what() << std::endl; 
            std::cerr << "Please input a higher grade." << std::endl;
        }
    
}
      
}

