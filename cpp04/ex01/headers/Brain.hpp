#ifndef BRAIN_CPP
#define BRAIN_CPP

#include <iostream>
#include <string>

class Brain
{
    private:
    std::string ideas[100];
    
    public:
    Brain();
    Brain(std::string type);
    Brain(const Brain& others);
    Brain& operator=(const Brain& others);
    virtual ~Brain();
    
};

#endif
