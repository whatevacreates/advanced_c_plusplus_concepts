/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:43:59 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/08/18 17:17:37 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <cctype>
# include <iostream>
# include <string>

class Contact
{
  public:
	Contact();
	~Contact();
	void display_contact();
	void display_contacts();
	void display_one_contact();
	bool add_fields(int index);
	void create_display_str(int index);
	void clear_fields();
	bool includes_weirds(const std::string &str);

  private:
	bool validate_number(const std::string &str);
  void trim_white_spaces(std::string &str);
	std::string format_input(std::string &str);
  bool check_inputs();
	std::string name;
	std::string lastname;
	std::string nickname;
	std::string number;
	std::string secret;
	std::string display_info;
};

#endif
