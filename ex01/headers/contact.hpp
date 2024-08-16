/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:43:59 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/08/16 15:49:31 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <cctype>

class Contact
{
    public:
    Contact();
    ~Contact();
    void display_contacts();
   void format_input(std::string& str);
      bool validate_number(const std::string& str);
    void display_one_contact();
    bool add_fields();
    
    private:
    std::string name;
    std::string lastname;
    std::string nickname;
    std::string number;
    std::string secret;
    //int index;
};

#endif
