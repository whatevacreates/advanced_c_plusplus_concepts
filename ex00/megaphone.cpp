/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eprzybyl <eprzybyl@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:06:45 by eprzybyl          #+#    #+#             */
/*   Updated: 2024/08/13 13:29:11 by eprzybyl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype> 
#include <string> 

int main(int argc, char* argv[]) {
    if (argc > 1) {
    for (size_t i = 1; i < (size_t)argc; i++)
    {
        std::string arg = argv[i]; 
        for (size_t j = 0; j < arg.length(); j++) {
            arg[j] = std::toupper(static_cast<unsigned char>(arg[j]));  
        }

        std::cout << arg;
    }
    } else {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    }
    
std:: cout << "\n";
    return 0;
}
