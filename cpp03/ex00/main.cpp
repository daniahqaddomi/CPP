/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dqaddomi <dqaddomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 00:10:23 by daniah            #+#    #+#             */
/*   Updated: 2026/01/18 18:31:05 by dqaddomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap robot1("Player1");
	ClapTrap robot2("Player2");
	
	std::cout << "\n--- Testing attacks ---" << std::endl;
	robot1.attack("Player2");
	robot2.takeDamage(0);
	
	std::cout << "\n--- Testing repair ---" << std::endl;
	robot2.beRepaired(5);
	
	std::cout << "\n--- Testing energy ---" << std::endl;
	int i = 0;
	
	while (i < 10)
	{
		robot1.attack("target");
		i++;
	}
	
	std::cout << "\n--- Testing death ---" << std::endl;
	robot2.takeDamage(50);
	robot2.attack("someone");
	robot2.beRepaired(10);

	std::cout << "\n--- Destructors ---" << std::endl;
	return (0);
}
