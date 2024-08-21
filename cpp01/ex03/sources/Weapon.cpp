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

Weapon::Weapon()
{

}

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon()
{

}

void Weapon::setType(const std::string &newType)
{
	this->type = newType;
}

const std::string &Weapon::getType() const
{
	return this->type;
}