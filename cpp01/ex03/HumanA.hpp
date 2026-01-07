/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniah <daniah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 11:27:03 by daniah            #+#    #+#             */
/*   Updated: 2026/01/07 11:27:16 by daniah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// HumanA.hpp
#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
private:
	std::string name;
	Weapon& weapon;

public:
	HumanA(std::string n, Weapon& w);
	~HumanA();
	
	void attack();
};

#endif