/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniah <daniah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 00:35:44 by daniah            #+#    #+#             */
/*   Updated: 2026/01/17 00:52:53 by daniah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "=== Testing correct polymorphism ===" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << "\nTypes:" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	
	std::cout << "\nSounds (should be specific):" << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
	std::cout << "\nDeleting:" << std::endl;
	delete meta;
	delete j;
	delete i;
	
	std::cout << "\n=== Testing wrong polymorphism ===" << std::endl;
	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_cat = new WrongCat();
	
	std::cout << "\nTypes:" << std::endl;
	std::cout << wrong_cat->getType() << " " << std::endl;
	
	std::cout << "\nSounds (WrongCat will output WrongAnimal sound):" << std::endl;
	wrong_cat->makeSound(); //will output WrongAnimal sound!
	wrong_meta->makeSound();
	
	std::cout << "\nDeleting:" << std::endl;
	delete wrong_meta;
	delete wrong_cat;
	
	std::cout << "\n=== Additional tests ===" << std::endl;
	std::cout << "\n--- Testing stack objects ---" << std::endl;
	{
		Animal animal;
		Dog dog;
		Cat cat;
		std::cout << "\nMaking sounds:" << std::endl;
		animal.makeSound();
		dog.makeSound();
		cat.makeSound();
	}
	
	std::cout << "\n--- Testing copy constructors ---" << std::endl;
	{
		Dog originalDog;
		Dog copiedDog(originalDog);
		std::cout << "Original type: " << originalDog.getType() << std::endl;
		std::cout << "Copied type: " << copiedDog.getType() << std::endl;
	}
	
	std::cout << "\n--- Testing assignment operator ---" << std::endl;
	{
		Cat cat1;
		Cat cat2;
		cat1 = cat2;
		std::cout << "After assignment, cat1 type: " << cat1.getType() << std::endl;
	}
	
	std::cout << "\n--- Testing array of Animals ---" << std::endl;
	{
		const Animal* animals[4];
		animals[0] = new Animal();
		animals[1] = new Dog();
		animals[2] = new Cat();
		animals[3] = new Dog();
		
		std::cout << "\nMaking sounds from array:" << std::endl;
		for (int idx = 0; idx < 4; idx++)
		{
			std::cout << "Animal[" << idx << "] type: " << animals[idx]->getType() << " - ";
			animals[idx]->makeSound();
		}
		
		std::cout << "\nDeleting array:" << std::endl;
		for (int idx = 0; idx < 4; idx++)
			delete animals[idx];
	}
	
	return 0;
}