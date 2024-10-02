#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <exception>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>


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
    bool validateLine(std::string &line);


};
#endif