
#include "Utils.hpp"
#include "BitcoinExchange.hpp"

void checkArguments(int argc, char *argv[])
{
    if(argc != 2)
    std::cerr << "Wrong number of arguments" << std::endl;
std::cout << argv[1] << std::endl;
    try
    {
    
    std::ifstream file;
       file.open( argv[1]);
    }
    catch(const std::exception &e)
    {

        std::cout << "Error caught: " << e.what() << std::endl;
        std::cout << "Launch btc with the correct path to the input file." <<std::endl;
        exit(1);
    }


}

int main(int argc, char *argv[])
{
    checkArguments(argc, argv);

std::cout << "check" << std::endl;
}
