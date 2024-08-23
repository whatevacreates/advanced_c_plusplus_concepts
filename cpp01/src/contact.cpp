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

bool Contact::check_inputs(void)
{
	if (name == "" || lastname == "" || nickname == "" || number == ""
		|| secret == "")
		{
			std::cout << "Contact cannot have empty fields! Try again." << std::endl;
			return (false);
		}
		
		/*
	trim_white_spaces(name);
	trim_white_spaces(lastname);
	trim_white_spaces(nickname);
	trim_white_spaces(number);
	trim_white_spaces(secret);*/
	return (true);
}

void Contact::trim_white_spaces(std::string &str)
{
	std::string new_str;
	std::cout << "length before" << str.length() << std::endl;
	size_t i = 0;
	while (std::isspace(str[i]) && i < str.length())
	{
		std::cout << "space loop -----------" << std::endl;
		i++;
	}
		
	while(!std::isspace(str[i]) && i < str.length())
	{
		std::cout << "assignement space loop -----------" << std::endl;
		new_str += str[i++];
	}
	str = new_str;
	std::cout << "length after" << str.length() << std::endl;
}

// std::string(start, end + 1);

/*
std::string trim(const std::string& str) {
	// Find the first non-whitespace character
	auto start = str.begin(); // from std::string::begin() (from <string>)
	while (start != str.end() && std::isspace(*start)) {
		// std::isspace is from <cctype>
		++start;
	}

	// Find the last non-whitespace character
	auto end = str.end(); // from std::string::end() (from <string>)
	do {
		--end;
	} while (std::distance(start, end) > 0 && std::isspace(*end));
		// std::distance is from <algorithm>

	// Return the trimmed string
	return (std::string(start, end + 1)); // from std::string (from <string>)
}*/

void Contact::display_contacts()
{
	std::cout << std::endl;
	std::cout << display_info << std::endl;
}

void Contact::display_contact()
{
	std::cout << '\n' << std::endl;
	std::cout << "Name:" << name << std::endl;
	std::cout << "Lastname:" << lastname << std::endl;
	std::cout << "Nickname:" << nickname << std::endl;
	std::cout << "Phone number:" << number << std::endl;
	std::cout << "Darkest Secret:" << secret << '\n' << std::endl;
}

void Contact::create_display_str(int index)
{
	std::string num = std::to_string(index + 1);
	display_info += format_input(num);
	display_info += format_input(name);
	display_info += format_input(lastname);
	display_info += format_input(nickname);
}

std::string Contact::format_input(std::string &str)
{
	std::string new_str = str.substr(0, 9);
	if (str.size() > 9)
	{
		new_str += '.';
		new_str += '|';
		return (new_str);
	}
	std::string new_str2(10 - new_str.size(), ' ');
	new_str2 += str.substr(0, std::min(str.size(), size_t(10)));
	new_str2 += '|';
	return (new_str2);
}
bool Contact::validate_number(const std::string &str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
		{
			std::cout << "Try Again: Your number contains non-numeric characters.\n" << std::endl;
			return (false);
		}
	}
	return (true);
}

void Contact::clear_fields()
{
	name.clear();
	lastname.clear();
	nickname.clear();
	number.clear();
	secret.clear();
	display_info.clear();
}