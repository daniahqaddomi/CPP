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

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "=== Testing subject requirements ===" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	delete j;
	delete i;
	
	std::cout << "\n=== Testing array of animals ===" << std::endl;
	const int size = 6;
	Animal* animals[size];
	
	std::cout << "\nCreating Dogs:" << std::endl;
	int idx = 0;
	while (idx < size / 2)
	{
		animals[idx] = new Dog();
		idx++;
	}
	
	std::cout << "\nCreating Cats:" << std::endl;
	while (idx < size)
	{
		animals[idx] = new Cat();
		idx++;
	}
	
	std::cout << "\n=== Making sounds ===" << std::endl;
	idx = 0;
	while (idx < size)
	{
		std::cout << animals[idx]->getType() << ": ";
		animals[idx]->makeSound();
		idx++;
	}
	
	std::cout << "\n=== Testing deep copy ===" << std::endl;
	Dog original;
	original.getBrain()->setIdea(0, "I am a good dog");
	original.getBrain()->setIdea(1, "I like bones");
	
	std::cout << "\nCopying dog:" << std::endl;
	Dog copy = original;
	
	std::cout << "\nOriginal ideas:" << std::endl;
	std::cout << original.getBrain()->getIdea(0) << std::endl;
	std::cout << original.getBrain()->getIdea(1) << std::endl;
	
	std::cout << "\nCopy ideas:" << std::endl;
	std::cout << copy.getBrain()->getIdea(0) << std::endl;
	std::cout << copy.getBrain()->getIdea(1) << std::endl;
	
	std::cout << "\nChanging copy's ideas:" << std::endl;
	copy.getBrain()->setIdea(0, "I am a different dog");
	
	std::cout << "\nOriginal idea 0: " << original.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copy idea 0: " << copy.getBrain()->getIdea(0) << std::endl;
	std::cout << "(They should be different - deep copy works!)" << std::endl;
	
	std::cout << "\n=== Deleting animals ===" << std::endl;
	idx = 0;
	while (idx < size)
	{
		delete animals[idx];
		idx++;
	}
	
	std::cout << "\n=== End ===" << std::endl;
	return 0;
}
