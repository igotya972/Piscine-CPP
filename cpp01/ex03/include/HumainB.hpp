/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumainB.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:25:14 by dferjul           #+#    #+#             */
/*   Updated: 2024/08/13 23:25:14 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanB
{
	private:
		Weapon *_weapon;
		std::string _name;
	public:
		HumanB();
		HumanB(Weapon *weapon, std::string name);
		~HumanB();
		void attack();
};