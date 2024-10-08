/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:25:28 by dferjul           #+#    #+#             */
/*   Updated: 2024/08/13 23:25:28 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumainA.hpp"
#include "../include/HumainB.hpp"
#include "../include/Weapon.hpp"

int main()
{
	Weapon club = Weapon("crude spiked club");
	HumanA bob(club, "Bob");
	bob.attack();
	club.setType("Pebble");
	bob.attack();
	//Weapon club = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.attack();
	jim.setWeapon(club);
	club.setType("spoon");
	jim.attack();
	return 0;
}
