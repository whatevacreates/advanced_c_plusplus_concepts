#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin():_path(""){}

Bitcoin::Bitcoin(const std::string path):_path(path)
{
    std::ifstream file;
    std::string line;
    std::stringstream ss;
    std::string dateStr;
    std::string valueStr;
    //int date;
    //int value;

    file.open(path);

    while(std::getline(file, line))
    {
        validateLine(line);
        std::cout << line << std::endl;
    }

}

void Bitcoin::validateLine(std::string &line)
{
    std::string str = line.substr(5,2);
    std::stringstream ss(  str ) ;
    int dot_count = 0;
    float value;
    int monthArray[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  size_t i;
    for(i = 0; i < line.length(); i++)
    {
         if(i > 12 && line[i] == '.' && dot_count == 0)
         {
            dot_count = 1;
         }
        else if(!isdigit(line[i]) && i != 4 && i != 7 && i != 10 && i != 11 && i!= 12)
        { if(line[13] == '-')
    {

        _data.insert(std::make_pair("Error: Value cannot be negative", -1));
        return;
    }
    
              _data.insert(std::make_pair("Error: Invalid Syntax", -1));
              return;
        }
          
    } 
    std::cout << "sizet i check: " << i << std::endl;
   
    if(line[4] != '-' || line[7] != '-' || line.substr(10, 3)  != " | ")
    {

       _data.insert(std::make_pair("Error: Invalid Syntax", -1));
        return;
    } 
    if(i <= 13)
    {
        _data.insert(std::make_pair("Error: Value cannot be left empty.", -1));
              return;
    }
   
    int check;
    int month;
    ss >> month;
    if(month > 12 || month < 1)
    {
         _data.insert(std::make_pair("Error: Invalid Month Format", -1));
        return;
    }

   ss.clear();
   ss.str(std::string());
   str = line.substr(8,2);
   ss << str;
   ss >> check;
   
        if(check > monthArray[month-1] || check < 1)
        {
          _data.insert(std::make_pair("Error: Invalid Day Format", -1));
        return;
        }
ss.clear();
str = line.substr(12,MAX);
ss << str;
ss >> value;
std::cout << "value: " << value << std::endl;
if(value > MAX)
{
    
          _data.insert(std::make_pair("Error: value is too big.", -1));
        return;
}
 _data.insert(std::make_pair(line.substr(0, 9), value));
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