/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniah <daniah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 11:08:15 by daniah            #+#    #+#             */
/*   Updated: 2026/01/07 11:12:14 by daniah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* horde;
	int i;
	
	if (N <= 0)
		return NULL;
	
	horde = new Zombie[N];
	
	i = 0;
	while (i < N)
	{
		horde[i].setName(name);
		i++;
	}
	
	return horde;
}
