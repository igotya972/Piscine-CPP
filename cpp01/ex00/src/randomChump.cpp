/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 02:54:31 by dferjul           #+#    #+#             */
/*   Updated: 2024/08/11 02:54:31 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie zombie(name);
	zombie.annouce();
	//std::cout << MAGENTA << name << " : BraiiiiiiinnnzzzZ" << RESET << std::endl;
	//std::cout << RED << "Foo is dead" << RESET << std::endl;
}
