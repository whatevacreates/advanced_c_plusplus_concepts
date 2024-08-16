/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:08:07 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/08/16 15:57:33 by eprzybyl         ###   ########.fr       */
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


bool Contact::add_fields(void)
{
    std::cout << "\nMy name is: ";
    std::getline(std::cin, name);
      format_input(name);
    std::cout << "My last name is: ";
    std::getline(std::cin, lastname);     
    std::cout << "My nickname is: ";
    std::getline(std::cin, nickname);   
    std::cout << "My phonenumber: ";
    std::getline(std::cin, number);
        if(!validate_number(number))
    return false;
    std::cout << "And my Darkest Secret is: ";
    std::getline(std::cin, secret);
    return true;
}

void Contact::display_contacts(void)
{
    std::cout << '\n' <<std::endl;
    std::cout << "Name:" << name <<std::endl ;
    std::cout << "Lastname:" << lastname <<std::endl;
    std::cout << "Nickname:" << nickname << std::endl;
    std::cout << "Phone number:" << number << std::endl;
    std::cout << "Darkest Secret:" << secret << '\n' << std::endl;
}

void Contact::format_input(std::string& str)
{
    std::string new_str = str.substr(0, 9);  // Get the first 9 characters of str
    if (str.size() > 9) {
        
        new_str += '.'; 
       new_str += '|'; 
        str = new_str;
        std::cout << str << '\n' ;
        return; // Add '.' if str is longer than 9 characters
    }
    std::string new_str2(10 - new_str.size(), ' ');  // Fill new_str2 with the remaining dots
    new_str2 += str.substr(0, std::min(str.size(), size_t(10)));  // Append the first 10 chars of str to new_str2
     new_str2 += '|'; 
    str = new_str2;
    std::cout << str << '\n' ;

   
}
bool Contact::validate_number(const std::string& str)
{
   for(size_t i = 0; i < str.size(); i++)
   {
    if(!std::isalnum(str[i]))
    return false;
   }
   return true;
}