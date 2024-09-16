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

int main()
{
	ClapTrap luc("Luc");
	ClapTrap bob("Bob");
	// luc.attack("Enemy");
	bob.takeDamage(12);
	// bob.beRepaired(2);
	for (int i = 0; i < 12; i++)
	{
		luc.attack("Enemy");
		//luc.takeDamage(2);
		//bob.beRepaired(2);
	}
	return 0;
}