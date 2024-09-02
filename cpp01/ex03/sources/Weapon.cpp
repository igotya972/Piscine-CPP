/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:25:39 by dferjul           #+#    #+#             */
/*   Updated: 2024/08/13 23:25:39 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"


Weapon::Weapon(std::string type)
{
	this->type = type;
}

void Weapon::setType(std::string newType)
{
	this->type = newType;
}

const std::string &Weapon::getType()
{
	return this->type;
}

Weapon::~Weapon() {}