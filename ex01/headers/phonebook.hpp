/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:43:59 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/08/18 21:48:35 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <cctype>
# include <iostream>
# include <string>

class Phonebook
{
  public:
	Phonebook();
	~Phonebook();
	bool add_contact();
	void search_contact();
	void exit_phonebook();
	

  private:
    void display_one_contact(int index);
	static const int max = 8;
	Contact contacts[max];
	int contact_count;
	std::string number_to_display;
};

#endif
