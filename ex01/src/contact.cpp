/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:08:07 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/08/15 17:26:09 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phonebook.hpp"

Contact ::Contact(void) : name(""), lastname(""), nickname(""), number(""), secret("")
{
    
	return ;
}

/*	Desctructor	*/
Contact::~Contact(void) {
	return ;
}


void Contact::add_fields(void)
{
    std::cout << "\nMy name is: ";
    std::getline(std::cin, name);
    std::cout << "My last name is: ";
    std::getline(std::cin, lastname);
    std::cout << "My nickname is: ";
    std::getline(std::cin, nickname);
    std::cout << "My phonenumber: ";
    std::getline(std::cin, number);
    std::cout << "And my Darkest Secret is: ";
    std::getline(std::cin, secret);
}

void Contact::display_contact(void)
{
    std::cout << '\n' <<std::endl;
    std::cout << "Name:" << name <<std::endl ;
    std::cout << "Lastname:" << lastname <<std::endl;
    std::cout << "Nickname:" << nickname << std::endl;
    std::cout << "Phone number:" << number << std::endl;
    std::cout << "Darkest Secret:" << secret << '\n' << std::endl;
}