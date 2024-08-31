#ifndef SED_HPP
# define SED_HPP

# include <cstdlib>
# include <fstream>
# include <iostream>
# include <string>

class Sed
{
  public:
	Sed(char *argv[]);
	~Sed();
    void checks();
    void createNewFile();

  private:
	std::string oldFileName;
    std::string newFileName;
	std::ifstream oldFile;
	std::ofstream newFile;
	std::string s1;
	std::string s2;
    std::string line;
    void createNewFileContent();
	
};

#endif