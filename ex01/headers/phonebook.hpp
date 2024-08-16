/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:43:59 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/08/16 13:09:30 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "contact.hpp"

class Phonebook
{
    public:
    Phonebook();
    ~Phonebook();
    bool add_contact();
    void search_contact();
    void exit_phonebook();
    private:
    static const int max  = 2;
    Contact contacts[max];
    int contact_count;
};

#endif
