/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:17:11 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/08/18 22:34:51 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Contact.hpp"
#include "Phonebook.hpp"
#include <iostream>
#include <string>

bool includes_weirds(const std::string &str)
{

	 if (std::cin.eof()) {
            std::cout << "EOF detected. Exiting..." << std::endl;
            return true;
        }
    else if (str.empty()) {
            std::cout << "ENTERRRRR PRESSED" << std::endl;
            return false;
        }
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!(std::isdigit(str[i]) && !std::isalpha(str[i])))
		{
			return (false);
		}
	}
	return (true);
}


int	main(int argc, char *argv[])
{
	std::string word;
	Phonebook phonebook;

	(void)argv;
	if(argc > 1)
	{
		std::cout << "Launch the phonebook just by typing ./phonebook" << std::endl;
		return -1;
	}
	

	while (1)
	{
		std::cout << "Enter your prompt: ADD, SEARCH or EXIT: " << std::endl;
		std::getline(std::cin, word);
		if (word == "ADD")
			phonebook.add_contact();
		else if (word == "SEARCH")
			phonebook.search_contact();
		else if (word == "EXIT")
		{
			return (0);
		}
		else
		{
			
			if(includes_weirds(word))
			{
				std::cout << "Your input contains forbidden characters. The program will exit. Try again later.\n" << std::endl;
				return -1;
			} else
			{
				std::cout << "This does not look quite right! Enter your command again." << std::endl;
			}
			
		}

	}
}

