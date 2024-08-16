/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:13:11 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/08/16 12:20:53 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>
#include <string>
#include "contact.hpp"

Phonebook::Phonebook() : contact_count(0) {
    return;
}


/*	Desctructor	*/
Phonebook::~Phonebook(void) {
	return ;
}


void Phonebook:: add_contact()
{
    if(contact_count < max)
    {
       contacts[contact_count].add_fields();
        contact_count++;
    }else if(contact_count == max)
    {
        contacts[contact_count-1].add_fields();
    }
}

void Phonebook:: search_contact()
{ 
    int i = -1;
    while(++i < contact_count)  
          contacts[i].display_contacts();
}

void Phonebook:: exit_phonebook()
{
    std::cout << "exiting bye" << std::endl;
}
