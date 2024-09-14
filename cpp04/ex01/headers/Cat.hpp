
#ifndef CAT_CPP
#define CAT_CPP

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
    std::string _catIdea;
    Brain* _catBrain;
    public:
    Cat();
    Cat(std::string type);
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    ~Cat();
    void makeSound() const;
};
#endif
