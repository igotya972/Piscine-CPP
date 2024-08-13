/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 02:54:24 by dferjul           #+#    #+#             */
/*   Updated: 2024/08/11 02:54:24 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main()
{
	Zombie *zombie = newZombie("Rodolphe");
	zombie->annouce();
	delete zombie;
	randomChump("Foo");
	return (0);
}
