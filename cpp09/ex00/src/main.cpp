
#include "Utils.hpp"
#include "BitcoinExchange.hpp"

void checkArguments(int argc, char *argv[])
{std::ifstream file;
    if(argc != 2)
    std::cerr << "Wrong number of arguments" << std::endl;
    try
    { 
        file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
     file.open( argv[1]);
    }
    catch(const std::exception &e)
    {

        std::cout << BRIGHT_RED << "Error caught: " << e.what() << RESET << std::endl;
        std::cout << B_SOFTBLUE <<  ":::>>> Launch btc with the correct path to the input file." << RESET <<std::endl;
        exit(1);
    }
file.close();

}

int main(int argc, char *argv[])
{
    checkArguments(argc, argv);
    Bitcoin ex(argv[1]);

}
