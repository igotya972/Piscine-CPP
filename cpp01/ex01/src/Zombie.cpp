/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 03:34:00 by dferjul           #+#    #+#             */
/*   Updated: 2024/08/13 03:34:00 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie::Zombie()
{
	this->_name = "Ramdom";
}

Zombie::Zombie(std::string name)
{
	this->_name = name;
}

void	Zombie::announce()
{
	std::cout << GREEN << this->_name << " is born" << RESET << std::endl;
}

Zombie::~Zombie()
{
	std::cout << RED << "Zombie " << this->_name << " is dead" << RESET << std::endl;
}