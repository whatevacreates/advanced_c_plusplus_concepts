/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:13:11 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/08/17 19:30:31 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phonebook.hpp"
#include <iostream>
#include <string>

Phonebook::Phonebook() : contact_count(0)
{
	return ;
}

Phonebook::~Phonebook(void)
{
	return ;
}

bool Phonebook::add_contact()
{
	if (contact_count < max)
	{
		if (!contacts[contact_count].add_fields(contact_count))
			return (false);
		contact_count++;
	}
	else if (contact_count == max)
	{
		contacts[contact_count - 1].clear_fields();
		if (!contacts[contact_count - 1].add_fields(contact_count - 1))
			return (false);
	}
	return (true);
}

void Phonebook::search_contact()
{
	int	i;
	int	index;

	i = -1;
	if (contact_count == 0)
	{
		std::cout << "Your Phonebook is empty! Add users first." << std::endl;
		return ;
	}
	while (++i < contact_count)
		contacts[i].display_contacts();
	std::cout << '\n' << "What number would you like to display (1-8)? " << std::endl;
	std::cout << "Press 0 to return (to the main menu." << std::endl;
	std::getline(std::cin, number_to_display);
	index = std::stoul(number_to_display);
	if (index == 0)
		return ;
	display_one_contact(index);
}

void Phonebook::display_one_contact(int index)
{
	if (index > contact_count)
	{
		std::cout << "The contact is not in the phonebook yet!" << std::endl;
		search_contact();
		return ;
	}
	std::cout << "Contact nr: " << index << '\n' << std::endl;
	contacts[index - 1].display_contact();
}

void Phonebook::exit_phonebook()
{
	for (int i = 0; i < contact_count; i++)
	{
		contacts[i].clear_fields();
	}
	contact_count = 0;
	std::cout << "Your phonebook has been cleaned." << std::endl;
}
