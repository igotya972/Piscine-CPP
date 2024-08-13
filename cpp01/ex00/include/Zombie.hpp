/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 02:54:37 by dferjul           #+#    #+#             */
/*   Updated: 2024/08/11 02:54:37 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "colors.hpp"

class Zombie
{
private:
	std::string _name;
public:
	Zombie(std::string name);
	~Zombie();
	void	annouce(void);
	Zombie	*newZombie(std::string name);
};
