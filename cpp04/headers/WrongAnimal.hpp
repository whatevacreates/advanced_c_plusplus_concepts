#ifndef WRONGANIMAL_CPP
#define WRONGANIMAL_CPP

#include <iostream>
#include <string>

class WrongAnimal
{
    protected:
    std::string _type;
    std::string _sound;
    public:
    WrongAnimal();
    WrongAnimal(std::string type);
    ~WrongAnimal();

    //setters:
    void setType(std::string type);
    void setSound(std::string sound);

    //getters:
    std::string getType(void) const;
    std::string getSound(void) const;
    void makeSound() const;
};

#endif
