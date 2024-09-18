#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm 
{
    private:
    const std::string _name;
    bool _isSigned;
    const int _signGrade;
    const int _execGrade;
    const std::string _target;

    public:
    AForm();
    AForm(std::string name, int signGrade, int execGrade, std::string target);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();
    

    //getters
    std::string getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;
    std::string getTarget() const;
    void setIsSigned(bool isSigned);

    //member functions
    virtual void beSigned(const Bureaucrat& src);
    virtual void execute(Bureaucrat const &executor) const = 0;

    //exception classes
    class GradeTooHighException : public std::exception
    {
        public:
        const char *what() const throw()
        {
             return "Exception thrown::: Grade is too high.";
        }
    };
    class GradeTooLowException : public std::exception
    {
        public:
        const char *what() const throw()
        {
            return "Exception thrown::: Grade is too low.";
        }
    };

    class FormNotSignedException : public std::exception
    {
        public:
        const char *what() const throw()
        {
            return "Exception thrown::: Form is not signed.";
        }
    };
    /*
    protected:
    void checkExecution(Bureaucrat const &executor) const;
    */
};

std::ostream operator<<(std::ostream &out, AForm const &form);

#endif