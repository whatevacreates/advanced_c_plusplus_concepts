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
		if (s1.empty())
		{
			oldFile.close();
			throw "s1 cannot be an empty string";
		}
		if (!oldFile.good())
		{
			oldFile.close();
			throw "cannot open a file";
		}
	}
	catch (const char *errMsg)
	{
		std::cerr << "Error2: " << errMsg << std::endl;
		std::exit(1);
	}
}

void Sed::createNewFile(void)
{
	newFile.open(std::string(oldFileName + ".replace").c_str(), std::ios::out);
	if (!newFile.good())
	{
		std::cerr << "Error: Cannot create the new file." << std::endl;
		std::exit(1);
	}
	createNewFileContent();
}

void Sed::createNewFileContent()
{
	size_t	pos;

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
