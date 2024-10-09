/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:16:40 by dferjul           #+#    #+#             */
/*   Updated: 2024/10/09 16:16:40 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ClapTrap.hpp"

/* int main()
{
	ClapTrap luc("Luc");
	ClapTrap bob("Bob");
	bob.setAttackDamage(5);
	luc.setAttackDamage(1);
	bob.attack(luc.getName());
	luc.takeDamage(5);
	luc.beRepaired(1);
	for (int i = 0; i < 5; i++)
	{
		luc.attack(bob.getName());
		bob.takeDamage(1);
	}
	bob.attack(luc.getName());
	return 0;
} */

int main ()
{
	ClapTrap bob("bob");
	ClapTrap patrick("patrick");
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
}