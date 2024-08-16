
#include "phonebook.hpp"


int main(int argc, char *argv[])
{

std::string word;
Phonebook phonebook;

(void)argv;
while(argc < 10)
{
    std::cout << "Enter your prompt: ADD, SEARCH or EXIT:" << std::endl;
    std::getline(std::cin, word);
    if(word == "ADD")
    {
        if(phonebook.add_contact())
        return 1;
    }
     
    else if(word == "SEARCH")
     phonebook.search_contact();
    else if(word == "EXIT")
     phonebook.exit_phonebook();
    else
    {
        std::cout << "C'mon we need the prompt! Try again!\n" << std::endl;
    }
    argc++;
}


}