/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dqaddomi <dqaddomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 11:04:36 by daniah            #+#    #+#             */
/*   Updated: 2026/01/15 17:32:04 by dqaddomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie*		heapZombie;
	
	std::cout << "Creating heap zombie:" << std::endl;
	heapZombie = newZombie("Ketchup");
	heapZombie->announce();
	
	std::cout << "\nCreating stack zombie:" << std::endl;
	randomChump("Potato");
	
	std::cout << "\nDeleting heap zombie:" << std::endl;
	delete heapZombie;
	
	std::cout << "\nProgram ending..." << std::endl;
	return (0);
}