/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dqaddomi <dqaddomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:58:10 by dqaddomi          #+#    #+#             */
/*   Updated: 2025/11/20 12:34:04 by dqaddomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>

PhoneBook::PhoneBook()
{
	this->contactCount = 0;
	this->oldestIndex = 0;
}

PhoneBook::~PhoneBook()
{
}

static std::string truncateString(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

static std::string getInput(std::string prompt)
{
	std::string input;
	
	while (1)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
		{
			std::cout << std::endl;
			exit(0);
		}
		if (input.length() > 0)
			return (input);
		std::cout << "Field cannot be empty!" << std::endl;
	}
}

void PhoneBook::addContact()
{
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
	
	firstName = getInput("Enter first name: ");
	lastName = getInput("Enter last name: ");
	nickname = getInput("Enter nickname: ");
	phoneNumber = getInput("Enter phone number: ");
	darkestSecret = getInput("Enter darkest secret: ");
	
	this->contacts[this->oldestIndex].setFirstName(firstName);
	this->contacts[this->oldestIndex].setLastName(lastName);
	this->contacts[this->oldestIndex].setNickname(nickname);
	this->contacts[this->oldestIndex].setPhoneNumber(phoneNumber);
	this->contacts[this->oldestIndex].setDarkestSecret(darkestSecret);
	
	this->oldestIndex = (this->oldestIndex + 1) % 8;
	if (this->contactCount < 8)
		this->contactCount++;
	
	std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::displayContacts()
{
	int i;
	
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	
	i = 0;
	while (i < this->contactCount)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << truncateString(this->contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << truncateString(this->contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << truncateString(this->contacts[i].getNickname()) << std::endl;
		i++;
	}
}

void PhoneBook::displayContactDetails(int index)
{
	std::cout << "First Name: " << this->contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << this->contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << this->contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << this->contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << this->contacts[index].getDarkestSecret() << std::endl;
}

void PhoneBook::searchContact()
{
	std::string input;
	int index;
	
	if (this->contactCount == 0)
	{
		std::cout << "Phonebook is empty!" << std::endl;
		return;
	}
	
	this->displayContacts();
	
	std::cout << "Enter the index of the contact: ";
	if (!std::getline(std::cin, input))
	{
		std::cout << std::endl;
		exit(0);
	}
	
	if (input.length() != 1 || input[0] < '0' || input[0] > '7')
	{
		std::cout << "Invalid index!" << std::endl;
		return;
	}
	
	index = input[0] - '0';
	if (index >= this->contactCount)
	{
		std::cout << "Index out of range!" << std::endl;
		return;
	}
	
	this->displayContactDetails(index);
}