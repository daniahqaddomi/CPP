/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniah <daniah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 00:45:45 by daniah            #+#    #+#             */
/*   Updated: 2026/01/17 00:46:59 by daniah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "=== Testing abstract class ===" << std::endl;
	std::cout << "Cannot instantiate AAnimal directly!" << std::endl;
	std::cout << "(Try uncommenting the line below to see compilation error)" << std::endl;
	// AAnimal test;  // This would cause compilation error!
	
	std::cout << "\n=== Creating concrete animals ===" << std::endl;
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	
	std::cout << "\n=== Testing polymorphism ===" << std::endl;
	std::cout << j->getType() << ": ";
	j->makeSound();
	std::cout << i->getType() << ": ";
	i->makeSound();
	
	std::cout << "\n=== Deleting ===" << std::endl;
	delete j;
	delete i;
	
	std::cout << "\n=== Array test ===" << std::endl;
	const int size = 4;
	AAnimal* animals[size];
	
	int idx = 0;
	while (idx < size / 2)
	{
		animals[idx] = new Dog();
		idx++;
	}
	while (idx < size)
	{
		animals[idx] = new Cat();
		idx++;
	}
	
	std::cout << "\nMaking sounds:" << std::endl;
	idx = 0;
	while (idx < size)
	{
		animals[idx]->makeSound();
		idx++;
	}
	
	std::cout << "\nCleaning up:" << std::endl;
	idx = 0;
	while (idx < size)
	{
		delete animals[idx];
		idx++;
	}
	
	return 0;
}
