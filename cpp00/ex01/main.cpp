/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniah <daniah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:55:12 by daniah            #+#    #+#             */
/*   Updated: 2026/01/05 23:17:18 by daniah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	PhoneBook phoneBook;

	std::string command;
	
	while (1)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
		{
			std::cout << std::endl;
			break;
		}
		
		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else if (command == "EXIT")
			break;
		else
			std::cout << "Invalid command" << std::endl;
	}
	
	return (0);
}