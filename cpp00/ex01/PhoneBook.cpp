/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniah <daniah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:55:12 by daniah            #+#    #+#             */
/*   Updated: 2026/01/05 23:54:59 by daniah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>

PhoneBook::PhoneBook()
{
	this->count = 0;
	this->index = 0;
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
	size_t i;
	bool hasContent;
	
	while (1)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
		{
			std::cout << std::endl;
			exit(0);
		}
		hasContent = false;
		i = 0;
		while (i < input.length())
		{
			if (input[i] != ' ' && input[i] != '\t')
			{
				hasContent = true;
				break;
			}
			i++;
		}
		if (hasContent)
			return (input);
		std::cout << "Field cannot be empty" << std::endl;
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
	
	this->contacts[this->index].setFirstName(firstName);
	this->contacts[this->index].setLastName(lastName);
	this->contacts[this->index].setNickname(nickname);
	this->contacts[this->index].setPhoneNumber(phoneNumber);
	this->contacts[this->index].setDarkestSecret(darkestSecret);
	
	this->index = (this->index + 1) % 8;
	if (this->count < 8)
		this->count++;
	
	std::cout << "Contact added successfully" << std::endl;
}

void PhoneBook::displayContacts()
{
	int i;
	
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	
	i = 0;
	while (i < this->count)
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
	
	if (this->count == 0)
	{
		std::cout << "Phonebook is empty" << std::endl;
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
		std::cout << "Invalid index" << std::endl;
		return;
	}
	
	index = input[0] - '0';
	if (index >= this->count)
	{
		std::cout << "Index out of range" << std::endl;
		return;
	}
	
	this->displayContactDetails(index);
}

