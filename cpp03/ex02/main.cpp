/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 00:40:08 by dferjul           #+#    #+#             */
/*   Updated: 2024/09/14 00:40:08 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ClapTrap.hpp"
#include "includes/ScavTrap.hpp"
#include "includes/FragTrap.hpp"
/*
int main()
{
	ScavTrap luc("Luc");
	ClapTrap bob("Bob");
	//luc.attack("Enemy");
	bob.attack("Enemy");
	bob.takeDamage(12);
	bob.beRepaired(2);

	luc.takeDamage(30);
	luc.beRepaired(20);
	luc.guardGate();
	 for (int i = 0; i < 12; i++)
	{
		luc.attack("Enemy");
		//luc.takeDamage(2);
		//bob.beRepaired(2);
	} 
	return 0;
}*/

int main()
{
	FragTrap luc("Luc");
	FragTrap Herve("Herve");
	//FragTrap luc3(luc);
	ClapTrap bob("Bob");

	// luc.attack("Enemy");
	// bob.takeDamage(2);

	// bob.attack("Luc");
	// luc.takeDamage(2);

	bob.beRepaired(3);
	luc.highFivesGuys();
	Herve.highFivesGuys();
	bob.beRepaired(3);
}


