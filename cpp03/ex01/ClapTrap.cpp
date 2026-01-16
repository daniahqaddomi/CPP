/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniah <daniah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 00:10:23 by daniah            #+#    #+#             */
/*   Updated: 2026/01/17 00:12:09 by daniah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->_name = "Default";
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_hit_points = 10;
	this->_energy_points = 10;
	this->_attack_damage = 0;
	std::cout << "ClapTrap " << this->_name << " constructor called" << std::endl;
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
		this->_name = other._name;
		this->_hit_points = other._hit_points;
		this->_energy_points = other._energy_points;
		this->_attack_damage = other._attack_damage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energy_points == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy to attack!" << std::endl;
		return;
	}
	if (this->_hit_points == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead and cannot attack!" << std::endl;
		return;
	}
	
	this->_energy_points--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target;
	std::cout << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
		return;
	}
	
	if (amount >= this->_hit_points)
		this->_hit_points = 0;
	else
		this->_hit_points -= amount;
	
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage! ";
	std::cout << "HP: " << this->_hit_points << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_points == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy to repair!" << std::endl;
		return;
	}
	if (this->_hit_points == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead and cannot repair!" << std::endl;
		return;
	}
	
	this->_energy_points--;
	this->_hit_points += amount;
	std::cout << "ClapTrap " << this->_name << " repairs itself for " << amount << " HP! ";
	std::cout << "HP: " << this->_hit_points << std::endl;
}
