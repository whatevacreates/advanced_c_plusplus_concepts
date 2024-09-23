#include "Base.hpp"
#include "B.hpp"
#include "A.hpp"
#include "C.hpp"
#include "Utils.hpp"


Base* createA()
{
    return new A;
}

Base* createB()
{
    return new B;
}

Base* createC()
{
    return new C;
}

Base* generate()
{
    int index = rand()%3;
    Base* (*arrayFunctionPointers[3])() = {createA, createB, createC};
    return arrayFunctionPointers[index]();
}



void identify(Base& p)
{

try {
    A& check = dynamic_cast<A&>(p);
    (void)check;
    std::cout << "Object is of type A" << std::endl;
} catch (const std::bad_cast&) {
    try {
        B& check = dynamic_cast<B&>(p);
        (void)check;
        std::cout << "Object is of type B" <<std::endl;
    } catch (const std::bad_cast&)
    {
        try {
            C& check = dynamic_cast<C&>(p);
            (void)check;
            std::cout << "Object is of type C" <<std::endl;
        }
        catch(const std::bad_cast&)
        {
            std::cout << "Wrong input." <<std::endl;
        }
    }
}


}

void identify(Base* p)
{ 
if(dynamic_cast<A*>(p))
std::cout << "Object is of type A" << std::endl;
else if(dynamic_cast<B*>(p))
std::cout << "Object is of type B" << std::endl;
else if(dynamic_cast<C*>(p))
std::cout << "Object is of type C" << std::endl;

}




int main() { 
    srand(time(0));
    for (int i = 1; i <= 10; i++) {   
        std::cout << B_ROSE << BOLD << "::::::::::::::::::::::::::::::::::::::::" << "TEST " << i << "::::::::::::::::::::::::::::::::::::::::" << RESET << std::endl;
        
        Base* test = generate(); 

        identify(*test); 
        identify(test);  

        delete test; 

        std::cout << std::endl;
    }

    return 0;
}