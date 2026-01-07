/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniah <daniah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 11:26:26 by daniah            #+#    #+#             */
/*   Updated: 2026/01/07 11:28:58 by daniah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
private:
	std::string name;
	Weapon* weapon;

public:
	HumanB(std::string n);
	~HumanB();
	
	void setWeapon(Weapon& w);
	void attack();
};

#endif