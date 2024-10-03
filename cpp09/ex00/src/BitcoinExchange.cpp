#include "BitcoinExchange.hpp"
#include "Utils.hpp"

Bitcoin::Bitcoin() : _path("")
{
}

Bitcoin::Bitcoin(const std::string path) : _path(path)
{

 _errorsBank[0] = "Error: Value cannot be negative.";
  _errorsBank[1] = "Error: Invalid syntax.";
   _errorsBank[2] ="Error: Your value has too many decimal points.";
    _errorsBank[3] = "Error: Value cannot be left empty.";
     _errorsBank[4] =  "Error: Invalid month format.";
      _errorsBank[5] = "Error: Invalid day format.";
       _errorsBank[6] = "Error: value is too big.";
   
	std::ifstream file;
	std::string line;
	std::stringstream ss;
	std::string dateStr;
	std::string valueStr;

	file.open(path);
	while (std::getline(file, line))
	{
		validateLine(line);
	}
}

void Bitcoin::validateLine(std::string &line)
{
	int		dot_count;
	float	value;
	int		monthArray[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	size_t	i;
	int		check;
	int		month;
    int date;

	std::string str = line.substr(5, 2);
	std::stringstream ss(str);
	dot_count = 0;
	for (i = 0; i < line.length(); i++)
	{
		if (i > 12 && line[i] == '.' && dot_count == 0)
		{
			dot_count = i;
		}
		else if (!isdigit(line[i]) && i != 4 && i != 7 && i != 10 && i != 11
			&& i != 12)
		{
			if (line[13] == '-')
			{
				_data.push_back(std::make_pair(0,
						-1));
				return ;
			}
			_data.push_back(std::make_pair(1, -1));
			return ;
		}
	}
	if (dot_count > 0 && i - dot_count > 7)
	{
		_data.push_back(std::make_pair(2, -1));
		return ;
	}
	if (line[4] != '-' || line[7] != '-' || line.substr(10, 3) != " | ")
	{
		_data.push_back(std::make_pair(1, -1));
		return ;
	}
	if (i <= 13)
	{
		_data.push_back(std::make_pair(3, -1));
		return ;
	}
	ss >> month;
	if (month > 12 || month < 1)
	{
		_data.push_back(std::make_pair(4, -1));
		return ;
	}
	ss.clear();
	ss.str(std::string());
	str = line.substr(8, 2);
	ss << str;
	ss >> check;
	if (check > monthArray[month - 1] || check < 1)
	{
		_data.push_back(std::make_pair(4, -1));
		return ;
	}
	ss.clear();
	str = line.substr(12, MAX);
	ss << str;
	ss >> value;
    ss.clear();
    ss << (line.substr(0,4)+line.substr(5,2)+line.substr(8,2));
    ss >> date; 
	if (value >= MAX)
	{
		_data.push_back(std::make_pair(6, -1));
		return ;
	}
	_data.push_back(std::make_pair(date, value));
}

Bitcoin::Bitcoin(const Bitcoin &other) : _path(other._path), _data(other._data)
{
}

Bitcoin &Bitcoin::operator=(const Bitcoin &other)
{
	if (this != &other)
	{
		_path = other._path;
		_data = other._data;
	}
	return (*this);
}

void Bitcoin::loadDataBase()
{
    std::ifstream file("./data/data.csv");
    std::string line;
    int date;
    float  value;
    std::string valueStr;

    if(!file.is_open())
    {
        std::cout << "Data file is invalid." << std::endl;
        exit(1);
    }
    while(std::getline(file, line))
    {  
        if(line[0] == '2')
    {
        std::stringstream ss(line.substr(0,4)+line.substr(5,2)+line.substr(8,2));
    
        ss >> date;
        ss.clear();
        std::stringstream ss1(line.substr(11, MAX));

        ss1 >> value;
      _dataBase.push_back(std::make_pair(date, value));
    }      
    }
    
   
}

std::string Bitcoin::intToString(int num)
{
    std::stringstream ss;
    ss << num;
    return ss.str();
}

void Bitcoin::searchDataBase()
{
    std::vector<std::pair<int, float> >::iterator it;
    std::vector<std::pair<int, float> >::iterator it2;
   
  std::string str;
   int date;
    float value;
    for(it = _data.begin(); it != _data.end(); ++it)
    {
        if(it->second < 0)
        {
            std::cout << SOFT_RED <<_errorsBank[it->first] << RESET << std::endl; 
           
        }
        else
        {
        date = it->first;
       value = it->second;
          for(it2 = _dataBase.begin(); it2 != _dataBase.end(); ++it2)
    {
         if(date < it2->first)
            {
                --it2;
               str = intToString(date);
                std::cout << LIGHT_GREEN << str.substr(0,4) << '-' <<  str.substr(4,2) << '-' << str.substr(6,2) <<  " => "<< value << " = "  << value * it2->second << RESET<< std::endl;
                break;
            }
        
    }
        }
      
    }

}

Bitcoin::~Bitcoin()
{
}