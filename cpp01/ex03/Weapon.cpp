/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniah <daniah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 12:18:06 by daniah            #+#    #+#             */
/*   Updated: 2026/01/07 11:30:32 by daniah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Weapon.cpp
#include "Weapon.hpp"

Weapon::Weapon(std::string t)
{
	this->type = t;
}

Weapon::~Weapon()
{
}

const std::string& Weapon::getType() const
{
	return this->type;
}

void Weapon::setType(std::string t)
{
	this->type = t;
}








