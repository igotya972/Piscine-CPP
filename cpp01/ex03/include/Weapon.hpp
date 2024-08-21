/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:24:40 by dferjul           #+#    #+#             */
/*   Updated: 2024/08/13 23:24:40 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();
		void setType(const std::string &newType);
		const std::string &getType() const;
};

