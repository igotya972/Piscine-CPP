/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTra.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 00:54:06 by dferjul           #+#    #+#             */
/*   Updated: 2024/09/14 00:54:06 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"


ClapTrap::ClapTrap(std::string name) : _name(name),_hitPoints(10), _energyPoints(10), _attackDamage(1)
{
	std::cout << "ClapTrap " << _name << " created" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destroyed" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0 || _energyPoints <= 0)
	{
		if (_hitPoints <= 0)
			std::cout << "ClapTrap " << _name << " has no hit points left" << std::endl;
		else if (_energyPoints <= 0)
			std::cout << "ClapTrap " << _name << " has no energy points left" << std::endl;
		return;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " has no hit points left" << std::endl;
		return;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
		if (_hitPoints - amount <= 0)
			_hitPoints = 0;
		else
			_hitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0 || _energyPoints <= 0)
	{
		if (_hitPoints <= 0)
			std::cout << "ClapTrap " << _name << " has no hit points left" << std::endl;
		else if (_energyPoints <= 0)
			std::cout << "ClapTrap " << _name << " has no energy points left" << std::endl;
		return;
	}
	else
	{
		std::cout << "ClapTrap " << _name << " is repaired for " << amount << " points!" << std::endl;
		_hitPoints += amount;
		_energyPoints--;
	}
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy)
{
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_hitPoints = copy._hitPoints;
		this->_energyPoints = copy._energyPoints;
		this->_attackDamage = copy._attackDamage;
	}
	return *this;
}
