/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniah <daniah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:55:12 by daniah            #+#    #+#             */
/*   Updated: 2026/01/05 23:54:59 by daniah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook
{
private:
	Contact contacts[8];
	int count;
	int index;

public:
	PhoneBook();
	~PhoneBook();
	
	void addContact();
	void searchContact();
	void displayContacts();
	void displayContactDetails(int index);
};

#endif