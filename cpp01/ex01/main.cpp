/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dqaddomi <dqaddomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 11:07:38 by daniah            #+#    #+#             */
/*   Updated: 2026/01/15 18:22:44 by dqaddomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int     hordeSize = 7;
	Zombie* horde;
	int     i;
	
	std::cout << "Creating horde of " << hordeSize << " zombies:" << std::endl;
	horde = zombieHorde(hordeSize, "Zombie");
	
	std::cout << "\nZombies announcing themselves:" << std::endl;
	i = 0;
	while (i < hordeSize)
	{
		horde[i].announce();
		i++;
	}
	
	std::cout << "\nDeleting the zombies horde:" << std::endl;
	delete[] horde;
	
	std::cout << "\nProgram ending..." << std::endl;
	return (0);
}
