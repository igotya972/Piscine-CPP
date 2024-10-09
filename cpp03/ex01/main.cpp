/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:39:27 by dferjul           #+#    #+#             */
/*   Updated: 2024/10/09 21:39:27 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ScavTrap.hpp"
#include "includes/ClapTrap.hpp"

/* int main()
{
	ScavTrap luc("Luc");
	ClapTrap bob("Bob");
	luc.attack(bob.getName());
	bob.takeDamage(luc.getAttackDamage());
	bob.beRepaired(2);

	luc.beRepaired(20);
	luc.guardGate();
	for (int i = 0; i < 5; i++)
	{
		luc.attack(bob.getName());
		bob.takeDamage(1);
	}
	return 0;
} */

int main()
{
	ScavTrap luc("Luc");
	ClapTrap bob("Bob");

	bob.setAttackDamage(5);
	luc.attack(bob.getName());
	bob.takeDamage(luc.getAttackDamage());

	bob.attack(luc.getName());
	luc.takeDamage(bob.getAttackDamage());

	bob.beRepaired(3);
	luc.beRepaired(3);
	luc.guardGate();
}

/* int main ()
{
	ScavTrap bob("bob");
	ScavTrap patrick("patrick");
	std::cout << std::endl;

	bob.setAttackDamage(5);
	patrick.setAttackDamage(9);

	bob.attack(patrick.getName());
	patrick.takeDamage(bob.getAttackDamage());

	patrick.attack(bob.getName());
	bob.takeDamage(patrick.getAttackDamage());
	patrick.beRepaired(1);

	std::cout << std::endl;
	return 0;
} */