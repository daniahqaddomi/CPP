/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dqaddomi <dqaddomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 00:10:23 by daniah            #+#    #+#             */
/*   Updated: 2026/01/18 18:11:35 by dqaddomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->name = "Default";
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
	std::cout << "ClapTrap " << this->name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energy_points == 0)
	{
		std::cout << "ClapTrap " << this->name << " has no energy to attack!" << std::endl;
		return;
	}
	if (this->hit_points == 0)
	{
		std::cout << "ClapTrap " << this->name << " is dead and cannot attack!" << std::endl;
		return;
	}
	
	this->energy_points--;
	std::cout << "ClapTrap " << this->name << " attacks " << target;
	std::cout << ", causing " << this->attack_damage << " points of damage" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points == 0)
	{
		std::cout << "ClapTrap " << this->name << " is already dead!" << std::endl;
		return;
	}
	
	if (amount > 2147483647u)
	{
		std::cout << "ClapTrap " << this->name << " cannot take negative damage" << std::endl;
		return;
	}
	
	if (amount >= this->hit_points)
		this->hit_points = 0;
	else
		this->hit_points -= amount;
	
	std::cout << "ClapTrap " << this->name << " takes " << amount << " damage ";
	std::cout << "HP: " << this->hit_points << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energy_points == 0)
	{
		std::cout << "ClapTrap " << this->name << " has no energy to repair" << std::endl;
		return;
	}
	if (this->hit_points == 0)
	{
		std::cout << "ClapTrap " << this->name << " is dead and cannot repair" << std::endl;
		return;
	}
	
	this->energy_points--;
	this->hit_points += amount;
	std::cout << "ClapTrap " << this->name << " repairs itself for " << amount << " HP! ";
	std::cout << "HP: " << this->hit_points << std::endl;
}
