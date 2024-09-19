#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"
#define RRF_GRADE_SIGN 72
#define RRF_GRADE_EXEC 45
#define DRILLING_NOISE "Vrrrrrrrrrrr... Vrrrrrrrrrrr... Vrrrrrrrrrrr... "

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
    private:
    std::string _target;

    public:
     RobotomyRequestForm();
     RobotomyRequestForm(std::string _target);
     RobotomyRequestForm(const  RobotomyRequestForm& other);
     RobotomyRequestForm& operator=(const  RobotomyRequestForm& other);
    ~RobotomyRequestForm();
    void execute(Bureaucrat const &executor) const;
    void beSigned(const Bureaucrat & src);
};

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm const &form);

#endif