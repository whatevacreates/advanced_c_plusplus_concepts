#include "Sed.hpp"

Sed::Sed(char *argv[]) : oldFileName(argv[1]), s1(argv[2]), s2(argv[3])
{
	return ;
}

Sed::~Sed()
{
	return ;
}

void Sed::checks()
{
	try
	{
		oldFile.open(oldFileName, std::ios::in);
		if (!oldFile.good())
			throw "cannot open a file";
		oldFile.close();
	}
	catch (const char *errMsg)
	{
		std::cerr << "Error2: " << errMsg << std::endl;
		oldFile.close();
		std::exit(1);
	}
}

void Sed::createNewFile(void)
{
	newFile.open(std::string(oldFileName + ".replace").c_str(), std::ios::out);
	createNewFileContent();
}

void Sed::createNewFileContent()
{
	size_t	pos;

	oldFile.open(oldFileName, std::ios::in);
	while (std::getline(oldFile, line))
	{
		while ((pos = line.find(s1)) != std::string::npos)
		{
			line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
		}
		newFile << line << '\n';
	}
	oldFile.close();
	newFile.close();
}
