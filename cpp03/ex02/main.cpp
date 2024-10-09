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

/* int main()
{
	ScavTrap luc("Luc");
	ClapTrap bob("Bob");
	//luc.attack("Enemy");
	bob.attack("Enemy");
	bob.takeDamage(luc.getAttackDamage());
	bob.beRepaired(2);

	luc.takeDamage(bob.getAttackDamage());
	luc.beRepaired(20);
	luc.guardGate();
	 for (int i = 0; i < 3; i++)
	{
		luc.attack(bob.getName());
		bob.takeDamage(luc.getAttackDamage());
	} 
	return 0;
} */

int main()
{
	//ClapTrap bob("Bob");
	FragTrap luc("Luc");
	FragTrap Herve("Herve");
	//FragTrap luc3(luc);

	// luc.attack(bob.getName());
	// bob.takeDamage(luc.getAttackDamage());

	Herve.attack(luc.getName());
	luc.takeDamage(Herve.getAttackDamage());

	luc.beRepaired(3);
	luc.highFivesGuys();
	Herve.highFivesGuys();
	luc.beRepaired(3);
}

/* int main()
{
	ScavTrap luc("Luc");
	FragTrap herve("Herve");
	herve.attack(luc.getName());
	luc.takeDamage(herve.getAttackDamage());
	luc.beRepaired(1);
	for (int i = 0; i < 3; i++)
	{
		luc.attack(herve.getName());
		herve.takeDamage(luc.getAttackDamage());
	}
	herve.attack(luc.getName());
	luc.guardGate();
	herve.highFivesGuys();
	return 0;
} */
