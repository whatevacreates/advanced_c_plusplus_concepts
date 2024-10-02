#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin():_path(""){}

Bitcoin::Bitcoin(const std::string path):_path(path)
{
    std::ifstream file;
    std::string *line;

    file.open(path);

    while(std::getline(file, *line))
    {
        validateLine(line);
        std::cout << line << std::endl;


    }

}

bool Bitcoin::validateLine(std::string &line)
{
    std::string str = line.substr(0,4);
    std::stringstream ss(str);
    for(int i = 0; i < 4; i++)
    {
        if(!isdigit(str[i]))
        line = "Error: Invalid Syntax, ciao.";
        return false;
    }
    int check;
    ss >> check;
    if(check > 2024)
    std::cout << "Yeah is bigger than 2024" << std::endl;

return true;
}
Bitcoin::Bitcoin(const Bitcoin& other): _path(other._path), _data(other._data)
{
}

Bitcoin& Bitcoin::operator=(const Bitcoin& other)
{
    if(this != &other)
    {
        _path = other._path;
        _data = other._data;
    }
    return *this;
}

void Bitcoin::exchange()
{
    std::cout << "this is exchange" << std::endl;
}


Bitcoin::~Bitcoin(){}