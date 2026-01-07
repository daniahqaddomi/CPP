/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniah <daniah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 11:16:40 by daniah            #+#    #+#             */
/*   Updated: 2026/01/07 11:17:24 by daniah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string* stringPTR = &str;
	std::string& stringREF = str;
	
	std::cout << "Memory address of str:        " << &str << std::endl;
	std::cout << "Memory address in stringPTR:  " << stringPTR << std::endl;
	std::cout << "Memory address in stringREF:  " << &stringREF << std::endl;
	
	std::cout << std::endl;
	
	std::cout << "Value of str:        " << str << std::endl;
	std::cout << "Value of stringPTR:  " << *stringPTR << std::endl;
	std::cout << "Value of stringREF:  " << stringREF << std::endl;
	
	return 0;
}
