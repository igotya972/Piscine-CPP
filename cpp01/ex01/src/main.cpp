/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 03:31:53 by dferjul           #+#    #+#             */
/*   Updated: 2024/08/13 03:31:53 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int main()
{
	Zombie *zombie = zombieHorde(5, "Carlos");
	int i = 0;
	while (i < 5)
	{
		zombie[i].announce();
		i++;
	}
	delete[] zombie;
	return (0);
}