/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dqaddomi <dqaddomi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 11:16:40 by daniah            #+#    #+#             */
/*   Updated: 2026/01/15 17:38:42 by dqaddomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str; //pointer to str
	std::string& stringREF = str; //reference to str
	
	std::cout << "Memory address of str:        " << &str << std::endl;
	std::cout << "Memory address in stringPTR:  " << stringPTR << std::endl;
	std::cout << "Memory address in stringREF:  " << &stringREF << std::endl;
	
	std::cout << std::endl;
	
	std::cout << "Value of str:        " << str << std::endl;
	std::cout << "Value of stringPTR:  " << *stringPTR << std::endl;
	std::cout << "Value of stringREF:  " << stringREF << std::endl;
	
	return (0);
}
