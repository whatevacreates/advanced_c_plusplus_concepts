
#include "phonebook.hpp"

int	main(int argc, char *argv[])
{
	std::string word;
	Phonebook phonebook;

	(void)argv;

	while (argc)
	{
		std::cout << "Enter your prompt: ADD, SEARCH or EXIT: " << std::endl;
		std::getline(std::cin, word);
		if (word == "ADD")
			phonebook.add_contact();
		else if (word == "SEARCH")
			phonebook.search_contact();
		else if (word == "EXIT")
		{
			phonebook.exit_phonebook();
			return (0);
		}
		else
			std::cout << "This does not look quite right! Watch out for the right case.\n" << std::endl;
		argc++;
	}
}