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
	std::string *str = new std::string(name);
	this->_name = name;
	std::cout << "Zombie " << str << " is created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << str << " is dead" << std::endl;
}

void	Zombie::annouce(void)
{
	std::cout << this->_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}


