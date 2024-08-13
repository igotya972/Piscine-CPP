/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 03:34:31 by dferjul           #+#    #+#             */
/*   Updated: 2024/08/13 03:34:31 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name)
{
	Zombie *zombieHorde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		new (&zombieHorde[i]) Zombie(name);
	}
	return (zombieHorde);
}
