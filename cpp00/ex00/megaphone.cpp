/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniah <daniah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:55:12 by daniah            #+#    #+#             */
/*   Updated: 2026/01/05 23:08:14 by daniah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	else
	{
		while (i < argc)
		{
			j = 0;
			while (argv[i][j] != '\0')
			{
				std::cout << (char)toupper(argv[i][j]);
				j++;
			}
			i++;
		}
	}
	std::cout << std::endl;
	return (0);
}
