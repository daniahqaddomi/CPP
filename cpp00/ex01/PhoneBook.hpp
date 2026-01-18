/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dqaddomi <dqaddomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:57:49 by dqaddomi          #+#    #+#             */
/*   Updated: 2025/11/20 12:00:11 by dqaddomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// PhoneBook.hpp
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook
{
private:
	Contact contacts[8];
	int contactCount;
	int oldestIndex;

public:
	PhoneBook();
	~PhoneBook();
	
	void addContact();
	void searchContact();
	void displayContacts();
	void displayContactDetails(int index);
};

#endif