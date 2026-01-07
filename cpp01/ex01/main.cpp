/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniah <daniah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 11:07:38 by daniah            #+#    #+#             */
/*   Updated: 2026/01/07 11:12:07 by daniah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int     hordeSize = 5;
	Zombie* horde;
	int     i;
	
	std::cout << "Creating horde of " << hordeSize << " zombies:" << std::endl;
	horde = zombieHorde(hordeSize, "Walker");
	
	std::cout << "\nZombies announcing themselves:" << std::endl;
	i = 0;
	while (i < hordeSize)
	{
		horde[i].announce();
		i++;
	}
	
	std::cout << "\nDeleting the horde:" << std::endl;
	delete[] horde;
	
	std::cout << "\nProgram ending..." << std::endl;
	return 0;
}
