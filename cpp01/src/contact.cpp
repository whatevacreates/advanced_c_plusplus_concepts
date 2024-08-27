/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:08:07 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/08/18 16:13:53 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phonebook.hpp"

Contact ::Contact(void) : name(""), lastname(""), nickname(""), number(""),
	secret(""), display_info("") {
		return; }

/*	Desctructor	*/
Contact::~Contact(void) {return; };

bool Contact::add_fields(int index)
{
	std::cout << "\nMy Name is: ";
	std::getline(std::cin, name);
	std::cout << "My Last Name is: ";
	std::getline(std::cin, lastname);
	std::cout << "My Nickname is: ";
	std::getline(std::cin, nickname);
	std::cout << "My Phone Number: ";
	std::getline(std::cin, number);
	if (!validate_number(number))
		return (false);
	std::cout << "And my Darkest Secret is: ";
	std::getline(std::cin, secret);
	if (!check_inputs())
		return (false);
	std::cout << std::endl;
	create_display_str(index);
	return (true);
}

