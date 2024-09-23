#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
 
 typedef struct Data
 {
    std::string name;
    int age;
    bool isVegetarian;
    std::string specialRequests[2];
 } Data;

class Serializer 
{
    private:
    Serializer();
    Serializer(const Serializer& other);
    Serializer& operator=(const Serializer& other);
    public:
    ~Serializer();
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif