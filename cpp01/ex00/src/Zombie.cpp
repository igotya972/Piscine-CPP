/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 02:54:33 by dferjul           #+#    #+#             */
/*   Updated: 2024/08/11 02:54:33 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->_name = name;
}

Zombie::~Zombie()
{
	std::cout << RED << this->_name << " is dead" << std::endl;
}

void	Zombie::annouce(void)
{
	std::cout << GREEN << _name << " : BraiiiiiiinnnzzzZ..." << RESET << std::endl;
}


