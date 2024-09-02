/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumainA.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:26:05 by dferjul           #+#    #+#             */
/*   Updated: 2024/08/13 23:26:05 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumainA.hpp"

HumanA::HumanA(Weapon &weapon, std::string name) : _weapon(weapon), _name(name) {}

void HumanA::attack()
{
	std::cout << _name << " attacks with " << _weapon.getType() << std::endl;
}

HumanA::~HumanA() {}