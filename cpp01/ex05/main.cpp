/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniah <daniah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 06:34:26 by daniah            #+#    #+#             */
/*   Updated: 2026/01/09 23:43:11 by daniah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Harl.hpp"

int main()
{
	Harl harl;
	
	std::cout << "Testing Harl's complaints:" << std::endl;
	std::cout << "========================================" << std::endl;
	std::cout << std::endl;
	
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("RANDOM");
	
	return 0;
}
