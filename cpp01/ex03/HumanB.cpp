/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniah <daniah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 12:24:51 by daniah            #+#    #+#             */
/*   Updated: 2026/01/07 11:30:45 by daniah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string n)
{
	this->name = n;
	this->weapon = NULL;
}

HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon& w)
{
	this->weapon = &w;
}

void HumanB::attack()
{
	if (this->weapon == NULL)
		std::cout << this->name << " has no weapon" << std::endl;
	else
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}
