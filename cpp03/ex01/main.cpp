/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniah <daniah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 00:19:06 by daniah            #+#    #+#             */
/*   Updated: 2026/01/17 00:19:29 by daniah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	std::cout << "=== Creating ClapTrap ===" << std::endl;
	ClapTrap clap("Clappy");
	
	std::cout << "\n=== Creating ScavTrap ===" << std::endl;
	ScavTrap scav("Scavvy");
	
	std::cout << "\n=== Testing ClapTrap ===" << std::endl;
	clap.attack("enemy");
	clap.takeDamage(5);
	clap.beRepaired(3);
	
	std::cout << "\n=== Testing ScavTrap ===" << std::endl;
	scav.attack("big enemy");
	scav.takeDamage(30);
	scav.beRepaired(20);
	scav.guardGate();
	
	std::cout << "\n=== Destructors (reverse order) ===" << std::endl;
	return 0;
}