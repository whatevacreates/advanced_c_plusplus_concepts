#include "Sed.hpp"

int	main(int argc, char *argv[])
{
	std::ifstream oldFile;
    std::ofstream newFile;    
    std::string newFileName;
    std::string		line;
   
    size_t			find_value;
    checks(argc, argv, oldFile);
    newFileName = argv[1];
    newFile.open(std::string( newFileName + ".replace").c_str(), std::ios::out);
     std::string s1 = argv[2];
    std::string s2 = argv[3];
	
}



