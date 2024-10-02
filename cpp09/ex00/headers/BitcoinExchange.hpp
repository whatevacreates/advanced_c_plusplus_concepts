#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <exception>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>
#define WRONG_YEAR 1
#define WRONG_VALUE 2
#define MAX std::numeric_limits<int>::max()


class Bitcoin
{
    private:
    std::string _path;
    std::map<std::string, float> _data;

    public:
    Bitcoin();
    Bitcoin(const std::string path);
    ~Bitcoin();
    Bitcoin(const Bitcoin& other);
    Bitcoin& operator=(const Bitcoin& other);
    void exchange();
   void validateLine(std::string &line);


};
#endif