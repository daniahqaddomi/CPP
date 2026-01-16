/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniah <daniah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:26:36 by daniah            #+#    #+#             */
/*   Updated: 2026/01/17 00:27:08 by daniah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::cout << "=== Creating robots ===" << std::endl;
	ClapTrap clap("Clappy");
	ScavTrap scav("Scavvy");
	FragTrap frag("Fraggy");
	
	std::cout << "\n=== ClapTrap actions ===" << std::endl;
	clap.attack("target1");
	clap.takeDamage(5);
	clap.beRepaired(3);
	
	std::cout << "\n=== ScavTrap actions ===" << std::endl;
	scav.attack("target2");
	scav.takeDamage(30);
	scav.guardGate();
	
	std::cout << "\n=== FragTrap actions ===" << std::endl;
	frag.attack("target3");
	frag.takeDamage(40);
	frag.beRepaired(20);
	frag.highFivesGuys();
	
	std::cout << "\n=== Copy test ===" << std::endl;
	FragTrap frag_copy(frag);
	frag_copy.highFivesGuys();
	
	std::cout << "\n=== Destructors ===" << std::endl;
	return 0;
}