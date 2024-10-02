#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin():_path(""){}

Bitcoin::Bitcoin(const std::string path):_path(path)
{
    std::ifstream file;
    std::string line;

    file.open(path);

    while(std::getline(file, line))
    {
        char validatedLine;
        validatedLine = validateLine(line);
        if(validatedLine == 'y')
        {
            _data.insert(std::make_pair("Error: Invalid Syntax, ciao.", WRONG_YEAR));  
        }
         
        else if(validatedLine == 'v')
        {
              _data.insert(std::make_pair("Error: Invalid Syntax, ciao.", WRONG_VALUE));  
        }
        std::cout << line << std::endl;



    }

}

char Bitcoin::validateLine(std::string &line)
{
    std::string str = line.substr(6,7);
  
    for(int i = 0; i < 4; i++)
    {
        if(!isdigit(str[i]))
        {
              return'y';  
        }
          
    }  
    
    std::stringstream ss(str);
    int check;
    ss >> check;
    if(check > 12 || check < 1)
    {
        std::cout << "Month is invalid" << std::endl;
        return 'm';

    }
    
return 's';
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