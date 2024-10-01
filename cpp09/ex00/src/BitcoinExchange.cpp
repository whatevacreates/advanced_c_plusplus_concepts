#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin():_path(""){}

Bitcoin::Bitcoin(std::string path):_path(path)
{
    std::ifstream file;
    std::string line;

    file.open(path);

    while(std::getline(file, line))
    {
        std::cout << line << std::endl;
    }

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