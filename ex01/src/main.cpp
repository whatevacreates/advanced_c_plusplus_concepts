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

#include "Phonebook.hpp"

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
			//phonebook.exit_phonebook();
			return (0);
		}
		else
			std::cout << "This does not look quite right! Watch out for the right case.\n" << std::endl;
		argc++;
	}
}