/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:57:31 by gsong             #+#    #+#             */
/*   Updated: 2023/08/14 16:09:13 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int main() {
  PhoneBook phoneBook = PhoneBook();
  std::string    command;

  std::cout << "My PhoneBook" << std::endl;
  std::cout << "command> ";
	while (std::getline(std::cin, command))
	{
		if (command == "EXIT") {
			std::cout << "exit" << std::endl;
			break;
		}
		else if (command == "ADD") {
      phoneBook.AddContact();
      std::cout << "command> ";
    }
		else if (command == "SEARCH") {
			phoneBook.SearchContact();
      std::cout << "command> ";
    }
		else {
			std::cout << "Invalid input - Command\n\n";
      std::cout << "command> ";
		}
	}
  if (std::cin.eof()) {
    std::cout << "Program Exit." << std::endl;
    return (0);
  }
	return (0);
}
