/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumainB.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:26:01 by dferjul           #+#    #+#             */
/*   Updated: 2024/08/13 23:26:01 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumainB.hpp"

HumanB::HumanB(std::string name) : _name(name) {}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void HumanB::attack()
{
	if (_weapon)
	{
		std::cout << _name << " attacks with " << _weapon->getType() << std::endl;
	}
	else
		std::cout << _name << " has no weapon" << std::endl;
}

HumanB::~HumanB() {}