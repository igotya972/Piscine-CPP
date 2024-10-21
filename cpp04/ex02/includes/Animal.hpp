/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferjul <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:49:14 by dferjul           #+#    #+#             */
/*   Updated: 2024/10/21 17:49:14 by dferjul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <sstream>

class Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		Animal(const Animal& copy);
		Animal(std::string const &type);
		Animal& operator=(const Animal& copy);
		virtual ~Animal();
		std::string getType() const;
		virtual void makeSound() const = 0;
};
