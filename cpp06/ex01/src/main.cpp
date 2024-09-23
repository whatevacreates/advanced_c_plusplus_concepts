#include "Serializer.hpp"
#include "Utils.hpp"




int randomNumber()
 { 
    
    int randomNumber = std::rand() % 11;
    return randomNumber;
}

void initializeData(Data &data)
{
    std::string arrayNames[11] = {"Anna" , "Steph", "Ola", "Zoe", "Mia", "Barbra", "Olaf", "Dia", "Kinga", "Zina", "Igor"};
    std::string specialRequestsString[11] = {"more drinks", "spicy", "no salt", "sea view", "allergy proof", "extra salad", "no veggies", "chicken", "fish", "no dessert", "double fries"};
    data.name = arrayNames[randomNumber()];
    data.specialRequests[0] = specialRequestsString[randomNumber()];

    data.specialRequests[1] = specialRequestsString[randomNumber()];
    data.age = randomNumber() + randomNumber() + randomNumber() + randomNumber();
    randomNumber()%2 == 0 ? data.isVegetarian = false : data.isVegetarian = true;
}

int main()
{
Data *person = new Data;
uintptr_t pointer;

std::srand(std::time(0));
for(int i = 0; i < 10; i++)
{
std::cout << "\n" << std::endl;
initializeData(*person);
pointer = Serializer::serialize(person);
std::cout << "Serialized pointer address: " << pointer << std::endl;
std::cout << B_ROSE << BOLD << "::::::::::::::::::::::::::::::::::::::::"<< person->name <<"::::::::::::::::::::::::::::::::::::::::" << RESET << std::endl;
person = Serializer::deserialize(pointer);
std::cout  << BOLD << PASTEL_LIME  << "age: " << RESET << person->age << std::endl;
std::cout << BOLD << PASTEL_LIME  <<"vegetarian: " << RESET << (person->isVegetarian ? "yes" : "no") <<std::endl;
std::cout << BOLD << PASTEL_LIME  << "special requests: " << RESET << person->specialRequests[0] << ", " << person->specialRequests[1] << RESET << std::endl;
}
}